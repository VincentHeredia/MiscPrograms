// File Name: MotorcycleClass.h
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Header for the motorcycle class
// Last Changed: Nov 12, 2012

#include "VehicleClass.h"
#include <string>//Needed for string variables
using namespace std;

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	Motorcycle(string w, string s, double m, double f, string F);

	void setHandleBarType(string newHandleBarType);
	string getHandleBarType() const;

	void print() const;
	void setEngineType(string newHandleBarType);

private:
	string HandleBarType;

};