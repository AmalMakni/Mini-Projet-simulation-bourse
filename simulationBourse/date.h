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
        bool estuneanneebisextile () const;
        //bool dateValide();
        int NbrJourDuMois () const;
    public :
        Date ( int j , int m , int a );
        Date(string date);
        Date();
        void incrementerDate ();
        void afficher ();
        int getJour() const;
        int getMois() const;
        int getAnnee() const;
        bool dateValide() const;
        bool operator<(Date const &b) const;
        bool operator==(Date const &d) const;
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
