#pragma once
#include "Car.h"
#include "Weather.h"

class Toyota : public Car
{
public:
	Toyota(int fuel_cap, int fuel_consum, Weather condition);
	int GetFuelCap() const;
	int GetFuelConsum() const;
	float GetAverageSpeed() const;
};

