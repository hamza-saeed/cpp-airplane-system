#pragma once
#include "Sensors.h"

class Temperature : public Sensors
{
public:
	double averageTemperature = 22;
	double temperature;
	void generate();
	double returnTemperature();
};