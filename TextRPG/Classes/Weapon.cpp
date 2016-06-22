#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon () : m_name ("nothing"), m_degats(1), m_value(0)
{
	
}

Weapon::Weapon (string name, int degats, int valeur)
{
	m_degats = degats;
	m_value = valeur;
	m_name = name;
}

Weapon::~Weapon ()
{
	
}

Weapon::Weapon (const Weapon &WeaponToCopy)
{
	m_degats = WeaponToCopy.m_degats;
	m_name = WeaponToCopy.m_name;
	m_value = WeaponToCopy.m_value;
}

int Weapon::getDegats () const
{
	return m_degats;
}

string Weapon::getName () const
{
	return m_name;
}

int Weapon::getValue () const
{
	return m_value;
}

void Weapon::change (string name, int degats, int valeur)
{
	m_name = name;
	m_degats = degats;
	m_value = valeur;
}

void Weapon::display () const
{
	cout << m_name << " (Damage : " << m_degats << " Value : " << m_value << ")" << endl;
}