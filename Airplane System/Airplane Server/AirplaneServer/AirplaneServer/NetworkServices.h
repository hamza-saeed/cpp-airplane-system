#pragma once
#include <winsock2.h>
#include <Windows.h>

class NetworkServices
{
public:
	//receive packet from client
	static int receiveMessage(SOCKET curSocket, char * buffer, int bufSize);
};

