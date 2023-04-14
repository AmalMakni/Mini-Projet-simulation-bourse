#include <iostream>
#include "date.h"
#include "PrixJournalier.h"
#include<vector>
#include<fstream>
#include "PersistancePrixJournalier.h"

using namespace std;

int main()
{
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
    Date d1(9, 4, 2023);

//    cin>>d1;
//    cout<<d1;
    PrixJournalier pj;
    cin>>pj;
    cout<<"le prix journalier est"<<endl;
    cout<<pj.getDate()<<endl;
    cout<<pj.getNom()<<endl<<pj.getPrix();
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Documents\\2022-2023\\MP C++\\Mini-Projet-simulation-bourse\\test.csv");
    for (int i=0;i<3;i++){
        cout<<"le prix journalier est"<<endl;
        cout<<v[i].getDate()<<endl;
        cout<<v[i].getNom()<<endl<<v[i].getPrix();
    }


    return 0;
}
