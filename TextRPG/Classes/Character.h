#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Weapon.h"

class Character
{
public:
	Character (); //Prototype du constructeur du personnage
	Character (std::string m_name);
	Character (std::string m_name, int m_HP);
	Character (std::string m_name, int m_HP, const Weapon &m_Weapon);
	~Character ();
	Character (const Character & characterToCopy);
	void receiveDmg (int nbDegats);
	void addHP (int nbHP);
	void attack (Character &cible) const;
	void changeWeapon (Weapon &Weapon);
	void displayStats () const;
	std::string getName () const;
	int getHP () const;
	std::string getEquippedWeapon () const;
	bool isAlive () const;

protected:
	int m_HP;
	Weapon m_Weapon;
	std::string m_name;
};

#endif // !DEF_PERSONNAGE

