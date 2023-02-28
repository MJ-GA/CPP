#include "Vehicle.h"

Vehicle::Vehicle(const int& id, const string& model, int seats, double rentalCost, RentalLocation* rentLoc)
{
    this->id = id;
    this->model = model;
    this->rentLoc = rentLoc;
    this->seats = seats;
    this->rentalCost = rentalCost;
}

Vehicle::~Vehicle()
{
}
int Vehicle::getId()
{
    return id;
}
string Vehicle::getModel()
{
    return model;
}
RentalLocation* Vehicle::getRentalLocation()
{
    return rentLoc;
}

int Vehicle::getNumSeats()
{
    return seats;
}

double Vehicle::getDailyRentalCost()
{
    return rentalCost;
}

