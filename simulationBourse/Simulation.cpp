#include <iostream>
#include<chrono>
#include<map>

#include "date.h"
#include "Bourse.h"
#include "Trader.h"
#include "Portefeuille.h"
#include "Simulation.h"
#include "Transaction.h"


//void Simulation::executer(Bourse& b , Trader& t , Date dateDebut , Date dateFin , double solde)
//{
//    Transaction action ;
//    Date dateCourante=dateDebut;
//    b.setDateAujourdhui(dateCourante);
//    //cout<<dateCourante<<endl;
//    Portefeuille p(solde);
//    unsigned int i=0, j=0, k=0;
//
//    while (dateCourante<dateFin)
//    {
//        //unsigned int i=0, j=0, k=0;
//        //cout<<"test 1 passed"<<endl;
//        //i=0;
//        vector <PrixJournalier> pj=b.getPrixJournalierAujourdhui();
//        //cout<<pj.size()<<endl;
//        if (pj.size()!=0 )
//        {
//            //i=0;
//            //cout<<"test2 passed"<<endl;
//            do{
//                action=t.choisirTransaction(b,p);
//                //cout<<action.getNomAction()<<","<<action.getQuantite()<<","<<action.getType()<<",";
//                bool existe=false;
//                i++;
//                if (action.getType() == achat && action.getQuantite()>0)
//                {
//                    vector <PrixJournalier> pj=b.getPrixJournalierAujourdhui();
//                    while (pj[j].getNom()!=action.getNomAction() && j<pj.size())
//                    {
//                        if (pj[j].getNom()==action.getNomAction())
//                            existe=true;
//                        else
//                            j++;
//                    }
//
//                    if (action.getQuantite()*pj[j].getPrix()<=p.getSolde()&& existe)
//                        p.acheterAction(action.getNomAction(), action.getQuantite(),pj[j].getPrix());
//                }
//                else if (action.getType()==vente && action.getQuantite()>0)
//                {
//                    vector <PrixJournalier> pj=b.getPrixJournalierAujourdhui();
//                    while (pj[j].getNom()!=action.getNomAction() && j<pj.size())
//                        j++;
//                    vector <Titre > titres=p.getTitres();
//                    while( !existe && k< titres.size())
//                        if (titres[k].getNomAction()==action.getNomAction())
//                            existe=true;
//                        else
//                            k++;
//                    if (existe && titres[k].getQuantite()<=action.getQuantite())
//                            p.vendreAction(action.getNomAction(), action.getQuantite(),pj[j].getPrix());
//                }
//
//
//            }while(action.getType()!=rien && i<100);
//            //cout<<"nb transactions pour la date: "<<dateCourante<<": "<<i;
//        }
//        dateCourante.incrementerDate();
//        b.setDateAujourdhui(dateCourante);
//
//
//    }
//    cout<<p.getSolde();
//}
//
//void Simulation::executer(Bourse& b , Trader& t , Date dateDebut , Date dateFin , double solde)
//{
//    Date dateCourante=dateDebut;
//    b.setDateAujourdhui(dateCourante);
//    Transaction transaction;
//    Portefeuille portefeuille(solde);
//    int achatBloque=0, venteBloquee=0, nbTransactionsBloquee;
//    int nbAchat=0, nbVente=0, nbRien=0, nbTransactionsReussites=0;
//    int nbJoursBourseFermee=0;
//    while(dateCourante<dateFin)
//    {
//        cout<<dateCourante<<endl;
//        vector<PrixJournalier> pjDispo=b.getPrixJournalierAujourdhui();
//        int i=0;
//        unsigned int j=0, k=0;
//        bool existe=false, existe2=false;
//        if (pjDispo.size()!=0)
//        {
//            do{
//
//                transaction=t.choisirTransaction(b, portefeuille);
//                cout<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
//                j=0;
//                k=0;
//                //existe=false;
//                //existe2=false;
////                while ( j<pjDispo.size() && pjDispo[j].getNom()!=transaction.getNomAction())
////                {
////                        j++;
////                }
//                while ( j<pjDispo.size() && !existe && transaction.getType()!=rien)
//                {
//                    if(pjDispo[j].getNom()==transaction.getNomAction())
//                        existe=true;
//                    else
//                        j++;
//                }
//                //cout<<transaction.getNomAction()<<","<<pjDispo[j].getNom()<<","<<pjDispo[j].getPrix()<<endl;
//
//                if(transaction.getType()==achat)
//                {
//                    //cout<<pjDispo[j].getPrix()<<endl;
////                   if(transaction.getQuantite()>=0 && pjDispo[j].getNom()==transaction.getNomAction() && pjDispo[j].getPrix()*transaction.getQuantite()<=portefeuille.getSolde())
//                    if(transaction.getQuantite()>=0 && existe && pjDispo[j].getPrix()*transaction.getQuantite()<=portefeuille.getSolde())
//                        {
//                            portefeuille.acheterAction(transaction.getNomAction(), transaction.getQuantite(), pjDispo[j].getPrix());
//                            nbAchat++;
//                            cout<<transaction.getNomAction()<<","<<pjDispo[j].getNom()<<","<<pjDispo[j].getPrix()<<endl;
//                            //cout<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
//                        }
//                    else
//                        {
//                            achatBloque++;
//                            //cout<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
//                        }
//
//                }
//                else if (transaction.getType()==vente)
//                {
//                    vector <Titre> titresDispo=portefeuille.getTitres();
////                    while ( k<titresDispo.size() && titresDispo[k].getNomAction()!=transaction.getNomAction())
////                    {
////                        cout<<titresDispo[k].getNomAction()<<endl;
////                            k++;
////                    }
//                    while ( k<titresDispo.size() && !existe2)
//                    {
//                        cout<<titresDispo[k].getNomAction()<<endl;
//                        if (titresDispo[k].getNomAction()==transaction.getNomAction())
//                            existe2=true;
//                        else
//                            k++;
//                    }
//                    //cout<<existe2<<" "<< existe <<" "<<(transaction.getQuantite()<=titresDispo[k].getQuantite() )<<" "<<(transaction.getQuantite()>=0)<<endl;
//
//                    cout<<(titresDispo[k].getNomAction()==transaction.getNomAction())
//                       <<" "<< (pjDispo[j].getNom()==transaction.getNomAction())
//                       <<" "<<  (transaction.getQuantite()<=titresDispo[k].getQuantite()) <<" "<<  (transaction.getQuantite()>=0)<<endl;
////                    if((titresDispo[k].getNomAction()==transaction.getNomAction())
////                       && (pjDispo[j].getNom()==transaction.getNomAction())
////                       && transaction.getQuantite()<=titresDispo[k].getQuantite() && transaction.getQuantite()>=0)
//                    if(existe && existe2
//                       && transaction.getQuantite()<=titresDispo[k].getQuantite() && transaction.getQuantite()>=0)
//                    {
//                        portefeuille.vendreAction(transaction.getNomAction(), transaction.getQuantite(), pjDispo[j].getPrix());
//                        nbVente++;
//                    }
//
//                    else
//                        venteBloquee++;
//                }
//                else if (transaction.getType()==rien)
//                    nbRien++;
//                //existe=false;
//                //existe2=false;
//            }while(transaction.getType()!=rien && i<100);
//
//        }
//        else
//            nbJoursBourseFermee++;
//
//        dateCourante.incrementerDate();
//        b.setDateAujourdhui(dateCourante);
//    }
//
//    nbTransactionsBloquee=achatBloque+venteBloquee;
//    nbTransactionsReussites=nbAchat+nbVente+nbRien;
//    cout<<"nbTransactionsBloquee: "<<nbTransactionsBloquee<<endl;
//    cout<<"nbTransactionsReussites: "<<nbTransactionsReussites<<endl;
//    cout<<"nbVenteBloquee: "<<venteBloquee<<endl;
//    cout<<portefeuille.getSolde()<<endl;
//}

//VERSION1 SIMULATION (it works!)
//void Simulation::executer(Bourse& b , Trader& t , Date dateDebut , Date dateFin , double solde)
//{
//    Date dateCourante=dateDebut;
//    b.setDateAujourdhui(dateCourante);
//    Transaction transaction;
//    Portefeuille portefeuille(solde);
//    int achatBloque=0, venteBloquee=0, nbTransactionsBloquee;
//    int nbAchat=0, nbVente=0, nbRien=0, nbTransactionsReussites=0;
//    int nbJoursBourseFermee=0;
//    while(dateCourante<dateFin)
//    {
//        cout<<dateCourante<<endl;
//        vector<PrixJournalier> pjDispo=b.getPrixJournalierAujourdhui();
//        int i=0;
//        unsigned int j=0, k=0;
//        if (pjDispo.size()!=0)
//        {
//            do{
//                //cout<<dateCourante<<endl;
//                cout<<portefeuille.getSolde()<<endl;
//                transaction=t.choisirTransaction(b, portefeuille);
//                cout<<portefeuille.getSolde()<<endl;
//
////                while ( j<pjDispo.size() && !existe && transaction.getType()!=rien)
////                {
////                    if(pjDispo[j].getNom()==transaction.getNomAction())
////                        existe=true;
////                    else
////                        j++;
////                }
//                //cout<<transaction.getNomAction()<<","<<pjDispo[j].getNom()<<","<<pjDispo[j].getPrix()<<endl;
//
//                if(transaction.getType()==achat)
//                {
//                    cout<<"nom action a acheter: "<<transaction.getNomAction()<<" /qte action a acheter:"<<transaction.getQuantite()<<" /Type: "<<transaction.getType()<<" /solde: "<<portefeuille.getSolde()
//                    <<endl;
//                    j=0;
//                    k=0;
//                    //existe=false;
//                    //existe2=false;
//                    while ( j<pjDispo.size() && pjDispo[j].getNom()!=transaction.getNomAction())
//                    {
//                            j++;
//                    }
//                    //cout<<pjDispo[j].getPrix()<<endl;
//                   if((transaction.getQuantite()>=0) && (pjDispo[j].getNom()==transaction.getNomAction()) && (pjDispo[j].getPrix()*transaction.getQuantite()<=portefeuille.getSolde()))
//                    //if(transaction.getQuantite()>=0 && existe && pjDispo[j].getPrix()*transaction.getQuantite()<=portefeuille.getSolde())
//                        {
//                            portefeuille.acheterAction(transaction.getNomAction(), transaction.getQuantite(), pjDispo[j].getPrix());
//                            nbAchat++;
//                            cout<<"nom action a acheter: "<<transaction.getNomAction()<<" action trouvee: "<<pjDispo[j].getNom()<<" Prix trouve: "
//                            <<pjDispo[j].getPrix()<<endl;
//                            //cout<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
//                        }
//                    else
//                        {
//                            achatBloque++;
//                            cout<<"Transaction bloquee: "<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
//                        }
//
//                }
//                else if (transaction.getType()==vente)
//                {
//                    vector <Titre> titresDispo=portefeuille.getTitres();
//                    cout<<"nom action a vendre: "<<transaction.getNomAction()<<" /qte action a vendre:"
//                    <<transaction.getQuantite()<<" /type action a vendre:"<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
//                    j=0;
//                    k=0;
//                    //existe=false;
//                    //existe2=false;
//                    while ( j<pjDispo.size() && pjDispo[j].getNom()!=transaction.getNomAction())
//                    {
//                            j++;
//                    }
//                    while ( k<titresDispo.size() && titresDispo[k].getNomAction()!=transaction.getNomAction())
//                    {
//                        //cout<<titresDispo[k].getNomAction()<<endl;
//                            k++;
//                    }
////                    while ( k<titresDispo.size() && !existe2)
////                    {
////                        cout<<titresDispo[k].getNomAction()<<endl;
////                        if (titresDispo[k].getNomAction()==transaction.getNomAction())
////                            existe2=true;
////                        else
////                            k++;
////                    }
//                    //cout<<existe2<<" "<< existe <<" "<<(transaction.getQuantite()<=titresDispo[k].getQuantite() )<<" "<<(transaction.getQuantite()>=0)<<endl;
//
////                    cout<<(titresDispo[k].getNomAction()==transaction.getNomAction())
////                       <<" "<< (pjDispo[j].getNom()==transaction.getNomAction())
////                       <<" "<<  (transaction.getQuantite()<=titresDispo[k].getQuantite()) <<" "<<  (transaction.getQuantite()>=0)<<endl;
////                    cout<<"nom action a vendre: "<<transaction.getNomAction()<<" /action trouvee: "<<pjDispo[j].getNom()<<" /Prix trouve: "
////                    <<pjDispo[j].getPrix()<<" /action ds le portefeuille: "<<titresDispo[k].getNomAction()<<endl;
//                    if(titresDispo.size()>0 && (titresDispo[k].getNomAction()==transaction.getNomAction())
//                       && (pjDispo[j].getNom()==transaction.getNomAction())
//                       && transaction.getQuantite()<=titresDispo[k].getQuantite() && transaction.getQuantite()>=0)
////                    if(existe && existe2
////                       && transaction.getQuantite()<=titresDispo[k].getQuantite() && transaction.getQuantite()>=0)
//                    {
//                        portefeuille.vendreAction(transaction.getNomAction(), transaction.getQuantite(), pjDispo[j].getPrix());
//                        nbVente++;
//                    }
//
//                    else
//                        venteBloquee++;
//                }
//                else if (transaction.getType()==rien)
//                {
//                     nbRien++;
//                     cout<<"rien"<<endl;
//                }
//                i++;
//                //existe=false;
//                //existe2=false;
//
//            }while(transaction.getType()!=rien && i<100);
//
//        }
//        else
//            nbJoursBourseFermee++;
//
//        dateCourante.incrementerDate();
//        b.setDateAujourdhui(dateCourante);
//    }
//
//    nbTransactionsBloquee=achatBloque+venteBloquee;
//    nbTransactionsReussites=nbAchat+nbVente+nbRien;
//    //CALCUL DE LA VALEUR DU PORTEFEUILLE:
//    double montant=0;
//    cout<<"Actions ds le portefeuille: ";
//    for(auto t: portefeuille.getTitres())
//    {
//        cout<<"nom: "<<t.getNomAction()<<", qte: "<< t.getQuantite()<<endl;
//        PrixJournalier pj=b.getPrixJournalierLePlusRecent(t.getNomAction(), dateFin);
//        if(pj.getNom()==t.getNomAction())
//        {
//            montant+=pj.getPrix()*t.getQuantite();
//        }
//    }
//    portefeuille.deposerMontant(montant);
//    cout<<"nbTransactionsBloquee: "<<nbTransactionsBloquee<<endl;
//    cout<<"nbTransactionsReussites: "<<nbTransactionsReussites<<endl;
//    cout<<"nbVenteBloquee: "<<venteBloquee<<endl;
//    cout<<portefeuille.getSolde()<<endl;
//}

//VERSION2 SIMULATION (with map)
map<string,long> Simulation::executer(Bourse& b , Trader& t , Date dateDebut , Date dateFin , double solde)
{
    map<string, long> stats;
    Date dateCourante=dateDebut;
    b.setDateAujourdhui(dateCourante);
    Transaction transaction;
    Portefeuille portefeuille(solde);
    int achatBloque=0, venteBloquee=0;
    int nbAchat=0, nbVente=0, nbRien=0;
    int nbJoursBourseFermee=0;
    stats["nonmbre de ventes (validees): "]=0;
    stats["nonmbre d'achats (valides): "]=0;
    stats["nonmbre de transactions de type rien: "]=0;
    stats["nonmbre de ventes bloquees: "]=0;
    stats["nonmbre d'achats bloques: "]=0;
    stats["nonmbre de jours ou la bourse est fermee: "]=0;
    stats["TEMPS_GET_ACTIONS_DISPO_AUJ_MICROs"]=0;
    stats["NOMBRE_GET_ACTIONS_DISPO_AUJ"]=0;
    stats["TEMPS_CHOISIR_ACTION_MICROs"]=0;
    stats["NOMBRE_CHOISIR_ACTION"]=0;
    while(dateCourante<dateFin)
    {
        //cout<<dateCourante<<endl;
        auto start = chrono::high_resolution_clock::now();
        vector<PrixJournalier> pjDispo=b.getPrixJournalierAujourdhui();
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        //auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        stats["TEMPS_GET_ACTIONS_DISPO_AUJ_MICROs"]+=duration.count();
        stats["NOMBRE_GET_ACTIONS_DISPO_AUJ"]++;
        int i=0;
        unsigned int j=0, k=0;
        if (pjDispo.size()!=0)
        {
            do{
                //cout<<portefeuille.getSolde()<<endl;
                start = chrono::high_resolution_clock::now();
                transaction=t.choisirTransaction(b, portefeuille);
                stop = chrono::high_resolution_clock::now();
                duration = chrono::duration_cast<chrono::microseconds>(stop - start);
                stats["TEMPS_CHOISIR_ACTION_MICROs"]+=duration.count();
                stats["NOMBRE_CHOISIR_ACTION"]++;
                //cout<<portefeuille.getSolde()<<endl;
                if(transaction.getType()==achat)
                {
//                    cout<<"nom action a acheter: "<<transaction.getNomAction()<<" /qte action a acheter:"<<transaction.getQuantite()<<" /Type: "<<transaction.getType()<<" /solde: "<<portefeuille.getSolde()
//                    <<endl;
                    j=0;
                    k=0;
                    while ( j<pjDispo.size() && pjDispo[j].getNom()!=transaction.getNomAction())
                    {
                            j++;
                    }
                   if((transaction.getQuantite()>0) && (pjDispo[j].getNom()==transaction.getNomAction()) && (pjDispo[j].getPrix()*transaction.getQuantite()<=portefeuille.getSolde()))
                        {
                            portefeuille.acheterAction(transaction.getNomAction(), transaction.getQuantite(), pjDispo[j].getPrix());
                            nbAchat++;
                            stats["nonmbre d'achats (valides): "]++;
//                            cout<<"nom action a acheter: "<<transaction.getNomAction()<<" action trouvee: "<<pjDispo[j].getNom()<<" Prix trouve: "
//                            <<pjDispo[j].getPrix()<<endl;
                        }
                    else
                        {
                            achatBloque++;
                            stats["nonmbre d'achats bloques: "]++;
                            cout<<"Transaction bloquee: "<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
                        }

                }
                else if (transaction.getType()==vente)
                {
                    vector <Titre> titresDispo=portefeuille.getTitres();
//                    cout<<"nom action a vendre: "<<transaction.getNomAction()<<" /qte action a vendre:"
//                    <<transaction.getQuantite()<<" /type action a vendre:"<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
                    j=0;
                    k=0;
                    while ( j<pjDispo.size() && pjDispo[j].getNom()!=transaction.getNomAction())
                    {
                            j++;
                    }
                    while ( k<titresDispo.size() && titresDispo[k].getNomAction()!=transaction.getNomAction())
                    {
                            k++;
                    }

                    if(titresDispo.size()>0 && (titresDispo[k].getNomAction()==transaction.getNomAction())
                       && (pjDispo[j].getNom()==transaction.getNomAction())
                       && transaction.getQuantite()<=titresDispo[k].getQuantite() && transaction.getQuantite()>0)
                    {
                        portefeuille.vendreAction(transaction.getNomAction(), transaction.getQuantite(), pjDispo[j].getPrix());
                        stats["nonmbre de ventes (validees): "]++;
                        nbVente++;
                    }

                    else
                    {
                        stats["nonmbre de ventes bloquees: "]++;
                        venteBloquee++;
                    }

                }
                else if (transaction.getType()==rien)
                {
                     nbRien++;
                     stats["nonmbre de transactions de type rien: "]++;
                     cout<<"rien"<<endl;
                }
                i++;

            }while(transaction.getType()!=rien && i<100);

        }
        else
        {
            stats["nonmbre de jours ou la bourse est fermee: "]++;
            nbJoursBourseFermee++;
        }


        dateCourante.incrementerDate();
        b.setDateAujourdhui(dateCourante);
    }

    //nbTransactionsBloquee=achatBloque+venteBloquee;
    //nbTransactionsReussites=nbAchat+nbVente+nbRien;
    stats["nombre de transactions validees: "]=stats["nonmbre de transactions de type rien: "]+stats["nonmbre de ventes (validees): "]+stats["nonmbre d'achats (valides): "];
    stats["nombre de transactions bloquees: "]=stats["nonmbre de ventes bloquees: "]+stats["nonmbre d'achats bloques: "];
    //CALCUL DE LA VALEUR DU PORTEFEUILLE:
    double montant=0;
    //cout<<"Actions ds le portefeuille: ";
    for(auto t: portefeuille.getTitres())
    {
        //cout<<"nom: "<<t.getNomAction()<<", qte: "<< t.getQuantite()<<endl;
        PrixJournalier pj=b.getPrixJournalierLePlusRecent(t.getNomAction(), dateFin);
        if(pj.getNom()==t.getNomAction())
        {
            montant+=pj.getPrix()*t.getQuantite();
        }
    }
    portefeuille.deposerMontant(montant);
    stats["VALEUR_DU_PORTEFEUILLE"]=portefeuille.getSolde();
    if(stats["NOMBRE_GET_ACTIONS_DISPO_AUJ"]!=0)
        stats["TEMPS_MOYEN_GET_ACTIONS_DISPO_AUJ_MICROs"]=stats["TEMPS_GET_ACTIONS_DISPO_AUJ_MICROs"]/stats["NOMBRE_GET_ACTIONS_DISPO_AUJ"];
    if(stats["NOMBRE_CHOISIR_ACTION"]!=0)
        stats["TEMPS_MOYEN_CHOISIR_ACTION_MICROs"]=stats["TEMPS_CHOISIR_ACTION_MICROs"]/stats["NOMBRE_CHOISIR_ACTION"];
//    cout<<"nbTransactionsBloquee: "<<nbTransactionsBloquee<<endl;
//    cout<<"nbTransactionsReussites: "<<nbTransactionsReussites<<endl;
//    cout<<"nbVenteBloquee: "<<venteBloquee<<endl;
//    cout<<portefeuille.getSolde()<<endl;
    return stats;
}
