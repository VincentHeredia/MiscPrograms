// File Name: TruckClass.h
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Header for the Truck class
// Last Changed: Nov 12, 2012

#include "VehicleClass.h"
#include <string>//Needed for string variables
using namespace std;

class Truck : public Vehicle
{
public:
	Truck();
	Truck(string w, string s, double m, double f, double b);

	void setBedSize(double newBedSize);
	double getBedSize() const;

	void print() const;
	void setEngineType(string newEngine);

private:
	double bedSize;//Size of the back of the truck

};