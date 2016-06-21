#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior ()
{

}

Warrior::~Warrior ()
{

}

Warrior::Warrior (string name) : Character (name), m_armor (10)
{

}

void Warrior::chargeAttack (Character &cible) const
{
	cible.receiveDmg (10);
}

void Warrior::blockAttack (Character &cible) const
{
	cible.receiveDmg (10);
}

void Warrior::receiveDmg (int nbDegats)
{
	nbDegats -= m_armor;
	m_HP -= nbDegats;

	if (m_HP < 0)
	{
		m_HP = 0;
	}
	cout << m_name << " blocked " << m_armor << " damage with his armor !" << endl;
	cout << m_name << " now has " << m_HP << " HP" << endl << endl;
}