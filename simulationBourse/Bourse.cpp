#include <iostream>
#include "date.h"
#include <vector>
#include "Bourse.h"
#include "PrixJournalier.h"
#include "PersistancePrixJournalier.h"

//Bourse Vecteur:
Bourse::Bourse ( Date date ) : dateAujourdhui(date)
{}
BourseVecteur::BourseVecteur(Date date , vector<PrixJournalier> pj) : Bourse(date),historique(pj)
{}

vector<string> BourseVecteur::getActionsDisponibleParDate(Date d) const
{
  vector<string> ActionDispo;
   if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
  {
    for ( unsigned int i =0 ; i<historique.size();i++)
    {
      if ( historique[i].getDate()== d)
        ActionDispo.push_back(historique[i].getNom());
    }
  }
  return ActionDispo;
}

vector<PrixJournalier> BourseVecteur::getPrixJournalierParDate(Date d) const
{
    vector<PrixJournalier> PrixAction;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        for (unsigned int i =0 ; i< historique.size();i++)
        {
        if ( historique[i].getDate()== d)
            PrixAction.push_back(historique[i]);
        }
    }

    return PrixAction;

}
vector<string> BourseVecteur::getActionsDisponibleAujourdhui() const
{
    return getActionsDisponibleParDate(dateAujourdhui);
}
vector<PrixJournalier> BourseVecteur::getPrixJournalierAujourdhui() const
{
    return getPrixJournalierParDate(dateAujourdhui);
}
void BourseVecteur::setDateAujourdhui(Date d)
{
    dateAujourdhui=d;
}

vector<PrixJournalier> BourseVecteur::getPrixJournalierParDateParPrix(Date d, double budget) const
{
    vector<PrixJournalier> PrixAction;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        for (unsigned int i =0 ; i< historique.size();i++)
        {
        if ( historique[i].getDate()== d &&  historique[i].getPrix()<=budget)
            PrixAction.push_back(historique[i]);
        }
    }

    return PrixAction;
}
vector<string> BourseVecteur::getActionsDisponibleParDateParPrix(Date d, double budget) const
{
    vector<string> ActionDispo;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        for ( unsigned int i =0 ; i<historique.size();i++)
        {
          if ( historique[i].getDate()== d && historique[i].getPrix()<=budget)
            ActionDispo.push_back(historique[i].getNom());
        }
    }
  return ActionDispo;
};
PrixJournalier BourseVecteur::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
{
    PrixJournalier pjRecent;
    unsigned int i=0;
    while(i<historique.size())
    {
        if (historique[i].getNom()==nom && historique[i].getDate()<dateFin)
            pjRecent=historique[i];
        i++;
    }
    return pjRecent;
};
//to finish:
vector<PrixJournalier> BourseVecteur::getHistoriqueParAction(string nom) const
{
    vector<PrixJournalier> historiqueAction;
    return historiqueAction;
}
double BourseVecteur::movingAverage(string nom, unsigned int periode) const
{
    double m=0;
    return m;
}

//Bourse Vecteur Optimisée

BourseVecteurOptimisee::BourseVecteurOptimisee(Date date , vector<PrixJournalier> pj) : Bourse(date),historique(pj)
{}

vector<string> BourseVecteurOptimisee::getActionsDisponibleParDate(Date d) const
{
  vector<string> ActionDispo;
  //cout<<(!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))<<endl;
  if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
  {
        unsigned int i=0;
        while(historique[i].getDate()<d && i<historique.size())
            i++;
        while(historique[i].getDate()==d && i<historique.size())
        {
            ActionDispo.push_back(historique[i].getNom());
            i++;
        }
    }
  return ActionDispo;

}

vector<PrixJournalier> BourseVecteurOptimisee::getPrixJournalierParDate(Date d) const
{
    vector <PrixJournalier> prix;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        unsigned int i=0;
        while(historique[i].getDate()<d && i<historique.size())
            i++;
        while(historique[i].getDate()==d && i<historique.size())
        {
            prix.push_back(historique[i]);
            i++;
        }
    }
    return prix;
}


vector<string> BourseVecteurOptimisee::getActionsDisponibleAujourdhui() const
{
    return getActionsDisponibleParDate(dateAujourdhui);
}
vector<PrixJournalier> BourseVecteurOptimisee::getPrixJournalierAujourdhui() const
{
    return getPrixJournalierParDate(dateAujourdhui);
}
void BourseVecteurOptimisee::setDateAujourdhui(Date d)
{
    dateAujourdhui=d;
}
vector<PrixJournalier> BourseVecteurOptimisee::getPrixJournalierParDateParPrix(Date d, double budget) const
{
    vector <PrixJournalier> prix;
    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
    {
        unsigned int i=0;
        while(historique[i].getDate()<d && i<historique.size())
            i++;
        while(historique[i].getDate()==d && i<historique.size())
        {
            if (historique[i].getPrix()<=budget)
                prix.push_back(historique[i]);
            i++;
        }
    }
    return prix;
}
vector<string> BourseVecteurOptimisee::getActionsDisponibleParDateParPrix(Date d, double budget) const
{
  vector<string> actionDispo;
  //cout<<(!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))<<endl;
  if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
  {
        unsigned int i=0;
        while(historique[i].getDate()<d && i<historique.size())
            i++;
        while(historique[i].getDate()==d && i<historique.size())
        {
            if (historique[i].getPrix()<=budget)
                actionDispo.push_back(historique[i].getNom());
            i++;
        }
    }
    return actionDispo;
};
//fix warning here (return only inside if)
PrixJournalier BourseVecteurOptimisee::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
{
    PrixJournalier pjRecent;
    unsigned int i=0;
    if (!(dateAujourdhui<dateFin))
    {
        dateFin.incrementerDate();
        while(historique[i].getDate()<dateFin && i<historique.size())
        {
            if (historique[i].getNom()==nom)
                pjRecent=historique[i];
            i++;
        }
        return pjRecent;
    }

};
vector<PrixJournalier> BourseVecteurOptimisee::getHistoriqueParAction(string nom) const
{
    vector<PrixJournalier> historiqueAction;
    unsigned int i=0;
    while(i<historique.size() && historique[i].getDate()<dateAujourdhui)
    {
        if (historique[i].getNom()==nom)
            historiqueAction.push_back(historique[i]);
        i++;
    }
    return historiqueAction;
}
double BourseVecteurOptimisee::movingAverage(string nom, unsigned int periode) const
{
    vector<PrixJournalier> historiqueAction=getHistoriqueParAction(nom);
    double m=0;
//    vector<PrixJournalier>:: iterator i=historiqueAction.end();
//    i--;
//    PrixJournalier value=*i;
    if (periode>historiqueAction.size())
        periode=historiqueAction.size();
//        cout<<historiqueAction.size()-periode<<endl;
//        int nb=historiqueAction.size()-periode;
//        cout<<historiqueAction[nb].getDate();
    for (unsigned int i=historiqueAction.size()-1; i>historiqueAction.size()-periode; i--)
    {
        m+=historiqueAction[i].getPrix();
        //cout<<historiqueAction[i].getDate()<<","<<historiqueAction[i].getNom()<<","<<historiqueAction[i].getPrix()<<endl;
    }
    //cout<<historiqueAction[historiqueAction.size()-periode].getDate()<<","<<historiqueAction[historiqueAction.size()-periode].getNom()<<","<<historiqueAction[historiqueAction.size()-periode].getPrix()<<endl;
    m+=historiqueAction[historiqueAction.size()-periode].getPrix();
    m=m/periode;
    //cout<<m;

    return m;
}

// BourseMultiSet :
BourseMultiSet::BourseMultiSet(Date date , vector<PrixJournalier> pj) : Bourse(date)
{
    multiset <PrixJournalier> H ;
    for (auto p: pj)
    {
        H.insert(p);
    }
    historique=H ;
}

vector<string> BourseMultiSet::getActionsDisponibleParDate(Date d) const
{
    vector<string > actionDispo;
  //cout<<(!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))<<endl;
//  if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
//  {
//        unsigned int i=0;
//        while(historique[i].getDate()<d && i<historique.size())
//            i++;
//        while(historique[i].getDate()==d && i<historique.size())
//        {
//            ActionDispo.push_back(historique[i].getNom());
//            i++;
//        }
//    }
    PrixJournalier pj(d,"", 0);
    multiset<PrixJournalier> :: iterator pos=historique.lower_bound(pj);
    while (pos!=historique.end() && pos->getDate()== d)
    {
        actionDispo.push_back(pos->getNom());
        pos++;
    }
  return actionDispo;

}

vector<PrixJournalier> BourseMultiSet::getPrixJournalierParDate(Date d) const
{
    vector <PrixJournalier> prix;
//    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
//    {
//        unsigned int i=0;
//        while(historique[i].getDate()<d && i<historique.size())
//            i++;
//        while(historique[i].getDate()==d && i<historique.size())
//        {
//            prix.push_back(historique[i]);
//            i++;
//        }
    //}
    PrixJournalier pj(d,"", 0);
    multiset<PrixJournalier> :: iterator pos=historique.lower_bound(pj);
    while (pos!=historique.end() && pos->getDate()== d)
    {
        prix.push_back(*pos);
        pos++;
    }
    return prix;
}


vector<string> BourseMultiSet::getActionsDisponibleAujourdhui() const
{
    return getActionsDisponibleParDate(dateAujourdhui);
}
vector<PrixJournalier> BourseMultiSet::getPrixJournalierAujourdhui() const
{
    return getPrixJournalierParDate(dateAujourdhui);
}
void BourseMultiSet::setDateAujourdhui(Date d)
{
    dateAujourdhui=d;
}
vector<PrixJournalier> BourseMultiSet::getPrixJournalierParDateParPrix(Date d, double budget) const
{
    vector <PrixJournalier> prix;
//    if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
//    {
//        unsigned int i=0;
//        while(historique[i].getDate()<d && i<historique.size())
//            i++;
//        while(historique[i].getDate()==d && i<historique.size())
//        {
//            if (historique[i].getPrix()<=budget)
//                prix.push_back(historique[i]);
//            i++;
//        }
//    }
    PrixJournalier pj(d,"", 0);
    multiset<PrixJournalier> :: iterator pos=historique.lower_bound(pj);
    while (pos!=historique.end() && pos->getDate()== d)
    {
        if (pos->getPrix()<= budget )
        {
            //cout<<pos->getDate()<<", ";
            prix.push_back(*pos);
        }
        pos++;

    }

    return prix;
}
vector<string> BourseMultiSet::getActionsDisponibleParDateParPrix(Date d, double budget) const
{
  vector<string> actionDispo;
  //cout<<(!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))<<endl;
//  if (!(dateAujourdhui<d) && !(historique[historique.size()-1].getDate()<d)&& !(d<historique[0].getDate()))
//  {
//        unsigned int i=0;
//        while(historique[i].getDate()<d && i<historique.size())
//            i++;
//        while(historique[i].getDate()==d && i<historique.size())
//        {
//            if (historique[i].getPrix()<=budget)
//                actionDispo.push_back(historique[i].getNom());
//            i++;
//        }
//    }
    PrixJournalier pj(d,"", 0);
    multiset<PrixJournalier> :: iterator pos=historique.lower_bound(pj);
    while (pos!=historique.end() && pos->getDate()== d)
    {
        if (pos->getPrix()<= budget )
        {
            //cout<<pos->getDate()<<", ";
            actionDispo.push_back(pos->getNom());
        }
        pos++;

    }
    return actionDispo;
};
//fix warning here (return only inside if)
PrixJournalier BourseMultiSet::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
{

    PrixJournalier pjRecent;

//    unsigned int i=0;
    if (!(dateAujourdhui<dateFin))
    {
        dateFin.incrementerDate();
        //PrixJournalier pj(dateFin, "", 0);
        multiset<PrixJournalier>:: iterator it=historique.begin();
        while(it->getDate()<dateFin && it!=historique.end())
        {
            if (it->getNom()==nom)
                pjRecent=*it;
            it++;
        }
        return pjRecent;
    }

};
vector<PrixJournalier> BourseMultiSet::getHistoriqueParAction(string nom) const
{
    vector<PrixJournalier> historiqueAction;
    multiset<PrixJournalier>:: iterator it=historique.begin();
    while(it->getDate()<dateAujourdhui && it!=historique.end())
    {
        if (it->getNom()==nom)
            historiqueAction.push_back(*it);
        it++;
    }
    return historiqueAction;
}
double BourseMultiSet::movingAverage(string nom, unsigned int periode) const
{
    vector<PrixJournalier> historiqueAction=getHistoriqueParAction(nom);
    double m=0;
//    vector<PrixJournalier>:: iterator i=historiqueAction.end();
//    i--;
//    PrixJournalier value=*i;
    if (periode>historiqueAction.size())
        periode=historiqueAction.size();
//        cout<<historiqueAction.size()-periode<<endl;
//        int nb=historiqueAction.size()-periode;
//        cout<<historiqueAction[nb].getDate();
    for (unsigned int i=historiqueAction.size()-1; i>historiqueAction.size()-periode; i--)
    {
        m+=historiqueAction[i].getPrix();
        //cout<<historiqueAction[i].getDate()<<","<<historiqueAction[i].getNom()<<","<<historiqueAction[i].getPrix()<<endl;
    }
    //cout<<historiqueAction[historiqueAction.size()-periode].getDate()<<","<<historiqueAction[historiqueAction.size()-periode].getNom()<<","<<historiqueAction[historiqueAction.size()-periode].getPrix()<<endl;
    m+=historiqueAction[historiqueAction.size()-periode].getPrix();
    m=m/periode;
    //cout<<m;

    return m;
}
//Test Bourse Vecteur:

void TestBourseVecteur::getActionsDisponibleParDate_DateExistante()
{
    bool test;
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    Date d(12,1,2023);
    BourseVecteur b(d1, v);
    vector<string> nom=b.getActionsDisponibleParDate(d);
    test=(nom.size()==3) && (nom[0]=="a") && (nom[1]=="b") && (nom[2]=="c");
    if (test)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getActionsDisponibleParDate pour une date existante"<<endl;
}

void TestBourseVecteur::getActionsDisponibleParDate_DateNonExistante()
{
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    BourseVecteur b(d1, v);
    vector<string> nom=b.getActionsDisponibleParDate(d1);
    if (nom.size()==0)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getActionsDisponibleParDate pour une non date existante"<<endl;

}

void TestBourseVecteur::getPrixJournalierParDate_DateExistante()
{
    bool test, test1, test2, test3;
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    Date d(12,1,2023);
    BourseVecteur b(d1, v);
    vector<PrixJournalier> prix=b.getPrixJournalierParDate(d);
    test1=(prix[0].getNom()=="a")&& (prix[0].getPrix()==10.5)&& (prix[0].getDate()==d);
    test2=(prix[1].getNom()=="b")&& (prix[1].getPrix()==11.5)&& (prix[1].getDate()==d);
    test3=(prix[2].getNom()=="c")&& (prix[2].getPrix()==15)&& (prix[2].getDate()==d);
    test=(prix.size()==3)&& test1 && test2 && test3;
    if (test)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getPrixJournalierParDate pour une date existante"<<endl;
}

void TestBourseVecteur::getPrixJournalierParDate_DateNonExistante()
{
    //bool test;
    PersistancePrixJournaliers p;
    vector<PrixJournalier> v;
    v=p.lirePrixJournaliersDUnFichier("C:\\Users\\21625\\Desktop\\New folder\\test.csv");
    Date d1(9, 4, 2023);
    BourseVecteur b(d1, v);
    vector<PrixJournalier> prix=b.getPrixJournalierParDate(d1);
    if (prix.size()==0)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec de getPrixJournalierParDate pour une date non existante"<<endl;
}


