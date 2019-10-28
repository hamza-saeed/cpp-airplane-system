#include "Server.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace System::Threading;
using namespace System::Windows::Forms;

unsigned int Server::client_id;
bool messageReceived[100];
int secondsMessageNotReceived[100];

Server::Server(void)
{
	// id's to assign clients for table
	client_id = 0;
	// set up the server network to listen 
	network = new ServerNetwork();
}

Server::~Server(void)
{
}

int Server::update(System::Windows::Forms::RichTextBox^ txtV, System::Windows::Forms::ComboBox^ cb)
{
	// get new clients
	if (network->acceptNewClient(client_id))
	{
		cb->Items->Add(client_id);
		//increment client ID for the next client
		client_id++;
	}

	receiveFromClients(txtV);
	return client_id;
}

void Server::receiveFromClients(System::Windows::Forms::RichTextBox^ txtV)
{
	std::map<unsigned int, SOCKET>::iterator iter;
	// go through all clients using an iterator
	for (iter = network->sessions.begin(); iter != network->sessions.end(); iter++)
	{
		int data_length = network->receiveData(iter->first, network_data);
		if (data_length <= 0)
		{
			Server::msgReceived(txtV, iter->first);
			//no data recieved
			continue;
		}

		int i = 0;
		while (i < (unsigned int)data_length)
		{
			packet.deserialize(&(network_data[i]));
			i += sizeof(Packet);

			//switch based on packet type
			switch (packet.packet_type) {

			case INIT_CONNECTION:
				txtV->Text += "\nServer received init packet from client " + iter->first;
				break;

			case DATA_EVENT:
			{
				dataReceived = true;
				messageReceived[iter->first] = true;
				ofstream logFile;
				timeofSend = localtime(&time1);
				logFile.open("logFile.log", std::ios_base::app);
				logFile << asctime(timeofSend) << packet.flightNumber << ",  " << packet.speed << ",  " << roundf(packet.latitude * 100)/100 << "," << roundf(packet.longitude * 100) /100 << ", " << roundf(packet.destinationLatitude * 100)/100 << ", " <<
					roundf(packet.destinationLongitude * 100)/100 << ",  " << packet.altitude << ",  " << packet.temperature << ", " << packet.fuelRemaining << ", " << packet.distance << endl;
				logFile.close();
				txtV->Text += "\nServer received data from client " + iter->first;

				txtV->Text += "\n" + this->returnSize() + " bytes received\nFlight Number:" + this->returnFlightNumber() + "\n";
				txtV->Text += "Speed: " + this->returnSpeed() + " mph \nCurrent Latitude: " + this->returnCurrentLat() * 100 + " \nCurrent Longitude: " + this->returnCurrentLong() + " \nDestination Latitude: " + this->returnDestLat() + " \nDestination Longitude: " + this->returnDestLong() +
					"\nAltitude: " + this->returnAltitude() + " feet \nTemperature inside Airplane: " + this->returnTemperature() + " degrees celcius \nRemaining Fuel: " + this->returnFuelRemaining() + " litres \nDistance Remaining: " + this->returnDistance() + " miles\n __________________________________ \n";
				txtV->SelectionStart = txtV->Text->Length;
				txtV->ScrollToCaret();

				//adds last value received for each client to array
				lastAltitude[iter->first] = packet.altitude; lastLat[iter->first] = packet.latitude;
				lastLong[iter->first] = packet.longitude; lastDestLat[iter->first] = packet.destinationLatitude;
				lastDestLong[iter->first] = packet.destinationLongitude; lastRemainingFuel[iter->first] = packet.fuelRemaining;
				lastSpeed[iter->first] = packet.speed; lastTemp[iter->first] = packet.temperature;
				lastDistance[iter->first] = packet.distance; lastFlightNumber[iter->first] = packet.flightNumber;
				lastSize[iter->first] = sizeof(packet);
				break;
			}
			default:
				printf("Error in packet types\n");
				break;
			}
		}
	}
}


bool Server::msgReceived(System::Windows::Forms::RichTextBox^ txtV, int id)
{
	if (lastLat[id] != lastDestLat[id] &&
		lastLong[id] != lastDestLong[id])
	{
		if (messageReceived[id] == true)
		{
			secondsMessageNotReceived[id] = 0;
		}
		else
		{
			secondsMessageNotReceived[id] = secondsMessageNotReceived[id] + 1;

			if (secondsMessageNotReceived[id] < (60*5))
			{
				warningStatus[id] = 0;
			}
			//5 minutes
			else if (secondsMessageNotReceived[id] == (60 * 5))
			{
				//trigger warning alert
				txtV->Text += "\n__________________________________ \nWarning Alert for Client " + id + "\n__________________________________ \n";
				txtV->SelectionStart = txtV->Text->Length;
				txtV->ScrollToCaret();
				warningStatus[id] = 1;
			}
			//15 minutes
			else if (secondsMessageNotReceived[id] == (60 * 15))
			{
				//trigger severe alert
				txtV->Text += "\n__________________________________\nSevere Alert for Client " + id + "\n__________________________________ \n";
				txtV->SelectionStart = txtV->Text->Length;
				txtV->ScrollToCaret();
				warningStatus[id] = 2;
			}
			//25 minutes
			else if (secondsMessageNotReceived[id] == (60 * 25))
			{
				//trigger critical alert
				txtV->Text += "\n__________________________________\nCritical Alert for Client " + id + "\n__________________________________\n ";
				txtV->SelectionStart = txtV->Text->Length;
				txtV->ScrollToCaret();
				warningStatus[id] = 3;
			}
		}
	}
	messageReceived[id] = false;
	return true;
}

//return method for each variable in the packet
int Server::returnFlightNumber()
{
	return packet.flightNumber;
}
double Server::returnSpeed()
{
	return packet.speed;
}
float Server::returnCurrentLat()
{
	return packet.latitude;
}
float Server::returnCurrentLong()
{
	return packet.longitude;
}

float Server::returnDestLat()
{
	return packet.destinationLatitude;
}
float Server::returnDestLong()
{
	return packet.destinationLongitude;
}
double Server::returnAltitude()
{
	return packet.altitude;
}
double Server::returnTemperature()
{
	return packet.temperature;
}
double Server::returnFuelRemaining()
{
	return packet.fuelRemaining;
}
double Server::returnDistance()
{
	return packet.distance;
}

std::string Server::returnTime()
{
	return asctime(timeofSend);
}

int Server::returnSize()
{
	return sizeof(packet);
}

boolean Server::returnDataReceived()
{
	return dataReceived;
}

int Server::returnWarningStatus(int id)
{
	return warningStatus[id];
}

