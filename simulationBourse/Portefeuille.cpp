#include "Portefeuille.h"
#include "Titre.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;


Portefeuille::Portefeuille(double s): solde(s) {};

void Portefeuille::ajouterAction(string nomAction, int qte)
{
    int i=0;
    bool existe=false;
    while( !existe && i< titres.size())
        if (titres[i].getNomAction()==nomAction)
            existe=true;
        else
            i++;
    if (existe)
        titres[i].setQuantite(titres[i].getQuantite()+qte);
    else
        {
            Titre nouveauTitre(nomAction, qte);
            titres.push_back( nouveauTitre);
        }
};

void Portefeuille::retireTitre(string nomAction, int qte)
{
    int i=0;
    bool existe=false;
    while( !existe && i< titres.size())
        if (titres[i].getNomAction()==nomAction)
        {
            existe=true;
            //cout<<"existe"<<endl;
        }

        else
            i++;
    if (existe && titres[i].getQuantite()>=qte)
        {
          titres[i].setQuantite(titres[i].getQuantite()-qte);
          //cout<<titres[i].getQuantite();
        }
    if (titres[i].getQuantite()==0)
        titres.erase(titres.begin()+i);
};

void Portefeuille::deposerMontant(double montant)
{
    solde+=montant;
};
void Portefeuille::retirerMontant(double montant)
{
    if (solde>=montant)
        solde=solde-montant;
};

double Portefeuille::getSolde() const
{
    return solde;
};
vector <Titre > Portefeuille::getTitres() const
{
    return titres;
};
void Portefeuille::acheterAction(string nom , int qte , double prix )
{
    ajouterAction(nom,qte);
    retirerMontant(prix*qte);
//    cout<<prix*qte<<endl;
//    cout<<solde<<endl;
}
void Portefeuille::vendreAction(string nom , int qte , double prix )
{
    retireTitre(nom,qte);
    deposerMontant(prix*qte);
}
