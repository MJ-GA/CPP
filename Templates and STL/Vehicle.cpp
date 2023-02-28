#include <iostream>
#include "Vehicle.h"
using namespace std;


Vehicle::Vehicle() {  
	cout << "In constructor with 0 Parameters" << endl;
}

Vehicle::Vehicle(int w) : Vehicle(4, w) {
	cout << "In constructor with 1 Parameters,wheels" << w << endl;
}
Vehicle::Vehicle(int w, int d) {
	numWheels = w;
	numDoors = d;
	cout << "In constructor with 2 Parameters" << endl;
}
Vehicle::Vehicle(Vehicle& v) :Vehicle(v.numWheels, v.numDoors) {
	cout << "In copy constructor by reference" << endl;
}
Vehicle::Vehicle(Vehicle* v) : Vehicle(v->numWheels, v->numDoors) {
	cout << "In copy constructor by pointer" << endl;

}

Vehicle::~Vehicle() {  
	cout << "In vehicle destructor" << endl;
}
Vehicle& Vehicle::operator =(const Vehicle& v)
{
	numDoors = v.numDoors;
	numWheels = v.numWheels;
	return *this;
}

bool Vehicle::operator ==(const Vehicle& v)
{
	return numDoors == v.numDoors && numWheels == v.numWheels;
}

bool Vehicle::operator !=(const Vehicle& v)
{
	return !(*this == v);
}


ostream& operator <<(ostream& out, const Vehicle& v)
{
	out << "Vehicle ";
	out << "Wheels: " << v.numWheels << ", ";
	out << "Doors: " << v.numDoors << ")";
	return out;
}