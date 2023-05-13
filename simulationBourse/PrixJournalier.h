#ifndef PRIXJOURNALIER_H_INCLUDED
#define PRIXJOURNALIER_H_INCLUDED

#include "date.h"

class PrixJournalier
{
    private:
        Date date;
        string nomAction;
        double prix;
    public:
        PrixJournalier(){};
        PrixJournalier(Date d, string nom  , double p) : date(d), nomAction(nom), prix(p) {};
        Date getDate() const;
        string getNom() const;
        double getPrix() const;
        friend istream& operator>>(istream& flux, PrixJournalier& pj);
        bool operator<(PrixJournalier const &p)const {return (date<p.date);};
        bool operator>(PrixJournalier const &p)const {return (p.date<date);};

};



#endif // PRIXJOURNALIER_H_INCLUDED
