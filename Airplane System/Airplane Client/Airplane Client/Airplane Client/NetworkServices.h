#pragma once
#include <winsock2.h>
#include <Windows.h>

class NetworkServices
{
public:
	//sends packet to the server
	static int sendMessage(SOCKET curSocket, char * message, int messageSize);
};

