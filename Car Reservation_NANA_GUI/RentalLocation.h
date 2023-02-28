#ifndef RENTALLOCATION_H
#define RENTALLOCATION_H

#include <string>

using namespace std;

// This class implements a rental location in the car rental system
class RentalLocation
{
public:
    // Class construcor
    RentalLocation(const int& id, const string& address);
    // class destructor
    virtual ~RentalLocation();
    // Get the ID of location
    int getId();
    // Get the address of location
    string getAddress();
protected:

private:
    // ID of the location
    int id;
    // address of the location
    string address;
};

#endif // RENTALLOCATION_H
