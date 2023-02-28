#pragma once

#include"Vehicle.h"
template < class T>
class ElectricVehicle : public Vehicle<T> {
public:
    T currentCharge;
    T maximumCharge;
    T engineEfficiency;
    inline ElectricVehicle(T maxEnergy, T rating) {
        engineEfficiency = rating;
        maximumCharge = maxEnergy;
        currentCharge = maxEnergy;
    }
    inline ~ElectricVehicle() {
        cout << "In Electric vehicle destructor" << endl;
    }

    inline T calculateRange() {
        return currentCharge * 100 / engineEfficiency;
    }
    inline T percentEnergyRemaining() {
        return (currentCharge / maximumCharge) * 100.0f;
    }
    inline void drive(T km) {
        if (currentCharge < 0) {
            cout << "Your Car is out of energy";
            return;
        }
        currentCharge -= (km / 100) * engineEfficiency;
    }
};
