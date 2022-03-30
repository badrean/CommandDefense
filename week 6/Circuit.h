#pragma once
#include "Weather.h"
#include "Car.h"
#include <iostream>

class Circuit
{
	int lenght;
	int count; int max_count;
	Weather curr_weather;
	Car* cars[3];
public:
	Circuit()
	{
		count = 0;
		max_count = 3;
	}
	bool AddCar(Car* masina);
	void SetWeather(Weather conditie_meteo);
	void SetLength(int distanta);
	void Race();
	
	Weather GetWeather();
	int GetLenght();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
};

