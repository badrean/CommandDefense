#include "GlobalWave.h"

int compareEnemiesNumber(Wave* wave1, Wave* wave2)
{
	if (wave1->get_nrofEnemies() == wave2->get_nrofEnemies()) return 0;
	if (wave1->get_nrofEnemies() > wave2->get_nrofEnemies()) return 1;
	return -1;
}

int compareMoney(Wave* wave1, Wave* wave2)
{
	if (wave1->get_moneyperEnemy() == wave2->get_moneyperEnemy()) return 0;
	if (wave1->get_moneyperEnemy() > wave2->get_moneyperEnemy()) return 1;
	return -1;
}