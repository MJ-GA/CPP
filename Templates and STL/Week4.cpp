
#include<iostream>
#include "ElectricVehicle.h"
#include "HybridVehicle.h"
#include "GasolineVehicle.h"
#include <vector>
using namespace std;

namespace Helper {
    template <typename T>
    T min(T a, T b) {
        if (a <= b) {
            return a;
        }
        return b;
    }

    template <typename T>
    T max(T a, T b) {
        if (a <= b) {
            return b;
        }
        return a;
    }
};

template < class T>
T testVehicle(T pvehicle, const char* vehicleName) {
    cout << vehicleName << " s range is: " << pvehicle->calculateRange() << endl;
    pvehicle->drive(150);
    cout << vehicleName << " s energy left is: " << pvehicle->percentEnergyRemaining() << endl;
    cout << vehicleName << " s range is now: " << pvehicle->calculateRange() << endl;

    return pvehicle;
};


void testTemplateLibrary() {
    vector<float> vec = { 5.0, 4.0, 3.0, 2.0, 1.0 };

    while (!vec.empty()) {
        cout << "Last Element : " << vec.back() << endl;
        vec.pop_back();
    }
};//End of step 5

int main()
{					//50L of gas, 7.1 L/100km
    delete  testVehicle(new GasolineVehicle<float>(50, 7.1), "Corolla");

    //42 L of gas, 4.3 L/100km, 8.8kWh, 22 kWh/100km
    delete testVehicle(new HybridVehicle<double>(42, 4.3, 8.8, 22.0), "Prius");

    //75 kWh, 16 kWh/100km
    delete testVehicle(new ElectricVehicle<int>(75, 16), "Tesla 3");

    cout << "min of 5 and 7 is:" << Helper::min(5, 7) << endl;
    cout << "max of 5 and 7 is:" << Helper::max(5, 7) << endl;

    cout << "min of A and B is:" << Helper::min('A', 'B') << endl;
    cout << "max of A and B is:" << Helper::max('A', 'B') << endl;

    cout << "min of string(Hello) and string(world) is:" << Helper::min(string("Hello"), string("World")) << endl;
    cout << "max of string(Hello) and string(world) is:" << Helper::max(string("Hello"), string("World")) << endl;
    testTemplateLibrary();
    return 0;
};

