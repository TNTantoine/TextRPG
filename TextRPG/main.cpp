#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;

int main ()
{
	Arme	poings("Petits poings", 1, 0),
			couteau("Couteau rouillé", 5, 2),
			epee("Epee aiguisée",10,5),
			masse("Masse en pierre", 10, 3);

	Personnage	heros("Heros", 100, 100, poings),
				orc("Orc", 50, 50, masse);

	heros.changerArme (poings);
	orc.changerArme (masse);
	heros.afficherEtat ();
	orc.afficherEtat ();
	
	system ("PAUSE");
	return 0;
}

