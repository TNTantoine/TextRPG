#include "Personnage.h"
#include <iostream>

using namespace std;

Personnage::Personnage () : m_name ("DefaultName"), m_HP (10), m_arme(0)
{
	m_arme = new Arme ();
}

Personnage::Personnage (string name) : m_name (name), m_HP (10)
{
	m_name = name;
	m_arme = new Arme ();
}

Personnage::Personnage (string name, int hp)
{
	m_name = name;
	m_HP = hp;
	m_arme = new Arme ();
}

Personnage::Personnage (string name, int hp, Arme arme)
{
	m_name = name;
	m_HP = hp;
	m_arme = new Arme(arme);
}

Personnage::~Personnage ()
{
	delete m_arme;
}

void Personnage::receiveDmg (int nbDegats)
{
	m_HP -= nbDegats;

	if (m_HP < 0)
	{
		m_HP = 0;
	}
	cout << m_name << " now has " << m_HP << " HP" << endl << endl;
}

void Personnage::addHP (int nbHP)
{
	if (m_HP <= 0)
	{
		cout << m_name << " has been resurrected !" << endl;
	}
	m_HP += nbHP;
	cout << m_name << " has been healed " << nbHP << "HP and now has " << m_HP << "HP" << endl;
}

void Personnage::attack (Personnage &cible) const
{
	cout << m_name << " attacks " << cible.m_name << " with " << m_arme->getName () << endl;
	if (m_arme->getDegats () <= 0)
	{
		cout << "The attack has zero effect !" << endl << endl;
	}
	else if (m_arme->getDegats () > 0 && m_arme->getDegats () <= 5)
	{
		cout << "Its not really effective..." << endl << endl;
	}
	else if (m_arme->getDegats () > 10)
	{
		cout << "Critical strike !" << endl << endl;
	}
	else
	{ 
		cout << endl;
	}
	cible.receiveDmg (m_arme->getDegats ());
}

void Personnage::changeWeapon (Arme &nouvelleArme)
{
	delete m_arme;
	m_arme = new Arme (nouvelleArme);
	cout << m_name << " equips the weapon " << m_arme->getName () << endl << endl;
}

void Personnage::displayStats () const
{
	cout << "-----------------------------------" << endl;
	cout << "| Stats of " << m_name << " :" << endl;
	cout << "| HP : " << m_HP << endl;
	cout << "| Weapon : " << m_arme->getName () << endl;
	cout << "-----------------------------------" << endl << endl;
}

string Personnage::getName () const
{
	return m_name;
}

string Personnage::getEquippedWeapon () const
{
	return m_arme->getName ();
}

bool Personnage::isAlive () const
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