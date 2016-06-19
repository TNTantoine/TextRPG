#pragma once
#include "Humain.h"
class Voleur : public Humain
{
public:
	Voleur();
	void sneakAttack (Personnage &cible) const;
	void stealItem (Personnage &cible) const;

private:
	int m_agility;
};