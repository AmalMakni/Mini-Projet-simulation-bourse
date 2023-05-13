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
#include "Menu.h"

using namespace std;

//Test Unitaires Date

//int main()
//{
//    cout<<"Tests Date:"<<endl;
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
//    Date d(1, 1, 2016);
//    cout<<d.dateValide()<<endl;
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

//TEST BOURSEMULTISET:
//int main()
//{
//    Date d1(2,12,2015), d2(17,12,2015), d3(1,12,2015);
//    PersistancePrixJournaliers p;
//    vector<PrixJournalier> v=p.lirePrixJournaliersDUnFichier
//    ("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\prices_simple.csv");
//    BourseMultiSet b(d1, v);
//    //vector<string> actionDispo=b.getActionsDisponibleParDateParPrix(d1, 100);
//    //cout<<actionDispo.size()<<endl;
//    //vector < PrixJournalier> prix = b.getPrixJournalierParDateParPrix(d1,100);
//    //PrixJournalier pj(d1, "", 0);
////    for(auto s: prix)
////        cout<<s.getNom()<<","<<s.getDate()<<","<< s.getPrix()<<"; "<<endl;
//        //cout<<s<<"; ";
//    PrixJournalier t=b.getPrixJournalierLePlusRecent("JPM", d3);
//    PrixJournalier t2=b.getPrixJournalierLePlusRecentV2("JPM", d3);
//
//    cout<<t.getNom()<<","<<t.getDate()<<","<<t.getPrix();
//    cout<<t2.getNom()<<","<<t2.getDate()<<","<<t2.getPrix();
//    return 0;
//}

//TEST BOURSE MULTIMAP
//int main()
//{
//    return 0;
//}

//TEST SIMULATION
int main()
{
    srand(time(NULL));
    //srand(1);
    PersistancePrixJournaliers p;
    Trader * t;
    Bourse *b;
    t= new TraderAleatoir2;
    TraderAleatoir2 trader2;
    TraderAleatoir1 trader;
    TraderMovingAverage2 trader3;
    TraderMovingAverage trader4;
    TraderComparaison trader5;

    //Date d1(2,12,2015), d2(17,12,2015);

    Date d1(4,1,2010), d2(6,9,2010);

    vector<PrixJournalier> v=p.lirePrixJournaliersDUnFichier
    ("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\prices_simple.csv");
    BourseVecteurOptimisee b2(d1,v);
    b= new BourseVecteurOptimisee(d1,v);
//    vector<PrixJournalier> historiqueAction=b2.getHistoriqueParAction("NKE");
//    for(auto pj: historiqueAction)
//    {
//        cout<<pj.getNom()<<","<<pj.getDate()<<","<<pj.getPrix()<<endl;
//    }
//    cout<<"***"<<endl;
    BourseVecteur b1(d1,v);
    BourseMultiSet b3(d1, v);
    BourseMultiMap b4(d1, v);
    //Portefeuille porte(100);
    //auto stats = Simulation::executer(b2, trader2, d1, d2, 100);
    auto stats = Simulation::executer(b4, trader2, d1, d2, 1000);
    for(auto it:stats){cout<<it.first<<"\t"<<it.second<<endl;}
    //double m=b2.movingAverage("JEC", 3);
}
// test menu
//int main (){
//
//    Date datedebut ;
//    Date datefin ;
//    Menu menu ;
//    Bourse * b;
//    Trader * t;
//    double budget;
//    PersistancePrixJournaliers p;
//    vector<PrixJournalier> v=p.lirePrixJournaliersDUnFichier
//   ("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\simulationBourse\\prices_simple.csv");
//    int choix;
//    do{
//            if((choix=menu.menuGeneral())<0)
//                exit(1);
//
//            switch (choix){
//                case 1:
//                    do {
//                        cout << " entrer votre date de debut sous la forme \"jj/mm/aaaa\" : ";
//                        string date;
//                        //cin >> datedebut;
//                        cin>>date;
//                        Date d1(date);
//                        datedebut=d1;
//                    }while(datedebut.dateValide()== false);
//                    cout << " saisie date check "  ;
//                    system("pause");
//                    break;
//                case 2:
//                    do {
//                        //cout<<datedebut<<endl;
//                        cout << " entrer votre date de fin sous la forme \"jj/mm/aaaa\" : ";
//                        //cin >> datefin ;
//                        string date;
//                        //cin >> datedebut;
//                        cin>>date;
//                        Date d1(date);
//                        datefin=d1;
//                        if(datefin<datedebut)
//                            cout<<"La date de debut est superieure a celle de fin. Veuillez reessayer."<<endl;
//                    }while(datefin.dateValide()== false || datefin<datedebut );
//                    cout << " case2  check " ;
//                    system("pause");
//                    break;
//                case 3:
//                    //menu.choixBourse(v,datedebut);
//                    choix=menu.menuBourse();
//                    switch(choix){
//                        case 1:
//                            b= new BourseVecteur(datedebut, v);
//                            break;
//                        case 2:
//                            b= new BourseMultiSet(datedebut, v);
//                            break;
//                        case 3:
//                            b= new BourseMultiMap(datedebut,v);
//                    }
//                    cout<<b->getDateAujourdhui();
//                    cout << " case3  check " ;
//                    system("pause");
//                    break;
//                case 4:
//                    choix=menu.menuTrader();
//                    switch(choix){
//                        case 1:
//                            t= new TraderAleatoir2;
//                            break;
//                        case 2:
//                            t= new TraderMovingAverage2;
//                            break;
//                        case 3:
//                            t= new TraderComparaison;
//                    }
//                    cout << " case3  check " ;
//                    system("pause");
//                    break ;
//                case 5:
//                    do{
//                        cout << "Saisir le budget de la simulation: " ;
//                        cin>>budget;
//                        if(budget<0)
//                            cout<<"Veuillez entrer un solde positif:";
//
//                    }while(budget<0);
//
//
//                    system("pause");
//                    break ;
//                case 6:
//                    srand(1);
//                    //cout << " case6  check " ;
//                    auto stats=Simulation::executer(*b, *t, datedebut, datefin, budget);
//                    for(auto it:stats){cout<<it.first<<"\t"<<it.second<<endl;}
//                    system("pause");
//                    break ;
//            }
//
//    }while(choix != 7);
//
//
//    return 0;
//}
