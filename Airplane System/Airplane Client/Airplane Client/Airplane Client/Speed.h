#pragma once
#include "Sensors.h"

class Speed : public Sensors
{
public:
	//avg speed for airplane
	double averageSpeed = 567;
	double speed;
	//methods
	void generate();
	double returnSpeed();
};