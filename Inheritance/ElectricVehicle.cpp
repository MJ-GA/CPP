#include<iostream>
#include "ElectricVehicle.h"
#include "Vehicle.h"
using namespace std;
ElectricVehicle::ElectricVehicle(float maxCharge, float efficiency) {

    engineEfficiency = efficiency;
    maximumCharge = maxCharge;
    currentCharge = maxCharge;
}

ElectricVehicle:: ~ElectricVehicle() {
    cout << "In Electric vehicle destructor" << endl;
}

float ElectricVehicle::calculateRange() {
    return currentCharge * 100 / engineEfficiency;
}
float ElectricVehicle::percentEnergyRemaining() {
    return (currentCharge * 100.0f / maximumCharge);
}
void ElectricVehicle::drive(float km) {
    if (currentCharge < 0) {
        cout << "Your Car is out of energy";
        return;
    }
    currentCharge -= (km / 100) * engineEfficiency;
}