#include "CarRentalSystem.h"

CarRentalSystem::CarRentalSystem()
{
}

CarRentalSystem::~CarRentalSystem()
{
}

void CarRentalSystem::addCustomer(Customer* cust)
{
    customers.push_back(cust);
}

void CarRentalSystem::addVehicle(Vehicle* vehicle)
{
    vehicles.push_back(vehicle);
}

void CarRentalSystem::addRentalLocation(RentalLocation* rentLoc)
{
    rentalLocations.push_back(rentLoc);
}

void CarRentalSystem::addRental(Rental* rent)
{
    rentals.push_back(rent);
}

vector<Customer*>& CarRentalSystem::getCustomers()
{
    return customers;
}

vector<Vehicle*>& CarRentalSystem::getVehicles()
{
    return vehicles;
}

vector<RentalLocation*>& CarRentalSystem::getRentalLocations()
{
    return rentalLocations;
}

vector<Rental*>& CarRentalSystem::getRentals()
{
    return rentals;
}

RentalLocation* CarRentalSystem::findRentalLocation(int locId)
{
    for (int i = 0; i < rentalLocations.size(); i++)
    {
        RentalLocation* rl = rentalLocations[i];
        if (rl->getId() == locId)
        {
            return rl;
        }
    }
    return nullptr;
}

Vehicle* CarRentalSystem::findVehicle(int vId)
{
    for (int i = 0; i < vehicles.size(); i++)
    {
        Vehicle* v = vehicles[i];
        if (v->getId() == vId)
        {
            return v;
        }
    }
    return nullptr;
}

vector<Vehicle*> CarRentalSystem::getVehiclesAtLocation(int locId)
{
    vector<Vehicle*> result;
    for (int i = 0; i < vehicles.size(); i++) {
        RentalLocation* rl = vehicles[i]->getRentalLocation();
        if (rl->getId() == locId) {
            result.push_back(vehicles[i]);
        }
    }
    return result;
}

vector<Customer*> CarRentalSystem::getCustomersRenting()
{
    vector<Customer*> result;
    return result;
}
