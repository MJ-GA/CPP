#include "Rental.h"

Rental::Rental(const int& id, Customer* cust, Vehicle* vehicle, int dayFrom, int dayTo)
{
    this->id = id;
    this->cust = cust;
    this->vehicle = vehicle;
    this->dayFrom = dayFrom;
    this->dayTo = dayTo;
    this->returned = false;
    this->dayReturn = -1;
}

Rental::~Rental()
{
}

int Rental::getId()
{
    return id;
}

Customer* Rental::getCustomer()
{
    return cust;
}

Vehicle* Rental::getVehicle()
{
    return vehicle;
}

RentalLocation* Rental::getRentalLocation()
{
    return vehicle->getRentalLocation();
}

void Rental::returnCar(int day)
{
    returned = true;
    dayReturn = day;
}
