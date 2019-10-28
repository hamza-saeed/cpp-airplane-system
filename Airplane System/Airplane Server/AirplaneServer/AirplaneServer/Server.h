#pragma once
#include "ServerNetwork.h"
#include <ctime>
#include "NetworkData.h"
class Server
{

public:
	//constructor
	Server(void);
	~Server(void);
	//methods and variablesfrom Server.C++
	int update(System::Windows::Forms::RichTextBox^ txtV, System::Windows::Forms::ComboBox ^ cb);
	void receiveFromClients(System::Windows::Forms::RichTextBox^ txtV);
	bool msgReceived(System::Windows::Forms::RichTextBox^ txtV, int id);
	//methods to return data in packet
	int returnFlightNumber(); double returnSpeed(); float returnCurrentLat();
	float returnCurrentLong(); float returnDestLat(); float returnDestLong();
	double returnAltitude(); double returnTemperature(); double returnFuelRemaining();
	double returnDistance(); std::string returnTime(); int returnSize(); boolean returnDataReceived(); 
	//warning status used for alarms 
	int returnWarningStatus(int id);
	Packet packet;
	//time
	time_t time1 = time(0);
	struct tm* timeofSend;
	boolean dataReceived = false;
	//arrays for last stored values
	//100 = max clients (this can be 
	//changed to allow for more clients)
	double lastAltitude[100]; float lastLat[100]; float lastLong[100]; float lastDestLat[100];
	float lastDestLong[100]; double lastRemainingFuel[100]; double lastSpeed[100]; double lastTemp[100];
	double lastDistance[100]; int lastSize[100]; int lastFlightNumber[100]; int warningStatus[100];

private:
	// IDs for the clients connecting for table in ServerNetwork 
	static unsigned int client_id;
	// The ServerNetwork object 
	ServerNetwork* network;
	// data buffer
	char network_data[MAX_PACKET_SIZE];
};
