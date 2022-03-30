#pragma once
#include "Car.h"
#include "Weather.h"

class Mercedes : public Car
{
public:
	Mercedes(int fuel_cap, int fuel_consum, Weather condition);
	int GetFuelCap() const;
	int GetFuelConsum() const;
	int GetAverageSpeed() const;
};

