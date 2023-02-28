#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;
// This class defines a customer in the car rental system
class Customer
{
public:
    // Class constructor
    Customer(const int& cid, const int& age, const string& fn, const string& ln, const string& stAddr, const bool& preferred = false);
    // Class destryctor
    virtual ~Customer();
    // Getter methods
    int getId();
    string getFirstName();
    string getLastName();
    string getStreetAddress();
    int getAge();
    bool isPreferred();
protected:

private:
    // id of the customer
    int id;
    // first name
    string firstName;
    // last name
    string lastName;
    // street address
    string streetAddress;
    // age
    int age;
    // whether preferred customer
    bool preferred;
};

#endif // CUSTOMER_H
