#include "Circuit.h"

bool Circuit::AddCar(Car* masina)
{
	if (count < max_count)
	{
		cars[count++] = masina;
		return true;
	}
	return false;
}

void Circuit::SetWeather(Weather conditie_meteo)
{
	curr_weather = conditie_meteo;
}

void Circuit::SetLength(int distanta)
{
	lenght = distanta;
}

void Circuit::Race()
{
	int time = 0;
	for (int i = 0; i < max_count; i++)
	{
		cars[i]->avg_time = lenght / cars[i]->GetAverageSpeed();
	}
	
	int temp;
	for (int i = 0; i < max_count; i++)
		for (int j = 0; j < max_count - i - 1; j++)
			if (cars[top[j]]->GetAverageSpeed() < cars[top[j + 1]]->GetAverageSpeed())
			{
				temp = top[j];
				top[j] = top[j + 1];
				top[j + 1] = temp;
			}

}

Weather Circuit::GetWeather()
{
	return curr_weather;
}

int Circuit::GetLenght()
{
	return lenght;
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < max_count; i++)
	{
		printf("Car %s finished on place %d with time %f\n", cars[top[i]]->name, i+1, cars[top[i]]->avg_time);
	}
}

void Circuit::ShowWhoDidNotFinis()
{
	for (int i = 0; i < max_count; i++)
	{
		if (cars[i]->GetFuelCap() / cars[i]->GetFuelConsum() == 0) printf("Car: %s did not finish.", cars[i]->name);
	}
}


