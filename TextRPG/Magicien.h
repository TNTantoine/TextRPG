#pragma once
#include "Humain.h"

class Magicien : public Humain
{
public:
	Magicien (string nom);
	void heal (Personnage &cible) const;
	void bouleDeFeu (Personnage &cible) const;

private:
	int m_mana;
	
};

