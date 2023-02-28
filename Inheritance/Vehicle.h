#pragma once
class Vehicle {
	int numWheels;
	int numDoors;
public:

	float engineEfficiency;
	virtual float calculateRange() = 0;
	virtual float percentEnergyRemaining() = 0;
	virtual void drive(float) = 0;

	Vehicle();
	Vehicle(int w);
	Vehicle(int w, int d);

	Vehicle(Vehicle& v);
	Vehicle(Vehicle* v);

	void printVehicle();
	virtual ~Vehicle(); //Destructor

	Vehicle& operator ++();

	Vehicle& operator --();

	bool operator == (const Vehicle& v);

	bool operator != (const Vehicle& v);

	Vehicle& operator = (const Vehicle& v);

	friend std::ostream& operator << (std::ostream& out, const Vehicle& v);

};

