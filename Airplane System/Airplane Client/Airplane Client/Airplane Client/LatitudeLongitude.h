#pragma once
class LatitudeLongitude
{
public:
	LatitudeLongitude();
	void updateLatitudeLongitude(double speed);
	//Heathrow, Gatwick, Manchester, Luton airport latitude longitude
	float departingLatitudeAirports[4] = { 51.4700f,51.1537f,53.3588f,51.8763f };
	float departingLongitudeAirports[4] = { -0.4543f,0.1821f,2.2727f,0.3717f };
	/*Charles de Gaulle, Milan-Malpensa Airport, Malaga Airport
	Munich airport latitude and longitude*/
	float destinationLatitudeAirports[4] = { 49.0097f, 45.6301f,36.6744f,48.3537f };
	float destinationLongitudeAirports[4] = { 2.5479f,8.7255f,4.4913f,11.7750f };
	float currentLatitude, currentLongitude, destinationLatitude, destinationLongitude;
	//return methods
	float returnCurrentLatitude();
	float returnCurrentLongitude();
	float returnDestinationLatitude();
	float returnDestinationLongitude();
	//moves along to destination. Uses speed to determine how fast
	void moveLongitude(double speed);
	void moveLatitude(double speed);
};

