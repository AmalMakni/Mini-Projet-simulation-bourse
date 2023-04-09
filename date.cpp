#include <iostream>
#include <string>
#include <sstream>
#include "date.h"
//test
using namespace std ;
int Date::getAnnee()
{
    return annee;
}
int Date::getMois()
{
    return mois;
}
int Date::getJour()
{
    return jour;
}

bool Date::estuneanneebisextile()
{
    if (annee % 400 == 0 )
        return true ;
    if (annee % 100 == 0)
        return false;
    if (annee % 4 == 0)
        return true ;
    return false ;
}
int Date::NbrJourDuMois()
{
    if (mois == 2)
    {if (estuneanneebisextile())
            return 29;
     else
        return 28 ;
     }
    else if (mois == 4|| mois ==6 || mois == 9 || mois == 11  )
        return 30 ;
    else
        return 31 ;
}

Date :: Date(int j , int m , int a): jour(j),mois(m),annee(a)
{

}
Date :: Date(string date )
{
    stringstream ss(date);
    string registre ;
    getline(ss,registre,'/');
    jour=stoi(registre);
    getline(ss,registre,'/');
    mois=stoi(registre);
    getline(ss,registre,'/');
    annee=stoi(registre);
}
void Date::incrementrerDate()
{
   int dd = NbrJourDuMois();
   // fin d'annee
   if ( jour== dd && mois==12 )
   {
     jour = 1 ;
     mois = 1 ;
     annee++;
   }
   else if (jour==dd)
   {
       jour=1;
       mois++;
   }
   else
        jour++;
}
void Date::afficher()
{
    cout << jour << "/"<< mois<<"/"<<annee;
}
//la date plus ancienne est considérée inférieure à la date la plus récente
bool operator<(Date const &a, Date const& b)
{
    int test=b.jour+100*b.mois+10000*b.annee-(a.jour+100*a.mois+10000*a.annee);
    if (test>0)
        return true;
    else
        return false;
}

void TestDate::incrementerDate()
{
    Date d(8,4,2023);
    d.incrementrerDate();
    if (d.getJour()==9 && d.getMois()==4 && d.getAnnee()==2023)
        cout<<"Test 1: Succes"<<endl;
    else
        cout<<"Test 1: Echec"<<endl;
}
void TestDate::incrementerDate_finDuMois31()
{
    Date d(31,3,2023);
    d.incrementrerDate();
    if (d.getJour()==1 && d.getMois()==4 && d.getAnnee()==2023)
        cout<<"Test 3: Succes"<<endl;
    else
        cout<<"Test 3: Echec"<<endl;
}
void TestDate::incrementerDate_finDuMois30()
{
    Date d(30,4,2023);
    d.incrementrerDate();
    if (d.getJour()==1 && d.getMois()==5 && d.getAnnee()==2023)
        cout<<"Test 2: Succes"<<endl;
    else
        cout<<"Test 2: Echec"<<endl;
}
void TestDate::incrementerDate_finDuMois_fevrier_28()
{
    Date d(28,2,2023);
    d.incrementrerDate();
    if (d.getJour()==1 && d.getMois()==3 && d.getAnnee()==2023)
        cout<<"Test 4: Succes"<<endl;
    else
        cout<<"Test 4: Echec"<<endl;
}
void TestDate::incrementerDate_finDuMois_fevrier_29()
{
    Date d(28,2,2024);
    d.incrementrerDate();
    if (d.getJour()==29 && d.getMois()==2 && d.getAnnee()==2024)
        cout<<"Test 5: Succes"<<endl;
    else
        cout<<"Test 5: Echec"<<endl;
}
void TestDate::incrementerDate_finAnnee()
{
    Date d(31,12,2023);
    d.incrementrerDate();
    if (d.getJour()==1 && d.getMois()==1 && d.getAnnee()==2024)
        cout<<"Test 6: Succes"<<endl;
    else
        cout<<"Test 6: Echec"<<endl;
}
void TestDate::initialiserDate_chaine1()
{
    Date d("01/03/2023");
    if (d.getJour()==1 && d.getMois()==3 && d.getAnnee()==2023)
        cout<<"Test 7: Succes"<<endl;
    else
        cout<<"Test 7: Echec"<<endl;
}
void TestDate::initialiserDate_chaine2()
{
    Date d("1/3/2023");
    if (d.getJour()==1 && d.getMois()==3 && d.getAnnee()==2023)
        cout<<"Test 8: Succes"<<endl;
    else
        cout<<"Test 8: Echec"<<endl;
}
void TestDate::superieur()
{
    Date d1(9, 4, 2023), d2(10,4,2023);
    if (d1<d2)
        cout<<"Test 9: Succes"<<endl;
    else
        cout<<"Test 9: Echec"<<endl;
}
