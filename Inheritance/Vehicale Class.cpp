// File Name: Vehicale Class.cpp
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Contains funtions of the Vehicle class, this class is used as a base for other classes
// Last Changed: Nov 12, 2012

#include "VehicleClass.h"
#include <iostream>//For Output
using namespace std;


Vehicle::Vehicle()
{
	wheels = "Null";
	engineType = "Null";
	seats = "Null";
	maximumSpeed = 0.0;
	fuelTankCap = 0.0;//fuel tank capacity
}

Vehicle::Vehicle(string w, string s, double m, double f)
{
	wheels = w;
	engineType = "null";
	seats = s;
	maximumSpeed = m;
	fuelTankCap = f;//fuel tank capacity
}

void Vehicle::setMaxSpeed(double newSpeed)
{
	maximumSpeed = newSpeed;
	print();
	return;
}
void Vehicle::setFuelCap(double newFuelCap)
{
	fuelTankCap = newFuelCap;
	print();
	return;
}
double Vehicle::getMaxSpeed()
{
	return maximumSpeed;
}
double Vehicle::getFuelCap()
{
	return fuelTankCap;
}

void Vehicle::print() const
{
	cout << "Wheels: " << wheels << endl
		 << "Engine Type: " << engineType << endl
		 << "Seats: " << seats << endl
		 << "Maximum Speed: " << maximumSpeed << endl
		 << "Fuel Tank Capacity: " << fuelTankCap << endl;

	return;
}
