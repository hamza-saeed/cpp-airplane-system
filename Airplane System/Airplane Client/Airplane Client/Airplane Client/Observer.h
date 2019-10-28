#pragma once
#include "TimeMonitor.h"
class Observer {
	//observer class
public:
	Observer(TimeMonitor *t);
	virtual ~Observer();
	//pure virtual function
	virtual void update() = 0;
	TimeMonitor *time;
};