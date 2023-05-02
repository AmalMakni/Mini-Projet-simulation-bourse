#include <iostream>
#include<vector>
#include<fstream>
#include <stdlib.h>
#include <time.h>

#include "date.h"
#include "PrixJournalier.h"
#include "Bourse.h"
#include "PersistancePrixJournalier.h"
#include "Transaction.h"
#include "Titre.h"
#include "Portefeuille.h"
#include "Trader.h"
#include "Simulation.h"

using namespace std;

//Test Unitaires Date

//int main()
//{
    //cout<<"Tests Date:"<<endl;
//    TestDate t;
//    t.incrementerDate();
//    t.incrementerDate_finDuMois30();
//    t.incrementerDate_finDuMois31();
//    t.incrementerDate_finDuMois_fevrier_28();
//    t.incrementerDate_finDuMois_fevrier_29();
//    t.incrementerDate_finAnnee();
//    t.initialiserDate_chaine1();
//    t.initialiserDate_chaine2();
//    t.inferieur();
//    return 0;
//}

//TESTS UNITAIRES PRIXJOURNALIER
//int main()
//{
//    cout<<"Test Prix Journalier:"<<endl;
//    cin>>d1;
//    cout<<d1;
//    PrixJournalier pj;
//    cin>>pj;
//    cout<<"le prix journalier est"<<endl;
//    cout<<pj.getDate()<<endl;
//    cout<<pj.getNom()<<endl<<pj.getPrix();
//    return 0;
//}

// TEST PERSISTANCEPRIXJOURNALIER
//int main()
//{
    //cout<<"Test Persistance Prix Journaliers:"<<endl;
//    PersistancePrixJournaliers p;
//    vector<PrixJournalier> v;
//    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\test.csv");
//    //v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\prices_simple.csv");
//    for (int i=0;i<v.size();i++){
//        cout<<"le prix journalier est"<<endl;
//        cout<<v[i].getDate()<<","<<v[i].getNom()<<","<<v[i].getPrix()<<endl;
//    }
//    return 0;
//}

////Tests Unitaires Bourse Vecteur
//int main()
//{
////    cout<<"Test Bourse Vecteur:"<<endl;
////    TestBourseVecteur tbv;
////    tbv.getActionsDisponibleParDate_DateExistante();
////    tbv.getActionsDisponibleParDate_DateNonExistante();
////    tbv.getPrixJournalierParDate_DateExistante();
////    tbv.getPrixJournalierParDate_DateNonExistante();
//    Date d1(2, 12, 2015);
//    //Date d1(12, 1, 2023);
//    PersistancePrixJournaliers p;
//    vector<PrixJournalier> v;
//    //v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\test.csv");
//    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\prices_simple.csv");
//    cout<<"nombre de pj: "<<v.size()<<endl;
////    for (int i=0;i<v.size();i++){
////        cout<<"le prix journalier est"<<endl;
////        cout<<v[i].getDate()<<","<<v[i].getNom()<<","<<v[i].getPrix()<<endl;
////    }
//    Date d(2,12,2015);
//    BourseVecteur b1(d1, v);
//    BourseVecteurOptimisee b2(d1,v);
//    vector<string> nom=b2.getActionsDisponibleParDateParPrix(d,100);
//    //vector<string> nom=b2.getActionsDisponibleParDate(d);
//    //vector<string> nom=b1.getActionsDisponibleAujourdhui();
//    //vector<PrixJournalier> prix=b1.getPrixJournalierParDate(d);
//    vector<PrixJournalier> prix=b2.getPrixJournalierParDateParPrix(d,100);
//    //vector<PrixJournalier> prix=b1.getPrixJournalierAujourdhui();
//    cout<<"nb de pj dispo 2/12/2015: "<< nom.size()<<endl;
//     for (unsigned int i=0;i<nom.size();i++){
//        cout<<nom[i]<<";";
//    }
////    for (int i=0;i<prix.size();i++)
////        cout<<prix[i].getDate()<<","<<prix[i].getNom()<<","<<prix[i].getPrix()<<";";
//    //TEST PORTEFEUILE
//    Portefeuille porte(100);
//    cout<<endl<<porte.getSolde()<<","<<porte.getTitres().size();
//
//    return 0;
//}

//Test transaction:
//int main()
//{
//    cout<<"Test transaction:"<<endl;
//    TestTransaction ttx;
//    ttx.initialiserTransaction();
//
//    return 0;
//}
//
//test Titre
//int main()
//{
//    cout<<"Test titre:"<<endl;
//    TestTitre tt;
//    tt.initialiserTitre();
//
//    return 0;
//}

//TEST PORTEFEUILLE
//int main()
//{
//    Portefeuille p(1000);
//    p.acheterAction("abc", 5, 10.5);
//    cout<<p.getSolde()<<endl;
//    p.acheterAction("abc", 5, 10.5);
//    p.acheterAction("def", 2, 12.5);
//    p.vendreAction("abc", 10, 22);
//    vector<Titre> v=p.getTitres();
//    for(auto pj: v)
//        cout<<pj.getNomAction()<<","<<pj.getQuantite()<<endl;
//
//}

//TEST TRADER
//int main ()
//{
//    srand(time(NULL));
//    //srand(7);
//    PersistancePrixJournaliers p;
//    vector<PrixJournalier> v;
//    //v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\test.csv");
//    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\prices_simple.csv");
//    //cout<<v.size()<<endl;
//    //Date d1(12, 1, 2023);
//    Date d1(2,12,2015);
//    BourseVecteur b1(d1, v);
//    BourseVecteurOptimisee b2(d1,v);
//    Portefeuille porte(100);
//    TraderAleatoir1 trader;
//    Transaction transaction=trader.choisirTransaction(b2, porte);
//    cout<<transaction.getNomAction()<<","<<transaction.getType()
//    <<","<<transaction.getQuantite()<<endl;
//    TraderAleatoir2 trader2;
//    transaction=trader2.choisirTransaction(b2, porte);
//    cout<<transaction.getNomAction()<<","<<transaction.getType()
//    <<","<<transaction.getQuantite();
//    return 0;
//}

//TEST SIMULATION
int main()
{
    //srand(time(NULL));
    srand(1);
    PersistancePrixJournaliers p;
    TraderAleatoir2 trader2;
    TraderAleatoir1 trader;
    Date d1(2,12,2015), d2(17,12,2015);

    vector<PrixJournalier> v=p.lirePrixJournaliersDUnFichier
    ("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\prices_simple.csv");
    BourseVecteurOptimisee b2(d1,v);
    BourseVecteur b1(d1,v);
    //Portefeuille porte(100);
    auto stats = Simulation::executer(b2, trader2, d1, d2, 100);
    for(auto it:stats){   cout<<it.first<<"\t"<<it.second<<endl; }

}
