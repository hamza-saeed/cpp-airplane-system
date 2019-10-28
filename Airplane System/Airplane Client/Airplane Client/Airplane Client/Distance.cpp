#include "stdafx.h"
#include "Distance.h"

double Distance::degreesToRadians(double degrees)
{
	//returns converted value
	return (degrees * pi / 180);
}

double Distance::radiansToDegrees(double radians)
{
	//returns converted value
	return (radians * 180 / pi);
}

double Distance::distanceearth(double currentLat, double currentLong, double destLat, double destLong)
{
	//Haversine Formula 
	double currentLatR, currentLongR, destLatR, destLongR, u, v;
	currentLatR = degreesToRadians(currentLat);
	currentLongR = degreesToRadians(currentLong);
	destLatR = degreesToRadians(destLat);
	destLongR = degreesToRadians(destLong);
	u = sin((destLatR - currentLatR) / 2);
	v = sin((destLongR - currentLongR) / 2);
	//return and convert to miles
	return ((2.0 * earthRadiusKm * asin(sqrt(u * u + cos(currentLatR) * cos(destLatR) * v * v))) * 0.621371192);
}

