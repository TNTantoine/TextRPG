#include <iostream>
#include <string>
#include <conio.h>

#include "Personnage.h"
#include "Magicien.h"

using namespace std;

int continueKey;
bool isHeroTurn = false;

string playerName = "";

Arme	fists ("Puny fists", 1, 0),
		rustyKnife ("Rusty knife", 6, 2),
		sharpSword ("Sharp sword", 10, 5),
		rockMace ("Rock mace", 12, 3),
		apocalypse ("Apocalypse", 2000, 0);


void Fight (Personnage player, Personnage enemy)
{
	cout << "A wild " << enemy.getName () << " jumped on your path !" << endl;

	cout << "(A)ttack or (F)lee ?" << endl;
	do
	{
		continueKey = _getch ();
		continueKey = toupper (continueKey);
	} while (continueKey != 'A' && continueKey != 'F');

	if (continueKey == 'A')
	{
		cout << "Thee wanteth to square the " << enemy.getName () << " !" << endl;
		cout << "Thee determination destabilizeth the " << enemy.getName () << " ! Thou shall strike first !" << endl;
		player.attack (enemy);
		isHeroTurn = false;
	}
	else
	{
		cout << "The " << enemy.getName () << " block'd the way, thee cannot escapeth !" << endl;
		cout << "The " << enemy.getName () << " sees thee hesitation and engages first !" << endl;
		enemy.attack (player);
		isHeroTurn = true;
	}

	while (enemy.isAlive () && player.isAlive())
	{
		if (isHeroTurn)
		{
			cout << "(A)ttack or (F)lee ?" << endl;
			do
			{
				continueKey = _getch ();
				continueKey = toupper (continueKey);
			} while (continueKey != 'A' && continueKey != 'F');

			if (continueKey == 'A')
			{
				player.attack (enemy);
			}
			else
			{
				cout << "The " << enemy.getName () << " block'd the way, thee cannot escapeth !" << endl;
			}
			isHeroTurn = false;
		}
		else
		{
			enemy.attack (player);
			isHeroTurn = true;
		}
	}

	if (!player.isAlive ())
	{
		cout << "Thou got slained by the " << enemy.getName () << " !" << endl;
		cout << "May thee soul resteh is peace..." << endl << endl;
	}

	else if (!enemy.isAlive ())
	{
		cout << "Thou vanquished the " << enemy.getName () << " !" << endl << endl;
		cout << "The " << enemy.getName () << " dropped something..." << endl;
		cout << "You found a " << rustyKnife.getName () << " !" << endl << endl;
		cout << "(E)quip the " << rustyKnife.getName () << " or (L)eave it ?" << endl;

		do
		{
			continueKey = _getch ();
			continueKey = toupper (continueKey);
		} while (continueKey != 'E' && continueKey != 'L');

		if (continueKey == 'E')
		{
			player.changeWeapon (rustyKnife);
		}
		else
		{
			cout << "Thou left the " << rustyKnife.getName () << " and kept thee " << player.getEquippedWeapon () << endl << endl;
		}
	}
	else
	{
		cout << "Thou cowardly fled the " << enemy.getName () << " !" << endl << endl;
	}
}

int main ()
{
	cout << "___________              __ ____________________  ________ " << endl;
	cout << "\\__    ___/___ ___  ____/  |\\______   \\______   \\/  _____/ " << endl;
	cout << "  |    |_/ __ \\   \\/  /\\   __\\       _/|     ___/   \\  ___ " << endl;
	cout << "  |    |\\  ___/ >    <  |  | |    |   \\|    |   \\    \\_\\  \\ " << endl;
	cout << "  |____| \\___  >__/\\_ \\ |__| |____|_  /|____|    \\______  /" << endl;
	cout << "             \\/      \\/             \\/                  \\/ " << endl << endl;

	cout << "A TEXT BASED RPG EXPERIENCE" << endl << endl;

	cout << "Thee shalt typeth thy nameth :" << endl;
		
	cin >> playerName;
		
	Personnage heros (playerName, 20, fists);

	cout << endl << "Welcometh to the w'rld of Agrandar warrior " << heros.getName() << " !" << endl;
	cout << "Lets has't a behold at thy stats" << endl << endl;

	heros.displayStats ();

	cout << "Typeth the 'Y' key to continueth" << endl << endl;

	do
	{
		continueKey = _getch ();
		continueKey = toupper (continueKey);
	} while (continueKey != 'Y');

	Personnage orc ("Orc", 10, fists);
	Fight (heros, orc);

	if (!heros.isAlive ())
	{
		heros.addHP (1);
		cout << "To be continued ?..." << endl << endl;
	}
	else
	{
		//Relancer un fight avec une autre creature cause un leak mémoire ???
		////Personnage demon ("Demon", 200, apocalypse);
		//Fight (heros, demon);
		//heros.addHP (1);
		//cout << "To be continued ?..." << endl << endl;
	}

	cout << "Congratulations ! Thou finisheth the demo !" << endl << endl;
	cout << "Don't hesitate to give the project a look at \"github.com/TNTantoine/TextRPG \"" << endl;
	cout << "If you have ideas to improve the game, don't hesitate to do a pull request !" << endl;

	system ("PAUSE");

	return 0;
}