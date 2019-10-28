#include "stdafx.h"
#include "LatitudeLongitude.h"
#include <chrono>
#include <time.h>

LatitudeLongitude::LatitudeLongitude()
{
	//generate seed
	srand(time(NULL));
	//randomly chooses departing airport from array
	int departing = (rand() % 4);
	//latitude and langitude for that airport assigned
	currentLatitude = departingLatitudeAirports[departing];
	currentLongitude = departingLongitudeAirports[departing];
	//randomly chooses destination airport from array
	int destination = (rand() % 4);
	//latitude and langitude for that airport assigned
	destinationLatitude = destinationLatitudeAirports[destination];
	destinationLongitude = destinationLongitudeAirports[destination];
}

void LatitudeLongitude::updateLatitudeLongitude(double speed)
{
	//change values
	moveLatitude(speed);
	moveLongitude(speed);
}

float LatitudeLongitude::returnCurrentLatitude()
{
	return currentLatitude;
}

float LatitudeLongitude::returnCurrentLongitude()
{
	return currentLongitude;
}

float LatitudeLongitude::returnDestinationLatitude()
{
	return destinationLatitude;
}

float LatitudeLongitude::returnDestinationLongitude()
{
	return destinationLongitude;
}

void LatitudeLongitude::moveLatitude(double speed)
{
	if (currentLatitude != destinationLatitude)
	{
		//decrease latitude if needed
		if (currentLatitude > destinationLatitude)
		{
			currentLatitude = currentLatitude - (0.00035 * (speed * 0.67));
			if (currentLatitude < destinationLatitude)
			{
				currentLatitude = destinationLatitude;
			}
		}
		else
		{
			//increase latitude if needed
			currentLatitude = currentLatitude + (0.00035 * (speed * 0.67));
			if (currentLatitude > destinationLatitude)
			{
				currentLatitude = destinationLatitude;
			}
		}
	}
}

void LatitudeLongitude::moveLongitude(double speed)
{
	if (currentLongitude != destinationLongitude)
	{
		//decrease longitude if needed

		if (currentLongitude > destinationLongitude)
		{
			currentLongitude = currentLongitude - (0.00035 * (speed * 0.67));
			if (currentLongitude < destinationLongitude)
			{
				currentLongitude = destinationLongitude;
			}
		}
		else
		{
			//increase longitude if needed
			currentLongitude = currentLongitude + (0.00035 * (speed * 0.67));
			if (currentLongitude > destinationLongitude)
			{
				currentLongitude = destinationLongitude;
			}
		}
	}
}
