#include "Arme.h"
#include <string>
#include <iostream>

using namespace std;

Arme::Arme () : m_nom ("Arme par defaut"), m_degats(0), m_valeur(0)
{
	
}

Arme::Arme (string nom, int degats, int valeur)
{
	m_degats = degats;
	m_valeur = valeur;
	m_nom = nom;
}

int Arme::getDegats () const
{
	return m_degats;
}

void Arme::changer (string nom, int degats, int valeur)
{
	m_nom = nom;
	m_degats = degats;
	m_valeur = valeur;
}

void Arme::afficher () const
{
	cout << "| Arme : " << m_nom << " (Degats : " << m_degats << " Valeur : " << m_valeur << ")" << endl;
}