#include "Robber.h"
#include <iostream>
#include <string>

using namespace std;

Robber::Robber () : Character (), m_agility (100)
{

}

Robber::Robber (string name) : Character (name), m_agility (100)
{

}

void Robber::sneakAttack (Character &cible) const
{
	cible.receiveDmg (5+m_agility);
}