#include "stdafx.h"
#include "Temperature.h"
#include <chrono>



void Temperature::generate()
{
	//change temperature randomly but at a reasonable stable rate. 
	temperature = averageTemperature - ((rand() % 6) - 3);
}

double Temperature::returnTemperature()
{
	//generate and return
	generate();
	return temperature;
}
