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
	int avg_time;
	const char* name;
	virtual int GetFuelCap() const = 0;
	virtual int GetFuelConsum() const = 0;
	virtual int GetAverageSpeed() const = 0;


};

