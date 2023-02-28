#pragma once
#include<iostream>
#include "Vehicle.h"
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"

class HybridVehicle :public ElectricVehicle, public GasolineVehicle {

public:


	HybridVehicle(float maxGasoline, float gasefficiency, float maxcharge, float electricefficiency) :GasolineVehicle(maxGasoline, gasefficiency), ElectricVehicle(maxcharge, electricefficiency) {}
   
	~HybridVehicle();
   float calculateRange();
   float percentEnergyRemaining();
   void drive(float km);

};