#include "Customer.h"

Customer::Customer(const int& cid, const int& age, const string& fn, const string& ln, const string& stAddr, const bool& pf)
{
    id = cid;
    firstName = fn;
    lastName = ln;
    streetAddress = stAddr;
    this->age = age;
    if (age > 25) {
        preferred = pf;
    }
    else {
        preferred = false;
    }
}

Customer::~Customer()
{
}

int Customer::getId()
{
    return id;
}
int Customer::getAge()
{
    return age;
}
string Customer::getFirstName()
{
    return firstName;
}
string Customer::getLastName()
{
    return lastName;
}
string Customer::getStreetAddress()
{
    return streetAddress;
}
bool Customer::isPreferred()
{
    return preferred;
}

