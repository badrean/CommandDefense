#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Weather.h"
#include <string.h>

class Car
{
protected:
	int fuel_capacity, fuel_consumption_km;
	int average_speed;
	
public:
	float avg_time;
	const char* name;
	virtual int GetFuelCap() const = 0;
	virtual int GetFuelConsum() const = 0;
	virtual float GetAverageSpeed() const = 0;


};

