#include "Portefeuille.h"
#include "Titre.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Portefeuille::Portefeuille(double s, vector <Titre *> vecteurTitres): solde(s), titres(vecteurTitres) {};

void Portefeuille::ajouterAction(string nomAction, int qte)
{

};

void Portefeuille::retireTitre(string nomAction, int qte)
{

};

void Portefeuille::deposerMontant(double montant)
{

};
void Portefeuille::retirerMontant(double montant)
{

};

double Portefeuille::getSolde() const
{
    return solde;
};
vector <Titre *> Portefeuille::getTitres() const
{
    return titres;
};
