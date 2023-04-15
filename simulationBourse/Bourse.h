#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED

#include <iostream>
#include "date.h"
#include <vector>
#include "PrixJournalier.h"

class Bourse{
    private :
        Date dateFinRecherche ;
    public :
        Bourse (Date date );
        virtual vector<string> getActionsDisponibleParDate(Date)=0;
        virtual vector<double> getPrixJournalierParDate(Date)=0;
};

class BourseVecteur : public Bourse {
    private :
        vector<PrixJournalier> historique  ;
    public :
        BourseVecteur (Date date , vector<PrixJournalier> pj);
        vector<string> getActionsDisponibleParDate(Date);
        vector<double> getPrixJournalierParDate(Date);


};

class TestBourseVecteur
{
    public:
        void getActionsDisponibleParDate_DateExistante();
        void getActionsDisponibleParDate_DateNonExistante();
        void getPrixJournalierParDate_DateExistante();
        void getPrixJournalierParDate_DateNonExistante();
};

#endif // BOURSE_H_INCLUDED
