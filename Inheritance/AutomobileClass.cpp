// File Name: AutomobileClass.cpp
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Contains the fuctions of the Automobile Class
// Last Changed: Nov 12, 2012

#include "AutomobileClass.h"
#include <iostream>//Needed for output
using namespace std;

Automobile::Automobile() : Vehicle()
{
	convertible = false;
	setEngineType("Automobile Engine");
}
Automobile::Automobile(string w, string s, double m, double f, bool c) : Vehicle(w, s, m, f)
{
	convertible = c;
	setEngineType("Automobile Engine");
}

void Automobile::setCon(bool newCon)
{
	convertible = newCon;
	return;
}
bool Automobile::getCon() const
{
	return convertible;
}

void Automobile::print() const
{
	Vehicle::print();
	if (convertible == true)
	{
		cout << "Is convertible\n";
	}
	else
	{
		cout << "Is not convertible\n";
	}
	return;
}
void Automobile::setEngineType(string newEngine)
{
	cout << "Setting automobile engine to " << newEngine << endl;
	engineType = newEngine;
	return;
}
