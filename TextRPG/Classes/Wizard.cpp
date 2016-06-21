#include "Wizard.h"
#include <iostream>
#include <string>

using namespace std;

Wizard::Wizard () : Character(), m_mana(100)
{

}

Wizard::Wizard (string name) : Character(name), m_mana(100)
{

}

void Wizard::fireBall (Character &cible)
{	
	int manaCost = 20;
	substractMana (manaCost);
	cible.receiveDmg (20);
}

void Wizard::heal (Character &cible)
{
	int manaCost = 10;
	substractMana (manaCost);
	cible.addHP (20);
}

void Wizard::substractMana (int subMana)
{
	m_mana -= subMana;
}