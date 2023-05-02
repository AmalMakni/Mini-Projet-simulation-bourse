#ifndef PORTEFEUILLE_H_INCLUDED
#define PORTEFEUILLE_H_INCLUDED
#include "Titre.h"
#include<vector>

class Portefeuille
{
    private:
        double solde;
        vector <Titre> titres;
    public:
        Portefeuille(double s);
        void ajouterAction(string nomAction, int qte);
        void retireTitre(string nomAction, int qte);
        void deposerMontant(double montant);
        void retirerMontant(double montant);
        double getSolde() const;
        vector <Titre> getTitres() const;
        void acheterAction (string , int , double );
        void vendreAction (string , int , double );

};

#endif // PORTEFEUILLE_H_INCLUDED
