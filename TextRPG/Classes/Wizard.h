#ifndef DEF_WIZARD
#define	DEF_WIZARD

#include <iostream>
#include <string>
#include "Character.h"


class Wizard : public Character
{
public:
	Wizard ();
	Wizard (std::string name);
	void fireBall (Character &cible);
	void heal (Character &cible);
	void substractMana (int subMana);

protected:
	int m_mana;
};

#endif // ! DEF_WIZARD