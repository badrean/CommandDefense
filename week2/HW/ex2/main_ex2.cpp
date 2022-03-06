#include <iostream>
#include "GlobalWave.h"

/*
	Design a C++ class that reflects the properties of an wave of  enemies. The class should include the following:
 - methods to set and get the name of the wave
 - methods to set and get the number of enemies  (must be bigger than 0)
 - methods to set and get the starting health (bigger than 0)
 - methods to set and get the money per enemy (must be a float value)


	Create 2 global functions that compare two wave in terms of: number of enemies and money per enemy.
If two waves are equal the return value of such a function will be 0. If the first wave is bigger than the second one, the return value will be 1, otherwise -1.
	Make sure that you have the following:
a cpp file for the methods specific to the class
a header file for the global functions
a cpp file for the global functions implementation
- a main.cpp file that shows how the methods and global functions can be used.

*/

int main()
{
	Wave* ptrWave = new Wave[2];

	ptrWave[0].set_nrofEnemies(9);
	ptrWave[0].set_startingHealth(10);
	ptrWave[0].set_moneyperEnemy(2.5f);

	ptrWave[1].set_nrofEnemies(10);
	ptrWave[1].set_startingHealth(10);
	ptrWave[1].set_moneyperEnemy(1.5f);

	int x = compareEnemiesNumber(&ptrWave[0], &ptrWave[1]);
	int y = compareMoney(&ptrWave[0], &ptrWave[1]);

	printf("x = %d si y = %d", x, y);

	delete[] ptrWave;

    return 0;
}