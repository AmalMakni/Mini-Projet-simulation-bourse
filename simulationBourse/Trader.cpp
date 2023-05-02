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
            Transaction tx(achat, "", -1);
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
                Transaction tx(achat, "", -1);
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
