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
        Date getDate() const;
        string getNom() const;
        double getPrix() const;
        friend istream& operator>>(istream& flux, PrixJournalier& pj);

};



#endif // PRIXJOURNALIER_H_INCLUDED
