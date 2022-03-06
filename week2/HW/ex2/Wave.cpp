#include "Wave.h"
#include "iostream"

int Wave::get_startingHealth()
{
	return this->startingHealth;
}

void Wave::set_startingHealth(int value)
{
	if (value > 0) this->startingHealth = value;
	else printf("The starting health cannot be lower than 1.");
}

int Wave::get_nrofEnemies()
{
	return this->nrofEnemies;
}

void Wave::set_nrofEnemies(int value)
{
	if (value > 0) this->nrofEnemies = value;
	else printf("The number of enemies cannot be lower than 1.");
}

float Wave::get_moneyperEnemy()
{
	return this->moneyperEnemy;
}

void Wave::set_moneyperEnemy(float value)
{
	if (value > 0) this->moneyperEnemy = value;
	else printf("The money drop per enemy cannot be lower than 1.");
}