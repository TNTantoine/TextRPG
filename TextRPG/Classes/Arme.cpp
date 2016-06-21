#include "Arme.h"
#include <iostream>

using namespace std;

Arme::Arme () : m_name ("nothing"), m_degats(1), m_value(0)
{
	
}

Arme::Arme (string name, int degats, int valeur)
{
	m_degats = degats;
	m_value = valeur;
	m_name = name;
}

Arme::~Arme ()
{
	
}

Arme::Arme (const Arme &armeToCopy)
{
	m_degats = armeToCopy.m_degats;
	m_name = armeToCopy.m_name;
	m_value = armeToCopy.m_value;
}

int Arme::getDegats () const
{
	return m_degats;
}

string Arme::getName () const
{
	return m_name;
}

int Arme::getValue () const
{
	return m_value;
}

void Arme::change (string name, int degats, int valeur)
{
	m_name = name;
	m_degats = degats;
	m_value = valeur;
}

void Arme::display () const
{
	cout << m_name << " (Damage : " << m_degats << " Value : " << m_value << ")" << endl;
}