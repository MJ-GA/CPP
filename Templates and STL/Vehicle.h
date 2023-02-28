#pragma once

using namespace std;
template <class T>
class Vehicle {
public:
    inline T calculateRange();
    inline T percentEnergyRemaining();
    inline void drive(T);
    ~Vehicle() {
        cout << "In vehicle destructor" << endl;
    }
  
  
};




