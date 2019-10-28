#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "ClientNetwork.h"
#include "NetworkData.h"
#include "Speed.h"
#include "Temperature.h"
#include "Fuel.h"
#include "Altitude.h"
#include "Observer.h"
#include "LatitudeLongitude.h"
#include "Distance.h"

//Client class follows Observer design pattern
class Client : public Observer
{
public:
	//constructor
	Client(TimeMonitor *t);
	~Client(void);
	//instance of ClientNetwork
	ClientNetwork* network;

	//declaring methods
	void sendActionPackets();
	char network_data[MAX_PACKET_SIZE];
	Speed* speed = new Speed();
	Temperature* temp = new Temperature();
	Fuel* fuel = new Fuel();
	Altitude* altitude = new Altitude();
	LatitudeLongitude* latLong = new LatitudeLongitude();
	Distance* distance = new Distance();
	int flightNumber = (rand() % 500);
	void update();
};

