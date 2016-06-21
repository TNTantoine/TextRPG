#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h"

class Character
{
public:
	Character (); //Prototype du constructeur du personnage
	Character (std::string m_name);
	Character (std::string m_name, int m_HP);
	Character (std::string m_name, int m_HP, Arme m_arme);
	~Character ();
	Character (const Character & characterToCopy);
	void receiveDmg (int nbDegats);
	void addHP (int nbHP);
	void attack (Character &cible) const;
	void changeWeapon (Arme &arme);
	void displayStats () const;
	std::string getName () const;
	int getHP () const;
	std::string getEquippedWeapon () const;
	bool isAlive () const;

protected:
	int m_HP;
	Arme m_arme;
	std::string m_name;
};

#endif // !DEF_PERSONNAGE

