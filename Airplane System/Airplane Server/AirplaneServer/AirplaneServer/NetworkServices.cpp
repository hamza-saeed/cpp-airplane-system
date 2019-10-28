#include "NetworkServices.h"


int NetworkServices::receiveMessage(SOCKET curSocket, char * buffer, int bufSize)
{
	//receive packet from client
	return recv(curSocket, buffer, bufSize, 0);
}