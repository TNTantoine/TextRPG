#include "Personnage.h"
#include <iostream>

using namespace std;

Personnage::Personnage () : m_nom("DefaultName"), m_vie (100), m_mana (100), m_arme(0)
{
	m_arme = new Arme ();
}

Personnage::Personnage (string nom, int vie, int mana, Arme arme)
{
	m_nom = nom;
	m_vie = vie;
	m_mana = mana;
	m_arme = new Arme(arme);
}

Personnage::~Personnage ()
{
	delete m_arme;
}


//Le deux constructeurs qui suivent sont indissociables, si constructeur de copie, operator= NEEDED !)
Personnage::Personnage (Personnage const& personnageACopier) : m_nom (personnageACopier.m_nom), m_vie (personnageACopier.m_vie), m_mana (personnageACopier.m_mana), m_arme (0)
{
	m_arme = new Arme(*(personnageACopier.m_arme));
}

Personnage& Personnage::operator=(Personnage const& personnageACopier)
{
	if (this != &personnageACopier)
	{
		m_vie = personnageACopier.m_vie;
		m_mana = personnageACopier.m_mana;
		m_nom = personnageACopier.m_nom;
		delete m_arme;
		m_arme = new Arme (*(personnageACopier.m_arme));
	}
	return *this;
}

void Personnage::recevoirDegats (int nbDegats)
{
	m_vie -= nbDegats;

	if (m_vie < 0)
	{
		m_vie = 0;
	}
}

void Personnage::attaquer (Personnage &cible)
{
	cible.recevoirDegats (m_arme->getDegats ());
}

void Personnage::boirePotionDeVie (int quantitePotion)
{
	m_vie += quantitePotion;

	if (m_vie > 100)
	{
		m_vie = 100;
	}
}

void Personnage::changerArme (Arme nouvelleArme)
{
	m_arme = new Arme(nouvelleArme);
}

bool Personnage::estVivant () const
{
	return m_vie > 0;
}

void Personnage::afficherEtat () const
{
	cout << "-----------------------------------" << endl;
	cout << "| Stats de " << m_nom << " :" << endl;
	cout << "| Vie : " << m_vie << endl;
	cout << "| Mana : " << m_mana << endl;
	m_arme->afficher ();
	cout << "-----------------------------------" << endl << endl;
}