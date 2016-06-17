#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h"

class Personnage
{
public:
	Personnage (); //Prototype du constructeur du personnage
	Personnage (std::string m_nom);
	void recevoirDegats (int nbDegats);
	void attaquer (Personnage &cible) const;
	
	void afficherStats () const;

protected:
	int m_vie;
	Arme *m_arme;
	std::string m_nom;
};

#endif // !DEF_PERSONNAGE

