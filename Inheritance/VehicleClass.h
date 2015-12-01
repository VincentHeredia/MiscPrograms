// File Name: CehicleClass.h
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Header for the the vehicle class, this is used as a base for other classes
// Last Changed: Nov 12, 2012

#ifndef VehicleClass_H
#define VehicleClass_H

#include <string>//Needed for string characters
using namespace std;

class Vehicle
{
public:
	Vehicle();
	Vehicle(string w, string s, double m, double f);
	
	void setMaxSpeed(double newSpeed);
	void setFuelCap(double newFuelCap);
	double getMaxSpeed();
	double getFuelCap();

	virtual void print() const;
	virtual void setEngineType(string) = 0;

protected:
	string wheels;
	string engineType;
	string seats;

private:
	double maximumSpeed;
	double fuelTankCap;//fuel tank capacity

};


#endif