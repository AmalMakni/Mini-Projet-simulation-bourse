#include <iostream>
#include <string>
#include <sstream>
#include "date.h"
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
bool Date::operator<(Date const &b)
{
    int test=b.jour+100*b.mois+10000*b.annee-(jour+100*mois+10000*annee);
    if (test>0)
        return true;
    else
        return false;
}

bool Date::operator==(Date const &d)
{
    if (jour==d.jour && mois==d.mois && annee==d.annee)
        return true;
    else
        return false;
}

void TestDate::incrementerDate()
{
    Date d(8,4,2023);
    d.incrementrerDate();
    Date d1(9,4,2023);
    string message="echec incrementation " ;
    verifier(d,d1,message);
}
void TestDate::incrementerDate_finDuMois31()
{
    Date d(31,3,2023);
    d.incrementrerDate();
    Date d1(1,4,2023);
    string message="echec incrementation fin mois 31 " ;
    verifier(d,d1,message);
}
void TestDate::incrementerDate_finDuMois30()
{
    Date d(30,4,2023);
    d.incrementrerDate();
    Date d1(1,5,2023);
    string message="echec incrementation fin mois 30 " ;
    verifier(d,d1,message);
}
void TestDate::incrementerDate_finDuMois_fevrier_28()
{
    Date d(28,2,2023);
    d.incrementrerDate();
    Date d1(1,3,2023);
    string message="echec incrementation fin fevrier non bissextile " ;
    verifier(d,d1,message);
}
void TestDate::incrementerDate_finDuMois_fevrier_29()
{
    Date d(28,2,2024);
    d.incrementrerDate();
    Date d1(29,2,2024);
    string message="echec incrementation fin fevrier bissextile" ;
    verifier(d,d1,message);
}
void TestDate::incrementerDate_finAnnee()
{
    Date d(31,12,2023);
    d.incrementrerDate();
    Date d1(1,1,2024);
    string message="echec incrementation fin annee " ;
    verifier(d,d1,message);
}
void TestDate::initialiserDate_chaine1()
{
    Date d("01/03/2023");
    Date d1(1,3,2023);
    string message="echec initialition a partir d une chaine " ;
    verifier(d,d1,message);
}
void TestDate::initialiserDate_chaine2()
{
    Date d("1/3/2023");
    Date d1(1,3,2023);
    string message="echec initialition a partir d une chaine sans 0 " ;
    verifier(d,d1,message);
}
void TestDate::inferieur()
{
    Date d1(9, 4, 2023), d2(10,4,2023);
    if (d1<d2)
        cout<<"Succes"<<endl;
    else
        cout<<"inferieur : Echec"<<endl;
}
void TestDate::verifier(Date d1, Date d2, string message)
{
    if (!(d1==d2))
        cout << message << endl ;
    else
        cout << "succes" << endl ;
}
ostream& operator<<(ostream& flux, Date const &d)
{
    flux<<d.jour<<"/"<<d.mois<<"/"<<d.annee;
    return flux;
}
istream& operator>>(istream& flux, Date d)
{

}
