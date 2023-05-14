#include <iostream>
#include<chrono>
#include<map>

#include "date.h"
#include "Bourse.h"
#include "Trader.h"
#include "Portefeuille.h"
#include "Simulation.h"
#include "Transaction.h"


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
    while(dateCourante<dateFin)
    {
        //cout<<dateCourante<<endl;
        auto start = chrono::high_resolution_clock::now();
        vector<PrixJournalier> pjDispo=b.getPrixJournalierAujourdhui();
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
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
                            stats["NOMBRE_D_ACHATS_VALIDES"]++;
//                            cout<<"nom action a acheter: "<<transaction.getNomAction()<<" action trouvee: "<<pjDispo[j].getNom()<<" Prix trouve: "
//                            <<pjDispo[j].getPrix()<<endl;
                        }
                    else
                        {
                            achatBloque++;
                            stats["NOMBRE_D_ACHATS_BLOQUES"]++;
                            //cout<<"Transaction bloquee: "<<transaction.getNomAction()<<","<<transaction.getQuantite()<<","<<transaction.getType()<<";"<<portefeuille.getSolde()<<endl;
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
                        stats["NOMBRE_DE_VENTES_VALIDEES"]++;
                        nbVente++;
                        //cout<<"vente effectuee"<<endl;
                    }

                    else
                    {
                        stats["NOMBRE_DE_VENTES_BLOQUEES"]++;
                        venteBloquee++;
                    }

                }
                else if (transaction.getType()==rien)
                {
                     nbRien++;
                     stats["NOMBRE_DE_TRANSACTIONS_DE_TYPE_RIEN"]++;
                     //cout<<"rien"<<endl;
                }
                i++;

            }while(transaction.getType()!=rien && i<100);

        }
        else
        {
            stats["NOMBRE_DE_JOURS_OU_LA_BOURSE_EST_FERMEE"]++;
            nbJoursBourseFermee++;
        }


        dateCourante.incrementerDate();
        b.setDateAujourdhui(dateCourante);
    }
    stats["NOMBRE_DE_TRANSACTIONS_VALIDES"]=stats["NOMBRE_DE_VENTES_VALIDEES"]+stats["NOMBRE_D_ACHATS_VALIDES"];
    stats["NOMBRE_DE_TRANSACTIONS_BLOQUEES"]=stats["NOMBRE_DE_VENTES_BLOQUEES"]+stats["NOMBRE_D_ACHATS_BLOQUES"];
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
    stats["GAIN"]=stats["VALEUR_DU_PORTEFEUILLE"]-solde;
    stats["GAIN_EN_POURCENTAGE"]=(stats["GAIN"]/solde)*100;
    return stats;
}
