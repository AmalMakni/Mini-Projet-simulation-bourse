#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
using namespace std ;
class Date
{
    private :
        int jour ;
        int mois ;
        int annee ;
        bool estuneanneebisextile ();
        int NbrJourDuMois ();
    public :
        Date ( int j , int m , int a );
        Date(std::string date);
        void incrementrerDate ();
        void afficher ();
        int getJour();
        int getMois();
        int getAnnee();
        friend bool operator<(Date const &a, Date const& b);
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
        void superieur();
};


#endif // DATE_H_INCLUDED
