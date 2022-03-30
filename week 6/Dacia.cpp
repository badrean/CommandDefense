#include "Dacia.h"

Dacia::Dacia(int fuel_cap, int fuel_consum, Weather condition)
{
    name = new char[6];
    strcpy((char*)name, "Dacia");
    fuel_capacity = fuel_cap;
    fuel_consumption_km = fuel_consum;
    
    if (condition == Weather::Rain)
    {
        average_speed = 80;
    }
    if (condition == Weather::Snow)
    {
        average_speed = 60;
    }
    if (condition == Weather::Sunny)
    {
        average_speed = 110;
    }
}

int Dacia::GetFuelCap() const
{
    return fuel_capacity;
}

int Dacia::GetFuelConsum() const
{
    return fuel_consumption_km;
}

int Dacia::GetAverageSpeed() const
{
    return average_speed;
}

