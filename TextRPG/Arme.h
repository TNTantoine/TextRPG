#ifndef DEF_ARME
#define DEF_ARME

#include <string>

class Arme
{
public:
	Arme (); //Constructeur de l'arme
	Arme (std::string nom, int degats, int valeur);
	int getDegats () const;
	void changer (std::string nom, int degats, int valeur);
	void afficher () const;

private:
	int m_degats;
	int m_valeur;
	std::string m_nom;

};
#endif // !DEF_ARME
