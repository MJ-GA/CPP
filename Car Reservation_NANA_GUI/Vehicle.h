#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "RentalLocation.h"

using namespace std;

// This class implements a vehicle in the car rental system
class Vehicle
{
public:
    // class constructor
    Vehicle(const int& id, const string& model, int seats, double rentalCost, RentalLocation* = nullptr);
    // class destructor
    virtual ~Vehicle();
    // Get the ID
    int getId();
    // Get the model
    string getModel();
    // Get the number of seats
    int getNumSeats();
    // Get the rental cost per day
    double getDailyRentalCost();
    // Get the rental location
    RentalLocation* getRentalLocation();

protected:

private:
    // car ID
    int id;
    // model of the car
    string model;
    // number of seats
    int seats;
    // cost of rent per day
    double rentalCost;
    // rental location
    RentalLocation* rentLoc;
};

#endif // VEHICLE_H
