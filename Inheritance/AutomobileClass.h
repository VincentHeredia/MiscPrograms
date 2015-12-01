// File Name: AutomobileClass.h
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Header for the Automobile Class
// Last Changed: Nov 12, 2012

#include "VehicleClass.h"
#include <string>//Needed for string variables
using namespace std;

class Automobile : public Vehicle
{
public:
	Automobile();
	Automobile(string w, string s, double m, double f, bool c);

	void setCon(bool newCon);//Sets the convertible variable, true = is convertible, false = not a convertible
	bool getCon() const;//Gets the convertible variable, true = is convertible, false = not a convertible

	void print() const;
	void setEngineType(string newEngine);

private:
	bool convertible;//If the car has a retractable roof or not

};