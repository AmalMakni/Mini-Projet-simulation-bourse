#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>

using namespace std ;

class Date
{
    private :
        int jour;
        int mois;
        int annee;
        bool estuneanneebisextile ();
        int NbrJourDuMois ();
    public :
        Date ( int j , int m , int a );
        Date(string date);
        Date();
        void incrementrerDate ();
        void afficher ();
        int getJour();
        int getMois();
        int getAnnee();
        bool operator<(Date const &b);
        bool operator==(Date const &d);
        friend ostream& operator<<(ostream& flux, Date const &d);
        friend istream& operator>>(istream& flux, Date& d);
};
class TestDate
{
    public:
        void incrementerDate();
        void incrementerDate_finDuMois30();
        void incrementerDate_finDuMois31();
        void incrementerDate_finDuMois_fevrier_28();
        void incrementerDate_finDuMois_fevrier_29();
        void incrementerDate_finAnnee();
        void initialiserDate_chaine1();
        void initialiserDate_chaine2();
        void inferieur();
        void verifier (Date d1, Date d2, string msessage);
};



#endif // DATE_H_INCLUDED
