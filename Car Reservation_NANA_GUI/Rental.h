#ifndef RENTAL_H
#define RENTAL_H

#include "Customer.h"
#include "Vehicle.h"
#include "RentalLocation.h"

// This class implements a car rental in the car rental system
class Rental
{
public:
    // Class constructor
    Rental(const int& id, Customer* cust, Vehicle* vehicle, int dayFrom, int dayTo);
    // class destructor
    virtual ~Rental();
    // Get the ID
    int getId();
    // Get the customer
    Customer* getCustomer();
    // Get the vehicle
    Vehicle* getVehicle();
    // Get the rental location
    RentalLocation* getRentalLocation();
    // Return the car on given day
    void returnCar(int day);

private:
    // ID of the rental
    int id;
    // customer of rental
    Customer* cust;
    // vehicle assigned
    Vehicle* vehicle;
    // start day of rent
    int dayFrom;
    // end day of rent
    int dayTo;
    // car returned or not
    bool returned;
    // day car was returned
    int dayReturn;
};

#endif // RENTAL_H
