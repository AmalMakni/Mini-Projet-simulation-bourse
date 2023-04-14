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
        Date getDate();
        string getNom();
        double getPrix();
        friend istream& operator>>(istream& flux, PrixJournalier& pj);

};



#endif // PRIXJOURNALIER_H_INCLUDED
