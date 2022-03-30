#include "Toyota.h"


Toyota::Toyota(int fuel_cap, int fuel_consum, Weather condition)
{
    name = new char[7];
    strcpy((char*)name, "Toyota");
    fuel_capacity = fuel_cap;
    fuel_consumption_km = fuel_consum;

    if (condition == Weather::Rain)
    {
        average_speed = 60;
    }
    if (condition == Weather::Snow)
    {
        average_speed = 50;
    }
    if (condition == Weather::Sunny)
    {
        average_speed =90;
    }
}

int Toyota::GetFuelCap() const
{
    return fuel_capacity;
}

int Toyota::GetFuelConsum() const
{
    return fuel_consumption_km;
}

float Toyota::GetAverageSpeed() const
{
    return average_speed;
}
