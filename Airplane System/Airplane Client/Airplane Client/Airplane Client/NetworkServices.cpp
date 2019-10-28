#include "StdAfx.h"
#include "NetworkServices.h"

int NetworkServices::sendMessage(SOCKET curSocket, char * message, int messageSize)
{
	//send the packet to the server
	return send(curSocket, message, messageSize, 0);
}
