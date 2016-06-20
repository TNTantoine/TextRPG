#ifndef DEF_ARME
#define DEF_ARME

#include <string>

class Arme
{
public:
	Arme (); //Constructeur de l'arme
	Arme (std::string nom, int degats, int value);
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