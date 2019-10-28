#include "stdafx.h"
#include "TimeMonitor.h"
#include "Observer.h"
#include <iostream>
#include <iomanip> 
#include <Windows.h>

using namespace std;

TimeMonitor::TimeMonitor() {
}

TimeMonitor::~TimeMonitor() {
}

void TimeMonitor::secondCount()
{
	while (true) {
		//counts number of seconds. Notify when ready
		sec++;
		Sleep(1000);
		//45 seconds
		if (sec == 45)
		{
			notify();
			sec = 0;
		}
	}
}

//attach observer
void TimeMonitor::attach(Observer *obs)
{
	//attach observer
	views.push_back(obs);
}

//notify Observer class
void TimeMonitor::notify()
{
	//update each concrete observer
	for (int i = 0; i < views.size(); i++)
	{
		views[i]->update();
	}
}
