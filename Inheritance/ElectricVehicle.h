#pragma once
#include<iostream>
#include "Vehicle.h"

class ElectricVehicle :virtual public Vehicle {
  
    public:
        float currentCharge;
        float maximumCharge;
        ElectricVehicle(float maxCharge, float efficiency);
        virtual ~ElectricVehicle(); 
        float calculateRange();
        float percentEnergyRemaining();
        void drive(float km);
       
    };

