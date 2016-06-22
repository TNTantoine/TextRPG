#include <iostream>
#include <vector>
#include <conio.h>
#include <random>
#include <chrono>
#include <thread>

#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Robber.h"


using namespace std;

int continueKey;

Character heros;

vector<Weapon> botWeaponList, droppableWeaponList;
vector<Character> botList;

default_random_engine generator (random_device{}());;

void Init ()
{
	Weapon
		fists ("Puny fists", 2, 0),
		claws ("Claws", 3, 0),
		sharpTeeth ("Sharp teeth", 5, 0),
		rustyKnife ("Rusty knife", 4, 2),
		sharpSword ("Sharp sword", 10, 5),
		rockMace ("Rock mace", 3, 1),
		hatchet ("Hatchet", 6, 4),
		axe ("Axe", 8, 6),
		magicStick ("Magic stick", 4, 4),
		hauntingWhisper ("Haunting whisper", 0, 0),
		apocalypse ("Apocalypse", 666, 0);

	droppableWeaponList = { rustyKnife , sharpSword, rockMace, hatchet, axe, magicStick };

	Character
		slime ("Slime", 5),
		rat ("Rat", 10, claws),
		kobold ("Kobold", 15, claws),
		zombie ("Zombie", 20, claws),
		orc ("Orc", 30, rockMace),
		vampire ("Vampire", 40, sharpTeeth),
		ghost ("Ghost", 10, hauntingWhisper),
		lucifer ("Lucifer the Doombringer", 666, apocalypse);
		

	botList = { slime, rat, kobold, zombie, orc, vampire, ghost, lucifer };
}

void CheckForLoot (Character player, Character enemy)
{
	cout << "Thou vanquished the " << enemy.getName () << " !" << endl << endl;

	uniform_int_distribution<int> distributionDropRNG (0, 10);
	int rngDrop = distributionDropRNG (generator);

	//The enemy drops an object
	if (rngDrop > 5)
	{
		cout << "The " << enemy.getName () << " dropped something..." << endl;
		std::this_thread::sleep_for (std::chrono::milliseconds (500));

		uniform_int_distribution<int> distributionFind (0, droppableWeaponList.size () - 1);

		int rngFind = distributionFind (generator);

		if (rngFind == droppableWeaponList.size ())
		{
			cout << "Your luck is beyond human comprehension, you found the " << droppableWeaponList[rngFind].getName () << " !" << endl;
		}
		else
		{
			cout << "You found a " << droppableWeaponList[rngFind].getName () << " !" << endl << endl;
		}

		cout << "(E)quip the " << droppableWeaponList[rngFind].getName () << " or (L)eave it ?" << endl;

		do
		{
			continueKey = _getch ();
			continueKey = toupper (continueKey);
		} while (continueKey != 'E' && continueKey != 'L');

		if (continueKey == 'E')
		{
			player.changeWeapon (droppableWeaponList[rngFind]);
		}
		else
		{
			cout << "Thou left the " << droppableWeaponList[rngFind].getName () << " and kept thee " << player.getEquippedWeapon () << endl << endl;
		}
	}
	else
	{
		cout << "The " << enemy.getName () << " left nothing." << endl;
	}
	
}

void Fight (Character player, Character enemy)
{
	bool isHeroTurn = false;

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
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
		cout << "Thee determination destabilizeth the " << enemy.getName () << " ! Thou shall strike first !" << endl << endl;
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
		player.attack (enemy);
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
		isHeroTurn = false;
	}
	else
	{
		cout << "The " << enemy.getName () << " block'd the way, thee cannot escapeth !" << endl;
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
		cout << "The " << enemy.getName () << " sees thee hesitation and engages first !" << endl << endl;
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
		enemy.attack (player);
		std::this_thread::sleep_for (std::chrono::milliseconds (1000));
		isHeroTurn = true;
	}

	while (enemy.isAlive () && player.isAlive ())
	{
		if (isHeroTurn)
		{
			cout << "(A)ttack or (F)lee ?" << endl << endl;
			do
			{
				continueKey = _getch ();
				continueKey = toupper (continueKey);
			} while (continueKey != 'A' && continueKey != 'F');

			if (continueKey == 'A')
			{
				player.attack (enemy);
				std::this_thread::sleep_for (std::chrono::milliseconds (1000));
			}
			else
			{
				uniform_int_distribution<int> distributionFlee (0, 1);
				int rngFlee = distributionFlee (generator);
				cout << "Rolled the dice for flee : " << rngFlee << endl;
				if (rngFlee >= 5)
				{
					cout << "The " << enemy.getName () << " block'd the way, thee cannot escapeth !" << endl;
					std::this_thread::sleep_for (std::chrono::milliseconds (500));
				}	
				else
				{
					cout << "Thou cowardly fled " << enemy.getName () << " !" << endl << endl;
					std::this_thread::sleep_for (std::chrono::milliseconds (500));
					return;
				}
			}
			isHeroTurn = false;
		}
		else
		{
			enemy.attack (player);
			std::this_thread::sleep_for (std::chrono::milliseconds (500));
			isHeroTurn = true;
		}
	}

	if (!player.isAlive ())
	{
		cout << "Thou got slained by " << enemy.getName () << " !" << endl;
		std::this_thread::sleep_for (std::chrono::milliseconds (500));
		cout << "May thee soul resteh is peace..." << endl << endl;
	}

	else if (!enemy.isAlive ())
	{
		CheckForLoot (player, enemy);
	}
}

void Intro ()
{
	cout << "___________              __ ____________________  ________ " << endl;
	cout << "\\__    ___/___ ___  ____/  |\\______   \\______   \\/  _____/ " << endl;
	cout << "  |    |_/ __ \\   \\/  /\\   __\\       _/|     ___/   \\  ___ " << endl;
	cout << "  |    |\\  ___/ >    <  |  | |    |   \\|    |   \\    \\_\\  \\ " << endl;
	cout << "  |____| \\___  >__/\\_ \\ |__| |____|_  /|____|    \\______  /" << endl;
	cout << "             \\/      \\/             \\/                  \\/ " << endl << endl;

	cout << "A TEXT BASED RPG EXPERIENCE !" << endl << endl;
}

void CharacterCreation ()
{
	cout << "Thee shalt typeth thy nameth :" << endl;

	string playerName = "";
	cin >> playerName;

	/*cout << "Thee shalt chooseth a class : (W)arrior - Wi(Z)ard - (R)obber" << endl;

	do
	{
	continueKey = _getch ();
	continueKey = toupper (continueKey);
	} while (continueKey != 'W' && continueKey != 'Z' && continueKey != 'R');

	if(continueKey == 'W')
	Warrior heros (playerName);
	else if(continueKey == 'Z')
	Wizard heros (playerName);
	else if(continueKey == 'R')
	Robber heros (playerName);
	*/

	Character temp (playerName, 40, droppableWeaponList[0]);
	heros = temp;


	cout << endl << "Welcometh to the w'rld of Agrandar warrior " << heros.getName () << " !" << endl;
	std::this_thread::sleep_for (std::chrono::milliseconds (500));
	cout << "Lets has't a behold at thy stats" << endl << endl;

	heros.displayStats ();

	std::this_thread::sleep_for (std::chrono::milliseconds (500));
	cout << "Typeth the 'Y' key to continueth" << endl << endl;

	do
	{
		continueKey = _getch ();
		continueKey = toupper (continueKey);
	} while (continueKey != 'Y');
}

void DemoScenario ()
{
	//RNG to determine the enemy
	uniform_int_distribution<int> distributionEncounter (0, botList.size()-1);
	int rngEncounter = distributionEncounter (generator);

	Fight (heros, botList[rngEncounter]);

	//Temporary Revive if the hero dies
	if (!heros.isAlive ())
	{
		heros.addHP (1);
		cout << "To be continued ?..." << endl << endl;
	}
}

bool CheckIfRestartGame ()
{
	cout << "You can now either (Q)uit the game or (C)ontinue your adventure !" << endl <<endl;
	do
	{
		continueKey = _getch ();
		continueKey = toupper (continueKey);
	} while (continueKey != 'Q' && continueKey != 'C');

	if (continueKey == 'C')
	{
		system ("cls");
		return true;
	}

	return false;
}

int main ()
{
	bool restart = true;

	Init ();
	Intro ();
	CharacterCreation ();
	while (restart)
	{		
		DemoScenario ();
		if (!CheckIfRestartGame ())
		{
			restart = false;
		}
	}

	cout << "Congratulations ! Thou finisheth the demo !" << endl << endl;
	cout << "Don't hesitate to give the project a look at \"github.com/TNTantoine/TextRPG \"" << endl;
	cout << "If you have ideas to improve the game, don't hesitate to do a fork !" << endl << endl;
	system ("PAUSE");

	return 0;
}