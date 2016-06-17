#include <iostream>
#include <string>
#include "Personnage.h"
#include "Magicien.h"

using namespace std;

int main ()
{
	Arme	poings("Petits poings", 1, 0),
			couteau("Couteau rouillé", 5, 2),
			epee("Epee aiguisée",10,5),
			masse("Masse en pierre", 10, 3);

	Personnage	heros("Heros", 100, poings),
				orc("Orc", 50, masse);

	Magicien merlin ();

	heros.afficherEtat ();
	orc.afficherEtat ();
	
	system ("PAUSE");
	return 0;
}

