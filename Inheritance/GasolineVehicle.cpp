#pragma once
#include<iostream>
#include "GasolineVehicle.h"
using namespace std;



   GasolineVehicle:: GasolineVehicle(float maxGas, float efficiency) {
        engineEfficiency = efficiency;
        maximumGasoline = maxGas;
        currentGasoline = maxGas;
    }

    GasolineVehicle::~GasolineVehicle() {
        cout << "In Gasoline vehicle destructor" << endl;
    }

    float  GasolineVehicle:: calculateRange() {
        return currentGasoline * 100 / engineEfficiency;
    }
    float  GasolineVehicle::percentEnergyRemaining() {
        return (currentGasoline * 100.0f / maximumGasoline);
    }
    void  GasolineVehicle::drive(float km) {
        if (currentGasoline < 0) {
            cout << "Your Car is out of energy";
            return;
        }
        currentGasoline -= (km / 100) * engineEfficiency;
    };