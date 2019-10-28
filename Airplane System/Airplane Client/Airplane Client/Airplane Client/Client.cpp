#include "StdAfx.h"
#include "Client.h"
#include <ctime>
#include "TimeMonitor.h"
#include <iostream>

Client::Client(TimeMonitor *t) : Observer(t)
{
	network = new ClientNetwork();
	// send init packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = INIT_CONNECTION;

	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}


Client::~Client(void)
{
}

void Client::sendActionPackets()
{
	// send action packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;

	//gathers data from each sensor and store it in the packet
	packet.speed = speed->returnSpeed();
	latLong->updateLatitudeLongitude(packet.speed);
	packet.latitude = latLong->returnCurrentLatitude();
	packet.longitude = latLong->returnCurrentLongitude();
	packet.destinationLatitude = latLong->returnDestinationLatitude();
	packet.destinationLongitude = latLong->returnDestinationLongitude();
	packet.temperature = temp->returnTemperature();
	packet.fuelRemaining = fuel->returnFuel();
	packet.flightNumber = flightNumber;
	packet.distanceRemaining = distance->distanceearth(packet.latitude, packet.longitude,
		packet.destinationLatitude, packet.destinationLongitude);
	packet.altitude = altitude->returnAltitude(packet.distanceRemaining);

	packet.packet_type = DATA_EVENT;
	//serialize the packet
	packet.serialize(packet_data);
	//send the message to the server
	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}

void Client::update()
{
	Packet packet;
	int i = 0;
	packet.deserialize(&(network_data[i]));
	switch (packet.packet_type) {

	default:
		Sleep(1000);
		//send
		sendActionPackets();
		//output
		cout << "The data has been sent to the server" << endl;
		//if destination reached, send the packet one last time and close the client
		if ((latLong->returnCurrentLatitude() == latLong->returnDestinationLatitude()) &&
			latLong->returnCurrentLongitude() == latLong->returnDestinationLongitude())
		{
			Sleep(1000);
			sendActionPackets();
			printf("Destination reached\n");
			exit(0);
		}
		break;
	}
}
