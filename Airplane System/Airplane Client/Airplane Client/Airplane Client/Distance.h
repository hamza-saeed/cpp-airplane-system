#pragma once
#include <cmath>
#include "LatitudeLongitude.h"
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

class Distance
{
public:
	//conversion methods
	double degreesToRadians(double degrees);
	double radiansToDegrees(double radians);
	//used for the Haversine equation
	double distanceearth(double currentLat, double currentLong, double destLat, double destLong);

};

