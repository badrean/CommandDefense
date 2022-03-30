#pragma once
#include "Weather.h"
#include "Car.h"
#include <iostream>

class Circuit
{
	int lenght;
	int count = 0; int max_count = 3;
	Weather curr_weather;
	
public:
	Car* cars[3];
	bool AddCar(Car* masina);
	void SetWeather(Weather conditie_meteo);
	void SetLength(int distanta);
	void Race();
	
	Weather GetWeather();
	int GetLenght();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
};

