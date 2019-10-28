#include "stdafx.h"
#include "Client.h"
#include <WinBase.h>
#include "TimeMonitor.h"

Client * client;

int main()
{
	printf("Client has been started \n");
	//instance of client
	TimeMonitor *t = new TimeMonitor();
	client = new Client(t);
	//calls timing method
	t->secondCount();
}