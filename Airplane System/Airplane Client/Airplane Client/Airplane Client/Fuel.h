#pragma once
#include "Sensors.h"

class Fuel : public Sensors
{
public:
	//fuel capacity for Boeing
	double fuel = 177000;
	//methods
	void generate();
	double returnFuel();
};