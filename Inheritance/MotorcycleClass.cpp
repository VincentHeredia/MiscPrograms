// File Name: MotorcycleClass.cpp
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Contains the functions for the motorcycle class
// Last Changed: Nov 12, 2012

#include "MotorcycleClass.h"
#include <iostream>//Needed for output
using namespace std;

Motorcycle::Motorcycle() : Vehicle()
{
	HandleBarType = "Null";
	setEngineType("Motorcycle Engine");
}
Motorcycle::Motorcycle(string w, string s, double m, double f, string h) : Vehicle(w, s, m, f)
{
	HandleBarType = h;
	setEngineType("Motorcycle Engine");
}

void Motorcycle::setHandleBarType(string newHandleBarType)
{
	HandleBarType = newHandleBarType;
	return;
}
string Motorcycle::getHandleBarType() const
{
	return HandleBarType;
}

void Motorcycle::print() const
{
	Vehicle::print();
	cout << "Handle Bar Type: " << HandleBarType << endl;
	return;
}
void Motorcycle::setEngineType(string newEngine)
{
	cout << "Setting motor cycle engine to " << newEngine << endl;
	engineType = newEngine;
	return;
}