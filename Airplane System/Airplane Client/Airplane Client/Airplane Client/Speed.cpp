#include "stdafx.h"
#include "Speed.h"
#include <chrono>

//double speed;


void Speed::generate()
{
	//random speed close to average
	speed = averageSpeed + ((rand() % 150) - 80);
}

double Speed::returnSpeed()
{
	//generate and return
	generate();
	return speed;
}
