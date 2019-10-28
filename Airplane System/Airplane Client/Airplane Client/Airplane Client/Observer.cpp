#include "stdafx.h"
#include "Observer.h"

Observer::Observer(TimeMonitor *t) {
	//attach the observer to the class
	time = t;
	time->attach(this);
}

Observer::~Observer() {
	// TODO Auto-generated destructor stub
}
