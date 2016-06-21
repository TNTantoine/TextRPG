#ifndef DEF_WARRIOR
#define	DEF_WARRIOR

#include <iostream>
#include <string>
#include "Character.h"


class Warrior : public Character
{
public:
	Warrior ();
	~Warrior ();
	Warrior (std::string name);
	void chargeAttack (Character &cible) const;
	void blockAttack (Character &cible) const;
	void receiveDmg (int nbDegats);

private:
	int m_armor;
};

#endif // ! DEF_WARRIOR