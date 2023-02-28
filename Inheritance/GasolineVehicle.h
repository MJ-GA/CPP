#pragma once
#include<iostream>
#include "Vehicle.h"

class GasolineVehicle :virtual public Vehicle {
public:
    float currentGasoline;
    float maximumGasoline;

    GasolineVehicle(float maxGas, float efficiency);

    virtual ~GasolineVehicle();

    float calculateRange();
    float percentEnergyRemaining();
    void drive(float km);

};