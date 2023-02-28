#pragma once
#include<iostream>
#include "HybridVehicle.h"


using namespace std;


    HybridVehicle:: ~HybridVehicle() {
        cout << "In Hybrid vehicle destructor" << endl;
    }
    float HybridVehicle :: calculateRange() {
        return (currentCharge * 100 / ElectricVehicle::engineEfficiency) + (currentGasoline * 100 / GasolineVehicle::engineEfficiency);
    }
    float HybridVehicle :: percentEnergyRemaining() {
        return (ElectricVehicle::percentEnergyRemaining() + GasolineVehicle::percentEnergyRemaining()) / 2;
    }
    void HybridVehicle::drive(float km) {
        if (currentGasoline + currentCharge < 0) {
            cout << "Your Car is out of energy";
            return;
        }
        else if (currentCharge >= 0) {
            float rangeNow = ElectricVehicle::calculateRange();
            currentCharge = 0; //driving that range on electric
            GasolineVehicle::drive(km - rangeNow);//how much left to drive on gas
        }
       // else
        {
            currentGasoline -= (km / 100) * GasolineVehicle::engineEfficiency;
        }//
   };
