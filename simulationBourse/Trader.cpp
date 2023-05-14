#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "Trader.h"
#include "Transaction.h"
#include "Bourse.h"
#include "Portefeuille.h"
#include "Titre.h"

//Transaction TraderAleatoir1::choisirTransaction (const Bourse& bourse, const Portefeuille &portefeuille)
//{
//    TypeTransaction type = static_cast<TypeTransaction>(rand()%3);
//    if (type == achat)
//    {
//        vector <string> actionsDisponibles = bourse.getActionsDisponibleAujourdhui();
//        cout<<actionsDisponibles.size()<<endl;
//        int positionAction =rand()%actionsDisponibles.size();
//        string nom=bourse.getActionsDisponibleAujourdhui()[positionAction];
//        PrixJournalier pj=bourse.getPrixJournalierAujourdhui()[positionAction];
//        int quantite=1+(rand()% static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix())));
//        Transaction tx (type, nom, quantite);
//        return tx;
//    }
//    else if (type == vente)
//    {
//        vector <Titre > titres=portefeuille.getTitres();
//        if (titres.size()>0)
//        {
//            int positionAction =rand()%titres.size();
//            int quantite=1+(rand()% titres[positionAction].getQuantite());
//            Transaction tx(type, titres[positionAction].getNomAction(), quantite);
//            return tx;
//        }
//        else
//        {
//            Transaction tx(type, "", 0);
//            return tx;
//        }
//    }
//    else
//    {
//        Transaction tx(type, "", 0);
//        return tx;
//    }
//
//}
//version optimisee
Transaction TraderAleatoir1::choisirTransaction (const Bourse& bourse, const Portefeuille &portefeuille)
{
    TypeTransaction type = static_cast<TypeTransaction>(rand()%3);
    if (type == achat)
    {
        vector <string> actionsDisponibles = bourse.getActionsDisponibleAujourdhuiParPrix(portefeuille.getSolde());
        //cout<<actionsDisponibles.size()<<endl;
        if (actionsDisponibles.size()!=0)
        {
            int positionAction =rand()%actionsDisponibles.size();
            string nom=actionsDisponibles[positionAction];
            PrixJournalier pj=bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde())[positionAction];
            int quantite=1+(rand()% static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix())));
            Transaction tx (type, nom, quantite);
            return tx;
        }
        else
        {
            Transaction tx(achat, "", -1);
            return tx;
        }
    }
    else if (type == vente)
    {
        vector <Titre > titres=portefeuille.getTitres();
        if (titres.size()>0)
        {
            int positionAction =rand()%titres.size();
            int quantite=1+(rand()% titres[positionAction].getQuantite());
            Transaction tx(type, titres[positionAction].getNomAction(), quantite);
            return tx;
        }
        else
        {
            Transaction tx(type, "", 0);
            return tx;
        }
    }
    else
    {
        Transaction tx(type, "", 0);
        return tx;
    }

}
//version non optimisee
//Transaction TraderAleatoir2::choisirTransaction (const Bourse& bourse, const Portefeuille &portefeuille)
//{
//    if (portefeuille.getTitres().empty())
//    {
//        vector <string> actionsDisponibles = bourse.getActionsDisponibleAujourdhui();
//        //cout<<actionsDisponibles.size()<<endl;
//        int positionAction =rand()%actionsDisponibles.size();
//        //cout<<positionAction<<endl;
//        string nom=bourse.getActionsDisponibleAujourdhui()[positionAction];
//        //cout<<nom<<endl;
//        PrixJournalier pj=bourse.getPrixJournalierAujourdhui()[positionAction];
//        //cout<<pj.getDate()<<","<<pj.getNom()<<","<<pj.getPrix()<<";";
//        //cout<<static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix()))<<endl;
//        int qmax=static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix()));
//        int quantite=0;
//        if (qmax>0)
//            quantite=1+(rand()% static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix())));
//
//        Transaction tx (achat, nom, quantite);
//        return tx;
//    }
//    else
//    {
//        TypeTransaction type = static_cast<TypeTransaction>(rand()%3);
//        if (type == achat)
//        {
//            vector <string> actionsDisponibles = bourse.getActionsDisponibleAujourdhui();
//            cout<<actionsDisponibles.size()<<endl;
//            int positionAction =rand()%actionsDisponibles.size();
//            string nom=bourse.getActionsDisponibleAujourdhui()[positionAction];
//            PrixJournalier pj=bourse.getPrixJournalierAujourdhui()[positionAction];
//            int qmax=static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix()));
//            int quantite=0;
//            if (qmax>0)
//                quantite=1+(rand()% static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix())));
//
//            Transaction tx (type, nom, quantite);
//            return tx;
//        }
//        else if (type == vente)
//        {
//            vector <Titre > titres=portefeuille.getTitres();
//            int positionAction =rand()%titres.size();
//            int quantite=1+(rand()% titres[positionAction].getQuantite());
//            Transaction tx(type, titres[positionAction].getNomAction(), quantite);
//            return tx;
//        }
//        else
//        {
//            Transaction tx(type, "", 0);
//            return tx;
//        }
//    }
//
//}

//Version optimisee
Transaction TraderAleatoir2::choisirTransaction (const Bourse& bourse, const Portefeuille &portefeuille)
{
    if (portefeuille.getTitres().empty())
    {
        vector <string> actionsDisponibles = bourse.getActionsDisponibleAujourdhuiParPrix(portefeuille.getSolde());
        //cout<<actionsDisponibles.size()<<endl;
        if (actionsDisponibles.size()!=0)
        {
             int positionAction =rand()%actionsDisponibles.size();
            //cout<<positionAction<<endl;
            string nom=actionsDisponibles [positionAction];
            //cout<<nom<<endl;
            PrixJournalier pj=bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde())[positionAction];
            int quantite=1+(rand()% static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix())));
            Transaction tx (achat, nom, quantite);
            return tx;
        }
        else
        {
            Transaction tx(achat, "", 0);
            return tx;
        }

    }
    else
    {
        TypeTransaction type = static_cast<TypeTransaction>(rand()%3);
        if (type == achat)
        {
            vector <string> actionsDisponibles = bourse.getActionsDisponibleAujourdhuiParPrix(portefeuille.getSolde());
            //cout<<actionsDisponibles.size()<<endl;
            if (actionsDisponibles.size()!=0)
            {
                int positionAction =rand()%actionsDisponibles.size();
                string nom=bourse.getActionsDisponibleAujourdhuiParPrix(portefeuille.getSolde())[positionAction];
                PrixJournalier pj=bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde())[positionAction];
                //cout<<positionAction<<","<<bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde()).size()<<endl;
                //cout<<nom<<","<<pj.getPrix()<<","<<static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix()))<<endl;
                int quantite=1+(rand()% static_cast <int> (floor(portefeuille.getSolde() / pj.getPrix())));

                Transaction tx (type, nom, quantite);
                return tx;
            }
            else
            {
                Transaction tx(achat, "", 0);
                return tx;
            }
        }
        else if (type == vente)
        {
            vector <Titre > titres=portefeuille.getTitres();
            if (titres.size()!=0)
            {
                int positionAction=rand()%titres.size();
                int quantite=1+(rand()% titres[positionAction].getQuantite());
                Transaction tx(type, titres[positionAction].getNomAction(), quantite);
                return tx;
            }
            else
            {
                Transaction tx(type, "", 0);
                return tx;
            }
        }
        else
        {
            Transaction tx(type, "", 0);
            return tx;
        }
    }

}

Transaction TraderMovingAverage::choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille)
{
    vector<Titre> titres=portefeuille.getTitres();
    if (titres.size()!=0)
    {
        cout<<"vente consideree"<<endl;
        //bool vendre=false;
        unsigned int i=0;
        //while(!vendre && i<titres.size())
        while(i<titres.size())
        {
            vector <PrixJournalier> historiqueAction=bourse.getHistoriqueParAction(titres[i].getNomAction());
            double m=0;
            for(auto pj: historiqueAction)
            {
                m+=pj.getPrix();
            }
            m=m/(historiqueAction.size());
            //cout<<titres[i].getNomAction()<<": "<<m<<endl;
            PrixJournalier pjAujourdhui=bourse.getPrixJournalierLePlusRecent(titres[i].getNomAction(), bourse.getDateAujourdhui());
            //cout<<pjAujourdhui.getNom()<<","<<pjAujourdhui.getPrix()<<","<<pjAujourdhui.getDate()<<endl;
            if(pjAujourdhui.getDate()==bourse.getDateAujourdhui() && pjAujourdhui.getPrix()<m)
            {
                Transaction tx(vente ,titres[i].getNomAction(), titres[i].getQuantite());
                //cout<<"Vente: "<<bourse.getDateAujourdhui()<<endl;
                return tx;
            }
            i++;
        }
    }
    vector<PrixJournalier> pjDispo=bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde());
    vector<double> movingAverages;
    if (pjDispo.size()!=0)
    {
        for (auto pj: pjDispo)
        {
            vector <PrixJournalier> historiqueAction=bourse.getHistoriqueParAction(pj.getNom());
            double m=0;
            for(auto p: historiqueAction)
            {
                m+=p.getPrix();
            }
            if (historiqueAction.size()!=0)
                m=m/(historiqueAction.size());
            movingAverages.push_back(pj.getPrix()-m);
        }
        unsigned int j=0;
        unsigned int maximum=0;
        for (j=0;j<movingAverages.size(); j++)
        {
            if(movingAverages[j]>movingAverages[maximum])
                maximum=j;
        }
        if (movingAverages[maximum]>0)
        {
            int qte=floor(portefeuille.getSolde()/pjDispo[maximum].getPrix());
            Transaction tx(achat, pjDispo[maximum].getNom(), qte);
            //cout<<"achat: "<<bourse.getDateAujourdhui()<<endl;
            return tx;
        }
    }
    Transaction tx(rien, "", 0);
    return tx;


};

Transaction TraderMovingAverage2::choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille)
{
    Date d(4,1,2010);
    if(bourse.getDateAujourdhui()==d)
        {
            Transaction tx(rien, "", 0);
            return tx;

        }
    vector<Titre> titres=portefeuille.getTitres();
    if (titres.size()!=0)
    {
        //cout<<"vente consideree"<<endl;
        //bool vendre=false;
        unsigned int i=0;
        //while(!vendre && i<titres.size())
        while(i<titres.size())
        {
            //vector <PrixJournalier> historiqueAction=bourse.getHistoriqueParAction(titres[i].getNomAction());
            //change this:
            double m=bourse.movingAverage(titres[i].getNomAction(), 50);
            //cout<<titres[i].getNomAction()<<" moving average: "<<m<<endl;
            PrixJournalier pjAujourdhui=bourse.getPrixJournalierLePlusRecent(titres[i].getNomAction(), bourse.getDateAujourdhui());
            //cout<<pjAujourdhui.getNom()<<","<<pjAujourdhui.getPrix()<<","<<pjAujourdhui.getDate()<<endl;
            if(pjAujourdhui.getDate()==bourse.getDateAujourdhui() && pjAujourdhui.getPrix()<m)
            {
                Transaction tx(vente ,titres[i].getNomAction(), titres[i].getQuantite());
                //cout<<titres[i].getNomAction()<<"/moy: "<< m<<"/ pj Auj"<<pjAujourdhui.getPrix()<<"Vente: "<<bourse.getDateAujourdhui()<<endl;
                return tx;
            }
            i++;
        }
    }
    vector<PrixJournalier> pjDispo=bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde());
    vector<double> movingAverages;
    if (pjDispo.size()!=0)
    {
        for (auto pj: pjDispo)
        {
            //vector <PrixJournalier> historiqueAction=bourse.getHistoriqueParAction(pj.getNom());
            //cout<<pj.getNom()<<endl;
            double m=bourse.movingAverage(pj.getNom(), 50);
            //cout<<pj.getNom()<<": "<<m<<endl;
            movingAverages.push_back(pj.getPrix()-m);
        }
        unsigned int j=0;
        unsigned int maximum=0;
        for (j=0;j<movingAverages.size(); j++)
        {
            if(movingAverages[j]>movingAverages[maximum])
                maximum=j;
        }
        if (movingAverages[maximum]>0)
        {
            int qte=floor(portefeuille.getSolde()/pjDispo[maximum].getPrix());
            Transaction tx(achat, pjDispo[maximum].getNom(), qte);
            //cout<<"achat: "<<bourse.getDateAujourdhui()<<", MovingAaverage difference: "<<movingAverages[maximum]<<", nom: "<<pjDispo[maximum].getNom() <<endl;
            return tx;
        }
    }
    Transaction tx(rien, "", 0);
    return tx;


};

Transaction TraderComparaison::choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille)
{
//    Date d(19,10,2015);
//    if (bourse.getDateAujourdhui()==d)
//    {
//        Transaction tx(rien, "", 0);
//        return tx;
//    }
    Date d(4,1,2010);
    if (bourse.getDateAujourdhui()==d )
    {
        Transaction tx(rien, "", 0);
        return tx;
    }
    //if(bourse.getDateAujourdhui==d)
    vector<Titre> titres=portefeuille.getTitres();
    //cout<<bourse.getDateAujourdhui()<<endl;
    if(titres.size()>0)
    {
        for(auto t: titres)
        {
            PrixJournalier pjAujourdhui=bourse.getPrixJournalierLePlusRecent(t.getNomAction(), bourse.getDateAujourdhui());
            if(pjAujourdhui.getDate()==bourse.getDateAujourdhui())
            {
                PrixJournalier pjHier=bourse.getPrixJournalierLePlusRecentV2(t.getNomAction(), bourse.getDateAujourdhui());
                if (pjHier.getPrix()<pjAujourdhui.getPrix())
                {
                    //cout<<"vente"<<","<<t.getNomAction()<<","<< t.getQuantite();
                    Transaction tx(vente, t.getNomAction(), t.getQuantite());
                    return tx;
                }
                //else
//                int qte=floor(portefeuille.getSolde()/pjAujourdhui.getPrix());
//                Transaction tx(achat, t.getNomAction(), t.getQuantite());
//                return tx;
            }
        }
    }
    vector<PrixJournalier> pjDispo=bourse.getPrixJournalierAujourdhuiParPrix(portefeuille.getSolde());
    if (pjDispo.size()>0)
    {
        vector<double> differenceAujourdhuiHier;
        for (auto pj: pjDispo)
        {
            //cout<<pj.getNom()<<endl;
            PrixJournalier pjHier=bourse.getPrixJournalierLePlusRecentV2(pj.getNom(), bourse.getDateAujourdhui());
            differenceAujourdhuiHier.push_back(pjHier.getPrix()-pj.getPrix());
        }
        //cout<<differenceAujourdhuiHier.size()<<endl;
        unsigned int j=0;
        unsigned int maximum=0;
        for (j=0;j<differenceAujourdhuiHier.size(); j++)
        {
            if(differenceAujourdhuiHier[j]>differenceAujourdhuiHier[maximum])
                maximum=j;
        }
        if (differenceAujourdhuiHier[maximum]>0)
        {
            int qte=floor(portefeuille.getSolde()/pjDispo[maximum].getPrix());
            Transaction tx(achat, pjDispo[maximum].getNom(), qte);
            //cout<<"achat"<<","<<pjDispo[maximum].getNom()<<","<< qte;
            //cout<<"achat: "<<bourse.getDateAujourdhui()<<", MovingAaverage difference: "<<movingAverages[maximum]<<", nom: "<<pjDispo[maximum].getNom() <<endl;
            return tx;
        }
    }

    Transaction tx(rien, "", 0);
    return tx;




};
