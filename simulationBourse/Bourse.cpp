#include <iostream>
#include "date.h"
#include <vector>
#include "Bourse.h"
#include "PrixJournalier.h"
#include "PersistancePrixJournalier.h"

//Bourse Vecteur:
Bourse::Bourse ( Date date ) : dateAujourdhui(date)
{}
BourseVecteur::BourseVecteur(Date date , vector<PrixJournalier> pj) : Bourse(date),historique(pj)
{}

vector<string> BourseVecteur::getActionsDisponibleParDate(Date d)
{
  vector<string> ActionDispo;
   if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
  {
    for ( int i =0 ; i<historique.size();i++)
    {
      if ( historique[i].getDate()== d)
        ActionDispo.push_back(historique[i].getNom());
    }
  }
  return ActionDispo;
}

vector<PrixJournalier> BourseVecteur::getPrixJournalierParDate(Date d)
{
    vector<PrixJournalier> PrixAction;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        for ( int i =0 ; i< historique.size();i++)
        {
        if ( historique[i].getDate()== d)
        PrixAction.push_back(historique[i]);
        }
    }

    return PrixAction;

}

//Bourse Vecteur Optimisée

BourseVecteurOptimisee::BourseVecteurOptimisee(Date date , vector<PrixJournalier> pj) : Bourse(date),historique(pj)
{}

vector<string> BourseVecteurOptimisee::getActionsDisponibleParDate(Date d)
{
  vector<string> ActionDispo;
  //cout<<(!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))<<endl;
  if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
  {
        int i=0;
        while(historique[i].getDate()<d && i<historique.size())
            i++;
        while(historique[i].getDate()==d && i<historique.size())
        {
            ActionDispo.push_back(historique[i].getNom());
            i++;
        }
    }
  return ActionDispo;

}

vector<PrixJournalier> BourseVecteurOptimisee::getPrixJournalierParDate(Date d)
{
    vector <PrixJournalier> prix;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        int i=0;
        while(historique[i].getDate()<d && i<historique.size())
            i++;
        while(historique[i].getDate()==d && i<historique.size())
        {
            prix.push_back(historique[i]);
            i++;
        }
    }
    return prix;
}

//Test Bourse Vecteur:

void TestBourseVecteur::getActionsDisponibleParDate_DateExistante()
{
    bool test;
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    Date d(12,1,2023);
    BourseVecteur b(d1, v);
    vector<string> nom=b.getActionsDisponibleParDate(d);
    test=(nom.size()==3) && (nom[0]=="a") && (nom[1]=="b") && (nom[2]=="c");
    if (test)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getActionsDisponibleParDate pour une date existante"<<endl;
}

void TestBourseVecteur::getActionsDisponibleParDate_DateNonExistante()
{
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    BourseVecteur b(d1, v);
    vector<string> nom=b.getActionsDisponibleParDate(d1);
    if (nom.size()==0)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getActionsDisponibleParDate pour une non date existante"<<endl;

}

void TestBourseVecteur::getPrixJournalierParDate_DateExistante()
{
    bool test, test1, test2, test3;
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    Date d(12,1,2023);
    BourseVecteur b(d1, v);
    vector<PrixJournalier> prix=b.getPrixJournalierParDate(d);
    test1=(prix[0].getNom()=="a")&& (prix[0].getPrix()==10.5)&& (prix[0].getDate()==d);
    test2=(prix[1].getNom()=="b")&& (prix[1].getPrix()==11.5)&& (prix[1].getDate()==d);
    test3=(prix[2].getNom()=="c")&& (prix[2].getPrix()==15)&& (prix[2].getDate()==d);
    test=(prix.size()==3)&& test1 && test2 && test3;
    if (test)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getPrixJournalierParDate pour une date existante"<<endl;
}

void TestBourseVecteur::getPrixJournalierParDate_DateNonExistante()
{
    bool test;
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    BourseVecteur b(d1, v);
    vector<PrixJournalier> prix=b.getPrixJournalierParDate(d1);
    if (prix.size()==0)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getPrixJournalierParDate pour une date non existante"<<endl;
}
