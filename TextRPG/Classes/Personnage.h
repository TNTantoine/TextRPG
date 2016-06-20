#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h"

class Personnage
{
public:
	Personnage (); //Prototype du constructeur du personnage
	Personnage (std::string m_name);
	Personnage (std::string m_name, int m_HP);
	Personnage (std::string m_name, int m_HP, Arme m_arme);
	~Personnage();
	void receiveDmg (int nbDegats);
	void addHP (int nbHP);
	void attack (Personnage &cible) const;
	void changeWeapon (Arme &arme);
	void displayStats () const;
	std::string getName () const;
	std::string getEquippedWeapon () const;
	bool isAlive () const;

protected:
	int m_HP;
	Arme *m_arme;
	std::string m_name;
};

#endif // !DEF_PERSONNAGE

