#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <string>

class Weapon
{
public:
	Weapon (); //Constructeur de l'arme
	~Weapon ();
	Weapon (const Weapon & weaponToCopy);
	Weapon (std::string nom, int degats, int value);
	int getDegats () const;
	std::string getName () const;
	int getValue () const;
	void change (std::string nom, int degats, int value);
	void display () const;

protected:
	int m_degats;
	int m_value;
	std::string m_name;

};
#endif // !DEF_ARME