#include <iostream>
#include<vector>
#include<fstream>

#include "date.h"
#include "PrixJournalier.h"
#include "Bourse.h"
#include "PersistancePrixJournalier.h"
#include "Transaction.h"
#include "Titre.h"

using namespace std;

int main()
{
    //Test Unitaires Date
    TestDate t;
    t.incrementerDate();
    t.incrementerDate_finDuMois30();
    t.incrementerDate_finDuMois31();
    t.incrementerDate_finDuMois_fevrier_28();
    t.incrementerDate_finDuMois_fevrier_29();
    t.incrementerDate_finAnnee();
    t.initialiserDate_chaine1();
    t.initialiserDate_chaine2();
    t.inferieur();
    //Tests Unitaires Bourse Vecteur
    cout<<"Test Bourse Vecteur:"<<endl;
    TestBourseVecteur tbv;
    tbv.getActionsDisponibleParDate_DateExistante();
    tbv.getActionsDisponibleParDate_DateNonExistante();
    tbv.getPrixJournalierParDate_DateExistante();
    tbv.getPrixJournalierParDate_DateNonExistante();
    //Test transaction:
    TestTransaction ttx;
    ttx.initialiserTransaction();
    //test Titre
    TestTitre tt;
    tt.initialiserTitre();

    Date d1(9, 4, 2023);

//    cin>>d1;
//    cout<<d1;
//    PrixJournalier pj;
//    cin>>pj;
//    cout<<"le prix journalier est"<<endl;
//    cout<<pj.getDate()<<endl;
//    cout<<pj.getNom()<<endl<<pj.getPrix();
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\test.csv");
    //v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\prices_simple.csv");
    for (int i=0;i<v.size();i++){
        cout<<"le prix journalier est"<<endl;
        cout<<v[i].getDate()<<","<<v[i].getNom()<<","<<v[i].getPrix()<<endl;
    }
    Date d(15,2,2023);
    BourseVecteur b1(d1, v);
    BourseVecteurOptimisee b2(d1,v);
    //vector<string> nom=b1.getActionsDisponibleParDate(d);
    vector<string> nom=b2.getActionsDisponibleParDate(d);
    //vector<PrixJournalier> prix=b1.getPrixJournalierParDate(d);
    vector<PrixJournalier> prix=b2.getPrixJournalierParDate(d);
     for (int i=0;i<nom.size();i++){
        cout<<nom[i]<<";";
    }
    for (int i=0;i<prix.size();i++)
        cout<<prix[i].getDate()<<","<<prix[i].getNom()<<","<<prix[i].getPrix()<<";";

    return 0;
}
