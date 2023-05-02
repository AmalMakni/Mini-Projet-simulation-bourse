#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED

#include <iostream>
#include "date.h"
#include <vector>
#include "PrixJournalier.h"

class Bourse{
    protected :
        Date dateAujourdhui;
    public :
        Bourse (Date date );
        virtual void setDateAujourdhui(Date)=0;
        virtual vector<string> getActionsDisponibleParDate(Date) const =0 ;
        virtual vector<PrixJournalier> getPrixJournalierParDate(Date) const =0 ;
        virtual vector<string> getActionsDisponibleAujourdhui() const =0;
        virtual vector<PrixJournalier> getPrixJournalierAujourdhui() const =0;
        virtual vector<PrixJournalier> getPrixJournalierParDateParPrix(Date, double) const =0;
        virtual vector<string> getActionsDisponibleParDateParPrix(Date, double) const =0;
        virtual vector<string> getActionsDisponibleAujourdhuiParPrix(double budget) const {return getActionsDisponibleParDateParPrix(dateAujourdhui, budget);};
        virtual vector<PrixJournalier> getPrixJournalierAujourdhuiParPrix(double budget) const {return getPrixJournalierParDateParPrix(dateAujourdhui, budget);};
        virtual PrixJournalier getPrixJournalierLePlusRecent(string nom, Date dateFin) const=0;
};

class BourseVecteur : public Bourse {
    private :
        vector<PrixJournalier> historique  ;
    public :
        BourseVecteur (Date date , vector<PrixJournalier> pj);
        void setDateAujourdhui(Date);
        vector<string> getActionsDisponibleParDate(Date) const;
        vector<PrixJournalier> getPrixJournalierParDate(Date) const;
        vector<string> getActionsDisponibleAujourdhui() const;
        vector<PrixJournalier> getPrixJournalierAujourdhui() const;
        vector<PrixJournalier> getPrixJournalierParDateParPrix(Date, double) const;
        vector<string> getActionsDisponibleParDateParPrix(Date, double) const;
        PrixJournalier getPrixJournalierLePlusRecent(string nom, Date dateFin) const;
};

class BourseVecteurOptimisee : public Bourse {
    private :
        vector<PrixJournalier> historique  ;
    public :
        BourseVecteurOptimisee (Date date , vector<PrixJournalier> pj);
        void setDateAujourdhui(Date);
        vector<string> getActionsDisponibleParDate(Date) const;
        vector<PrixJournalier> getPrixJournalierParDate(Date) const;
        vector<string> getActionsDisponibleAujourdhui() const;
        vector<PrixJournalier> getPrixJournalierAujourdhui() const;
        vector<PrixJournalier> getPrixJournalierParDateParPrix(Date, double) const;
        vector<string> getActionsDisponibleParDateParPrix(Date, double) const;
        PrixJournalier getPrixJournalierLePlusRecent(string nom, Date dateFin) const;
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
