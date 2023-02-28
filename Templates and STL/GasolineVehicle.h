#pragma once
#include"Vehicle.h"
template < class T>
class GasolineVehicle : public Vehicle<T> {
public:
    T currentGasoline;
    T maximumGasoline;
    T engineEfficiency;
    inline GasolineVehicle(T maxEnergy, T rating) {
        engineEfficiency = rating;
        maximumGasoline = maxEnergy;
        currentGasoline = maxEnergy;
    }
    inline ~GasolineVehicle() {
        cout << "In Gasoline vehicle destructor" << endl;
    }
    inline T calculateRange() {
        return currentGasoline * 100 / engineEfficiency;
    }
    inline T percentEnergyRemaining() {
        return (currentGasoline / maximumGasoline) * 100.0f;
    }
    inline void drive(T km) {
        if (currentGasoline < 0) {
            cout << "Your Car is out of energy";
            return;
        }
        currentGasoline -= (km / 100) * engineEfficiency;
    }
};