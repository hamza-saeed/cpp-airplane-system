#pragma once
#include <string.h>

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {
	INIT_CONNECTION = 0,
	DATA_EVENT = 1,
};


struct Packet {

	//data to be contained in packet
	unsigned int packet_type;
	int flightNumber;
	double speed;
	float longitude;
	float latitude;
	float destinationLatitude;
	float destinationLongitude;
	double altitude;
	double temperature;
	double fuelRemaining;
	double distanceRemaining;


	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};