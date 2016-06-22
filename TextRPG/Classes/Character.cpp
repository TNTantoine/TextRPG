#include "Character.h"
#include <stdlib.h>
#include <iostream>
#include <random>

using namespace std;

Character::Character () : m_name ("DefaultName"), m_HP (10)
{

}

Character::Character (string name) : m_name (name), m_HP (10)
{
	
}

Character::Character (string name, int hp)
{
	m_name = name;
	m_HP = hp;
}

Character::Character (string name, int hp, Arme arme)
{
	m_name = name;
	m_HP = hp;
}

Character::~Character ()
{

}

Character::Character (const Character &characterToCopy)
{
	m_name = characterToCopy.m_name;
	m_HP = characterToCopy.m_HP;
	m_arme = characterToCopy.m_arme;
}

void Character::receiveDmg (int nbDegats)
{
	m_HP -= nbDegats;

	if (m_HP < 0)
	{
		m_HP = 0;
	}
	cout << m_name << " now has " << m_HP << " HP" << endl << endl;
}

void Character::addHP (int nbHP)
{
	if (m_HP <= 0)
	{
		cout << m_name << " has been resurrected !" << endl;
	}
	m_HP += nbHP;
	cout << m_name << " has been healed " << nbHP << "HP and now has " << m_HP << "HP" << endl;
}

void Character::attack (Character &cible) const
{
	default_random_engine generator (random_device{}());
	uniform_int_distribution<int> distributionRngMultiplier (0, 10);
	int rngMultiplier = distributionRngMultiplier (generator);
	int tempDmg = m_arme.getDegats () * rngMultiplier;

	cout << m_name << " attacks " << cible.m_name << " with " << m_arme.getName () << " RNG = " << rngMultiplier << endl;
	if (tempDmg <= 0)
	{
		cout << tempDmg << " : The attack missed !" << endl << endl;
	}
	else if (tempDmg > 0 && tempDmg <= 3)
	{
		cout << tempDmg << " : Its not really effective..." << endl << endl;
	}
	else if (tempDmg > 3 && tempDmg < 8)
	{
		cout << tempDmg << " : The strike landed !" << endl << endl;
	}
	else if (tempDmg >= 8)
	{
		cout << tempDmg << " : Critical strike !" << endl << endl;
	}
	else
	{ 
		cout << endl;
	}
	cible.receiveDmg (tempDmg);
}

void Character::changeWeapon (Arme &nouvelleArme)
{
	m_arme = nouvelleArme;
	cout << m_name << " equips the weapon " << m_arme.getName () << endl << endl;
}

void Character::displayStats () const
{
	cout << "-----------------------------------" << endl;
	cout << "| Stats of " << m_name << endl;
	cout << "| HP : " << m_HP << endl;
	cout << "| Weapon : " << m_arme.getName () << endl;
	cout << "-----------------------------------" << endl << endl;
}

string Character::getName () const
{
	return m_name;
}

int Character::getHP () const
{
	return m_HP;
}

string Character::getEquippedWeapon () const
{
	return m_arme.getName ();
}

bool Character::isAlive () const
{
	bool temp;
	if (m_HP <= 0)
	{
		temp = false;
	}
	else
	{
		temp = true;
	}
	return temp;
}