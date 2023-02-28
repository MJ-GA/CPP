#include "RentalLocation.h"

RentalLocation::RentalLocation(const int& id, const string& address)
{
    this->id = id;
    this->address = address;
}

RentalLocation::~RentalLocation()
{
}

int RentalLocation::getId()
{
    return id;
}
string RentalLocation::getAddress()
{
    return address;
}
