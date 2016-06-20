#include "Personnage.h"
#include <iostream>

using namespace std;

Personnage::Personnage () : m_nom("DefaultName"), m_vie (100), m_arme(0)
{
	m_arme = new Arme ();
}

Personnage::Personnage (string nom) : m_vie(100), m_nom(nom)
{
	m_nom = nom;
}

Personnage::~Personnage ()
{
	delete m_arme;
}

void Personnage::recevoirDegats (int nbDegats)
{
	m_vie -= nbDegats;

	if (m_vie < 0)
	{
		m_vie = 0;
	}
}

void Personnage::attaquer (Personnage &cible) const
{
	cible.recevoirDegats (m_arme->getDegats ());
}

void Personnage::afficherStats () const
{
	cout << "-----------------------------------" << endl;
	cout << "| Stats de " << m_nom << " :" << endl;
	cout << "| Vie : " << m_vie << endl;
	m_arme->afficher ();
	cout << "-----------------------------------" << endl << endl;
}