#include "stdafx.h"
#include "Altitude.h"
#include <chrono>

void Altitude::generate(double distance)
{
	/*generates a realistic value for altitude*
	This starts the amplitude low but increases it
	until it reaches the average (roughly). When the 
	plane has almost reached its destination, the amplitude
	begins to decrease.
	*/

	if ((distance > 250))
	{
		if (altitude > (averageAltitude * 0.9) && altitude < (averageAltitude * 1.2))
		{
			altitude = altitude - ((rand() % 302) - 165);
		}
		else if (altitude > (averageAltitude * 1.2))
		{
			averageAltitude = (averageAltitude * 0.9) - ((rand() % 203) - 135);
		}
		else if (altitude == 0)
		{
			altitude += 4000 - ((rand() % 303) - 167);
		}
		else if (altitude < (averageAltitude *  0.3))
		{
			altitude = (altitude * 1.9) - ((rand() % 203) - 135);
		}
		else
		{
			altitude = altitude * 1.3;
		}
	}
	else
	{
		if (altitude == 0)
		{
			altitude += 3000 - ((rand() % 303) - 167);
		}
		else
		{
			altitude = altitude * 0.8;
		}
	}
	if (distance < 10)
	{
		altitude = 0;
	}
}

double Altitude::returnAltitude(double distance)
{
	generate(distance);
	return altitude;
}
