#pragma once
#include "Humain.h"
class Guerrier : public Humain 
{
public:
	Guerrier();
	void chargeAttack (Personnage &cible) const;
	void groundSmash (Personnage &cible) const;

private:
	int m_armor;
};

