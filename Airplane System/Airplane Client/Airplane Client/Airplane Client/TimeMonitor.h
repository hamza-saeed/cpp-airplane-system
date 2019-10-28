#pragma once
#include "stdafx.h"
#include <vector>
using namespace std;

class TimeMonitor {
public:
	//constructor
	TimeMonitor();
	virtual ~TimeMonitor();
	//stores number of seconds passed
	int sec;
	//second counting method
	void secondCount();
	//used for observer design pattern
	void attach(class Observer *obs);
	void notify();
private:
	//used for observer
	vector <class Observer *> views;
};
