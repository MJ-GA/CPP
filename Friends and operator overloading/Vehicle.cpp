// Vehicle.cpp
#include "Vehicle.h"


//No class declaration because of redefinition error
Vehicle::Vehicle() :Vehicle(0, 0) {}

//print vehicle function
void Vehicle::printVehicle() {

    cout << "Number of wheels: " << numWheels << endl
        << "Number of doors: " << numDoors << endl;
}

Vehicle::Vehicle(int w, int d) {
    numWheels = w;
    numDoors = d;
    cout << "In constructor with 2 parameters" << endl;
}

Vehicle::Vehicle(int w) :Vehicle(w, 1) {}

// Implementing copy constructors

Vehicle::Vehicle(Vehicle& copy) : Vehicle(copy.numWheels, copy.numDoors) {
    cout << "In copy constructor by reference" << endl;
}

Vehicle::Vehicle(Vehicle* copy) {

    this->numWheels = copy->numWheels;
    this->numDoors = copy->numDoors;
    cout << "In copy constructor by pointer" << endl;
}

Vehicle::~Vehicle() {}


void CreateVehicle(Vehicle& v, int w = 4, int d = 2) {

    v = Vehicle(w, d);
}

//Assignment operator overloading

Vehicle& Vehicle::operator= (const Vehicle& vehicle)
{
    // Assigning new values to existing variables
    numWheels = vehicle.numWheels;
    numDoors = vehicle.numDoors;

   //return the existing object so we can chain this operator
    return *this;
}

//**** Equality operator overloading ****

//If equals
 bool operator== (const Vehicle& vehicle, const Vehicle& vehicle2) {

     return (vehicle.numWheels == vehicle2.numWheels &&
         vehicle.numDoors == vehicle2.numDoors);
}

 //If not equals
 bool operator!= (const Vehicle& vehicle, const Vehicle& vehicle2) {

     return !(vehicle.numWheels == vehicle2.numWheels &&
         vehicle.numDoors == vehicle2.numDoors);
 }
//****Increment operator ovelroading****

 //Prefix increment 
 Vehicle& Vehicle:: operator++(){ 
     ++this->numDoors;
     ++this->numWheels;
     return *this;
 }

 //Postfix increment 
 Vehicle& Vehicle:: operator++(int) {
     return *this;
     ++this->numDoors;
     ++this->numWheels;
    
 }

//*****Decrement operator overloading****

 //Prefix
 Vehicle& Vehicle:: operator--() {

     Vehicle& v = *this;
     if (this->numDoors > 0)
        --this->numDoors;
     if (this->numWheels > 0 )
     --this->numWheels;
     return v;
 }

 //Postfix
 Vehicle& Vehicle:: operator--(int) {
     Vehicle& v = *this;
     if (this->numDoors > 0)
         --this->numDoors;
     if (this->numWheels > 0)
         --this->numWheels;

     return v;
 }

//Ostream operator << overloading
 ostream& operator<<(ostream& COUT, Vehicle& vehicle) {
    COUT << "\nNumber of wheels: " << vehicle.numWheels << endl;
    COUT << "Number of doors : " << vehicle.numDoors << endl;

    return COUT;
}

