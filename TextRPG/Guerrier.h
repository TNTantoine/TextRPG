#pragma once
#include "Humain.h"
class Guerrier : public Humain 
{
public:
	void chargeAttack (Personnage &cible) const;
	void groundSmash (Personnage &cible) const;

private:
	int m_armor;
};

