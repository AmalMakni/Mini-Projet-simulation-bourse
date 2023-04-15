#include <iostream>
#include "date.h"
#include <vector>
#include "Bourse.h"
#include "PrixJournalier.h"


Bourse::Bourse ( Date date ) : dateFinRecherche(date)
{}
BourseVecteur::BourseVecteur(Date date , vector<PrixJournalier> pj) : Bourse(date),historique(pj)
{}

vector<string> BourseVecteur::getActionsDisponibleParDate(Date d)
{
  vector<string> ActionDispo;
  for ( int i =0 ; i<historique.size();i++)
  {
      if ( historique[i].getDate()== d)
        ActionDispo.push_back(historique[i].getNom());
  }
  return ActionDispo;
}

vector<double> BourseVecteur::getPrixJournalierParDate(Date d)
{
    vector<double> PrixAction;
    for ( int i =0 ; i< historique.size();i++)
    {
        if ( historique[i].getDate()== d)
        PrixAction.push_back(historique[i].getPrix());
    }
    return PrixAction;

}

