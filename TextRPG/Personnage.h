#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <string>
#include "Arme.h"

class Personnage
{
public:
	Personnage (); //Prototype du constructeur du personnage
	Personnage (Personnage const& personnageACopier); // Prototype du constructeur de copie
	Personnage (std::string m_nom, int m_vie, int m_mana, Arme m_arme);
	void recevoirDegats (int nbDegats);
	void attaquer (Personnage &cible);
	void boirePotionDeVie (int quantitePotion);
	void changerArme (Arme nouvelleArme);
	bool estVivant () const;
	void afficherEtat () const;

private:
	int m_vie;
	int m_mana;
	Arme *m_arme;
	std::string m_nom;
};

#endif // !DEF_PERSONNAGE

