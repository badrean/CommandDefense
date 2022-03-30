#include "Mercedes.h"

Mercedes::Mercedes(int fuel_cap, int fuel_consum, Weather condition)
{
    name = new char[9];
    strcpy((char*)name, "Mercedes");
    fuel_capacity = fuel_cap;
    fuel_consumption_km = fuel_consum;

    if (condition == Weather::Rain)
    {
        average_speed = 70;
    }
    if (condition == Weather::Snow)
    {
        average_speed = 55;
    }
    if (condition == Weather::Sunny)
    {
        average_speed = 105;
    }
}

int Mercedes::GetFuelCap() const
{
    return fuel_capacity;
}

int Mercedes::GetFuelConsum() const
{
    return fuel_consumption_km;
}

int Mercedes::GetAverageSpeed() const
{
    return average_speed;
}
