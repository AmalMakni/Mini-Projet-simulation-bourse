#include "PrixJournalier.h"
#include "date.h"
#include <iostream>
#include <string>
using namespace std;

Date PrixJournalier::getDate() const
{
    return date;
}

string PrixJournalier::getNom() const
{
    return nomAction;
}

double PrixJournalier::getPrix() const
{
    return prix;
}

istream& operator>>(istream& flux, PrixJournalier& pj)
{
    flux>>pj.date;
    char tab[1000];
    flux.getline(tab,1000,';');
    pj.nomAction=tab;
    flux.getline(tab,1000);
    pj.prix=atof(tab);
    return flux;
}
