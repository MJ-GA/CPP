#pragma once
#include <iostream>
using namespace std;



class Vehicle {

private:

    int numWheels, numDoors;

public:
    Vehicle();
    Vehicle(int w, int d);
    Vehicle(int w);

    // Copy Constructors
    Vehicle(Vehicle&);
    Vehicle(Vehicle*);

    void printVehicle();

    ~Vehicle();

    int getNumWheels() {

        return numWheels;
    }
    int getNumDoors() {

        return numDoors;
    }
    void setNumDoors(int numDoors) {

        this->numDoors < -numDoors;
    }
    void setNumWheels(int numWheels) {

        this->numWheels < -numWheels;
    
    }
    //Assignment operator declaration 
    Vehicle& operator= (const Vehicle& vehicle);

    //Comparison Operator overloading 

    //If Equals
    friend bool operator== (const Vehicle& vehicle, const Vehicle& vehicle2);

    //If Not Equals
    friend bool operator!= (const Vehicle& vehicle, const Vehicle& vehicle2);

    //Increment decrement operators overloading

    Vehicle& operator++();    //prefix increment header
    Vehicle& operator++(int); // postfix increment header

    Vehicle& operator--(); //prefix decrement header
    Vehicle& operator--(int);   //postfix decrement header

    //Friending ostream
    friend ostream& operator<<(ostream& COUT, Vehicle& vehicle);
   
};