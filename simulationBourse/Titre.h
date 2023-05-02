#ifndef TITRE_H_INCLUDED
#define TITRE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Titre
{
    private:
        string nomAction;
        int quantite;
    public:
        Titre(string nom, int qte);
        string getNomAction() const;
        int getQuantite() const;
        void setQuantite(int q){quantite=q;};
};

class TestTitre
{
    public:
        void initialiserTitre();
};

#endif // TITRE_H_INCLUDED
