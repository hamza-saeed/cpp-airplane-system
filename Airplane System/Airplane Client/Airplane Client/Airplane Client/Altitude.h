#pragma once
#include "Sensors.h"

class Altitude
{
public:
	//declaring and initialising variables
	double initialAltitude = 0;
	double averageAltitude = 39000;
	//starting point
	double altitude = initialAltitude;
	//methods
	void generate(double distance);
	double returnAltitude(double distance);
};