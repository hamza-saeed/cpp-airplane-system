#include "stdafx.h"
#include "Fuel.h"
#include <chrono>

void Fuel::generate()
{
	/*every second, a Boeing uses 4 litres of
	fuel. As this will be called every 45 seconds
	(4 * 45) = 180. This randomly generates a number
	within 10% (plus or minus) of 180. The bounds are 162-198
	*/
	fuel = fuel - 180 + (rand() % 36) - 18;
}

double Fuel::returnFuel()
{
	generate();
	return fuel;
}
