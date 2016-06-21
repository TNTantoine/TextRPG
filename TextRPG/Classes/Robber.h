#ifndef DEF_ROBBER
#define	DEF_ROBBER

#include <iostream>
#include <string>
#include "Character.h"


class Robber : public Character
{
public:
	Robber ();
	Robber (std::string name);
	void sneakAttack (Character &cible) const;
	//void stealObject (Character &cible) const;

private:
	int m_agility;
};

#endif // ! DEF_ROBBER