// File Name: main.cpp
// Author: Vincent Heredia
// Class:  CSCI 222
// Project Number: 1.0
// Description: Runs test on the classes
// Last Changed: Nov 12, 2012

#include "AutomobileClass.h"
#include "MotorcycleClass.h"
#include "TruckClass.h"
#include <iostream>//Used for output
using namespace std;

int main()
{
	Vehicle* Automobile1Ptr = new Automobile("Round", "Leather", 150, 300, true);//Declaring the Vehicle Pointers
	Vehicle* Automobile2Ptr = new Automobile("Triangle", "Fabric", 140, 290, false);
	Vehicle* Truck1Ptr = new Truck("Round", "Fabric", 120, 400, 50);
	Vehicle* Truck2Ptr = new Truck("Square", "Leather", 90, 500, 70);
	Vehicle* Motorcycle1Ptr = new Motorcycle("Triangle", "Fabric", 190, 200, "Monkey Bars");
	Vehicle* Motorcycle2Ptr = new Motorcycle("Square", "Leather", 290, 210, "Standard Bars");
	
	Vehicle* vehicleArray[6];

	vehicleArray[0] = Motorcycle1Ptr;//Loading the object pointers into an array
	vehicleArray[1] = Motorcycle2Ptr;
	vehicleArray[2] = Automobile1Ptr;
	vehicleArray[3] = Automobile2Ptr;
	vehicleArray[4] = Truck1Ptr;
	vehicleArray[5] = Truck2Ptr;

	cout << endl;
	vehicleArray[0]->setEngineType("New Motorcycle Engine");//Calls the motorcycle version of setEngineType()
	cout << endl;
	vehicleArray[1]->setEngineType("New Motorcycle Engine");//Calls the motorcycle version of setEngineType()
	cout << endl;
	vehicleArray[2]->setEngineType("New Automobile Engine");//Calls the Automobile version of setEngineType()
	cout << endl;
	vehicleArray[3]->setEngineType("New Automobile Engine");//Calls the Automobile version of setEngineType()
	cout << endl;
	vehicleArray[4]->setEngineType("New Truck Engine");//Calls the Truck version of setEngineType()
	cout << endl;
	vehicleArray[5]->setEngineType("New Truck Engine");//Calls the Truck version of setEngineType()
	cout << endl;

	return 0;
}