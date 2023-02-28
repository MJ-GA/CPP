#pragma once
#include "ElectricVehicle.h"
#include "GasolineVehicle.h"
template < class T>
class HybridVehicle :public ElectricVehicle<T>, public GasolineVehicle<T> {
public:
    inline HybridVehicle(T maxGasoline, T gasefficiency, T maxcharge, T electricefficiency) :GasolineVehicle<T>(maxGasoline, gasefficiency), ElectricVehicle<T>(maxcharge, electricefficiency) {}
    inline ~HybridVehicle() {
        cout << "In Hybrid vehicle destructor" << endl;
    }
 
    inline T calculateRange() {
        return (ElectricVehicle<T>::currentCharge / ElectricVehicle<T>::engineEfficiency) * 100 + (GasolineVehicle<T>::currentGasoline / GasolineVehicle<T>::engineEfficiency) * 100;
    }
    inline T percentEnergyRemaining() {
        return ((ElectricVehicle<T>::currentCharge + GasolineVehicle<T>::currentGasoline) / (ElectricVehicle<T>::maximumCharge + GasolineVehicle<T>::maximumGasoline)) * 100.0f;
    }
    inline void drive(T km) {
        if (GasolineVehicle<T>::currentGasoline + ElectricVehicle<T>::currentCharge < 0) {
            cout << "Your Car is out of energy";
            return;
        }
        else if (ElectricVehicle<T>::currentCharge > 0) {
            ElectricVehicle<T>::currentCharge -= (km / 100) * ElectricVehicle<T>::engineEfficiency;
        }
        else
        {
            GasolineVehicle<T>::currentGasoline -= (km / 100) * GasolineVehicle<T>::engineEfficiency;
        }
    }
};