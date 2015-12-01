// File Name: TruckClass.cpp
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Contains the functions for the Truck class
// Last Changed: Nov 12, 2012

#include "TruckClass.h"
#include <iostream>//Needed for output
using namespace std;



Truck::Truck() : Vehicle()
{
	bedSize = 0.0;
	setEngineType("Truck Engine");
}
Truck::Truck(string w, string s, double m, double f, double b) : Vehicle(w, s, m, f)
{
	bedSize = b;
	setEngineType("Truck Engine");
}

void Truck::setBedSize(double newBedSize)
{
	bedSize = newBedSize;
	return;
}
double Truck::getBedSize() const
{
	return bedSize;
}

void Truck::print() const
{
	Vehicle::print();
	cout << "Bed Size: " << bedSize << endl;
	return;
}
void Truck::setEngineType(string newEngine)
{
	cout << "Setting truck engine to " << newEngine << endl;
	engineType = newEngine;
	return;
}