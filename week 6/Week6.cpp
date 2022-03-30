#pragma warning
#include "Circuit.h"
#include "Car.h"
#include "Dacia.h"
#include "Mercedes.h"
#include "Toyota.h"

int main()

{
	Circuit c;

	c.SetLength(100);

	c.SetWeather(Weather::Rain);

	c.AddCar(new Dacia(200, 100, c.GetWeather()));

	c.AddCar(new Toyota(150, 80, c.GetWeather()));

	c.AddCar(new Mercedes(300, 140, c.GetWeather()));

	//c.AddCar(new Ford());

	//c.AddCar(new Mazda());

	c.Race();

	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.

	c.ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit

	return 0;
}