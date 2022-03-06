#pragma once

//#include "EnemyController.h"

class Wave {
private:
	char* name;
	//EnemyController* control; am incercat aici sa ma folosesc de variabila nrofUnits pe care deja am definit-o dar nu-s sigur cum sa o obtin, fara sa am o functie
	//get si set in EnemyController
	int nrofEnemies;
	int startingHealth;
	float moneyperEnemy;
public:
	//constructorul l-am lasat default
	int get_startingHealth();
	void set_startingHealth(int value);
	int get_nrofEnemies();
	void set_nrofEnemies(int value);
	float get_moneyperEnemy();
	void set_moneyperEnemy(float value);
};

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