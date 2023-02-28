#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include <vector>
#include "Customer.h"
#include "Vehicle.h"
#include "RentalLocation.h"
#include "Rental.h"

using namespace std;

// This class implements the core functionality of the car rental system
// by keeping and managing list of customers, rental locations, vehicles and
// car rentals
class CarRentalSystem
{
public:
    // class constructor that creates empty list of entities
    CarRentalSystem();
    // class destructor
    virtual ~CarRentalSystem();
    // Add a customer
    void addCustomer(Customer* cust);
    // Add a car
    void addVehicle(Vehicle* vehicle);
    // Add a rental location
    void addRentalLocation(RentalLocation* rentLoc);
    // Add a rental
    void addRental(Rental* rent);

    // Find a car by id
    Vehicle* findVehicle(int vId);
    // find a rental location by id
    RentalLocation* findRentalLocation(int locId);
    // Get all customers
    vector<Customer*>& getCustomers();
    // Get all vehicles
    vector<Vehicle*>& getVehicles();
    // Get all rental locations
    vector<RentalLocation*>& getRentalLocations();
    // Get all rentals
    vector<Rental*>& getRentals();

    // Get all cars at given rental location id
    vector<Vehicle*> getVehiclesAtLocation(int locId);
    // Get all customers who are renting a car
    vector<Customer*> getCustomersRenting();
protected:

private:
    // list of customers
    vector<Customer*> customers;
    // list of vehicles
    vector<Vehicle*> vehicles;
    // list of rental locations
    vector<RentalLocation*> rentalLocations;
    // list of rentals
    vector<Rental*> rentals;
};

#endif // CARRENTALSYSTEM_H
