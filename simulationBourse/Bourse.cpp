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
    PrixJournalier pjRecent(dateFin,"",-1);
    if(!(dateAujourdhui<dateFin))
    {
        dateFin.incrementerDate();
        unsigned int i=0;
        while(i<historique.size())
        {
            if (historique[i].getNom()==nom && historique[i].getDate()<dateFin)
                pjRecent=historique[i];
            i++;
        }
    }

    return pjRecent;
};
PrixJournalier BourseVecteur::getPrixJournalierLePlusRecentV2(string nom, Date dateFin) const
{
    PrixJournalier pjRecent(dateFin,"",-1);
    if(!(dateAujourdhui<dateFin))
    {
        //dateFin.incrementerDate();
        unsigned int i=0;
        while(i<historique.size())
        {
            if (historique[i].getNom()==nom && historique[i].getDate()<dateFin)
                pjRecent=historique[i];
            i++;
        }
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

PrixJournalier BourseVecteurOptimisee::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
{
    PrixJournalier pjRecent;
    PrixJournalier pj(dateFin, "", 0);
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
    return pj;

};
PrixJournalier BourseVecteurOptimisee::getPrixJournalierLePlusRecentV2(string nom, Date dateFin) const
{
    PrixJournalier pjRecent;
    PrixJournalier pj(dateFin, "", 0);
    unsigned int i=0;
    if (!(dateAujourdhui<dateFin))
    {
        //dateFin.incrementerDate();
        while(historique[i].getDate()<dateFin && i<historique.size())
        {
            if (historique[i].getNom()==nom)
                pjRecent=historique[i];
            i++;
        }
        return pjRecent;
    }
    return pj;
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
    //cout<<historique[0].getDate();
    vector<PrixJournalier> historiqueAction=getHistoriqueParAction(nom);
    double m=0;

    if(dateAujourdhui==historique[0].getDate())
        return m;
//    vector<PrixJournalier>:: iterator i=historiqueAction.end();
//    i--;
//    PrixJournalier value=*i;
    if (periode>historiqueAction.size())
        periode=historiqueAction.size();
//        cout<<historiqueAction.size()-periode<<endl;
//        int nb=historiqueAction.size()-periode;
//        cout<<historiqueAction[nb].getDate();
    if (historiqueAction.size()==0)
        return m;
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
    PrixJournalier pj(d,"", 0);
    if(dateAujourdhui<d)
        return actionDispo;
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
    if(dateAujourdhui<d)
        return prix;
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
    if (dateAujourdhui<d)
        return prix;
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
    if (dateAujourdhui<d)
        return actionDispo;

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
//PrixJournalier BourseMultiSet::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
//{
//
//    PrixJournalier pjRecent(dateFin, "", -1);
//
////    unsigned int i=0;
//    if (!(dateAujourdhui<dateFin))
//    {
//        dateFin.incrementerDate();
//        //PrixJournalier pj(dateFin, "", 0);
//        multiset<PrixJournalier>:: iterator it=historique.begin();
//        while(it->getDate()<dateFin && it!=historique.end())
//        {
//            if (it->getNom()==nom)
//                pjRecent=*it;
//            it++;
//        }
//        return pjRecent;
//    }
//
//    return pjRecent;
//
//};
PrixJournalier BourseMultiSet::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
{
    PrixJournalier pj(dateFin, "", 0);
    PrixJournalier pjRecent(dateFin, "", 0);
    if (!(dateAujourdhui<dateFin))
    {
        auto it=historique.upper_bound(pj);
        if(it==historique.end())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        if(dateFin<it->getDate())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        while(it->getNom()!=nom && it!=historique.begin())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        //cout<<!(dateFin<it->getDate())<<endl;
        if(it->getNom()==nom && !(dateFin<it->getDate()))
            return *it;
    }
    return pjRecent;
}
//PrixJournalier BourseMultiSet::getPrixJournalierLePlusRecentV2(string nom, Date dateFin) const
//{
//
//    PrixJournalier pjRecent;
//
////    unsigned int i=0;
//    if (!(dateAujourdhui<dateFin))
//    {
//        //dateFin.incrementerDate();
//        //PrixJournalier pj(dateFin, "", 0);
//        multiset<PrixJournalier>:: iterator it=historique.begin();
//        while(it->getDate()<dateFin && it!=historique.end())
//        {
//            if (it->getNom()==nom)
//                pjRecent=*it;
//            it++;
//        }
//        return pjRecent;
//    }
//
//};

PrixJournalier BourseMultiSet::getPrixJournalierLePlusRecentV2(string nom, Date dateFin) const
{
    PrixJournalier pj(dateFin, "", 0);
    PrixJournalier pjRecent(dateFin, "", 0);
    if (!(dateAujourdhui<dateFin))
    {
        auto it=historique.upper_bound(pj);
         if(it==historique.end())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        if(dateFin<it->getDate())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        while((it->getNom()!=nom || it->getDate()==dateFin) && it!=historique.begin())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        //cout<<!(dateFin<it->getDate())<<endl;
        if(it->getNom()==nom )
            pjRecent=*it;
    }
    //cout<<dateAujourdhui<<endl;
    //cout<<pjRecent.getNom()<<", "<<pjRecent.getPrix()<<", "<<pjRecent.getDate()<<endl;
    return pjRecent;

}
//parcours sequentiel d'un set (arbre, non contigu) prend beaucoup plus de temps que le parcours sequentiel d'un vecteur (contigu)
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
    Date d(4,1,2010);
    if(dateAujourdhui==d)
        return m;
    //cout<<dateAujourdhui<<endl;
//    vector<PrixJournalier>:: iterator i=historiqueAction.end();
//    i--;
//    PrixJournalier value=*i;
    if (periode>historiqueAction.size())
        periode=historiqueAction.size();
//        cout<<historiqueAction.size()-periode<<endl;
//        int nb=historiqueAction.size()-periode;
//        cout<<historiqueAction[nb].getDate();
//you were here
//    for (vector<PrixJournalier>:: iterator i=historiqueAction.end()-1; i>historiqueAction.end()-periode; i--)
//    {
//        //m+=historiqueAction[i].getPrix();
//        m+=i->getPrix();
//        //cout<<historiqueAction[i].getDate()<<","<<historiqueAction[i].getNom()<<","<<historiqueAction[i].getPrix()<<endl;
//    }
//    //cout<<historiqueAction[historiqueAction.size()-periode].getDate()<<","<<historiqueAction[historiqueAction.size()-periode].getNom()<<","<<historiqueAction[historiqueAction.size()-periode].getPrix()<<endl;
//    //m+=historiqueAction[historiqueAction.size()-periode].getPrix();
//    vector<PrixJournalier>:: iterator i=historiqueAction.end()-periode;
//    m+=i->getPrix();
//    m=m/periode;
    //cout<<m;
    if (historiqueAction.size()==0)
        return m;
    for (unsigned int i=historiqueAction.size()-1; i>historiqueAction.size()-periode; i--)
    {
        m+=historiqueAction[i].getPrix();
        //cout<<historiqueAction[i].getDate()<<","<<historiqueAction[i].getNom()<<","<<historiqueAction[i].getPrix()<<endl;
    }
    //cout<<historiqueAction[historiqueAction.size()-periode].getDate()<<","<<historiqueAction[historiqueAction.size()-periode].getNom()<<","<<historiqueAction[historiqueAction.size()-periode].getPrix()<<endl;
    m+=historiqueAction[historiqueAction.size()-periode].getPrix();
    m=m/periode;

    return m;
}
// BourseMultiMap :
BourseMultiMap::BourseMultiMap(Date date , vector<PrixJournalier> & pj) : Bourse(date)
{
    multimap <Date, PrixJournalier> H ;
    for (auto p: pj)
    {
        H.insert({p.getDate() ,p});
    }
    historique=H ;
}

vector<string> BourseMultiMap::getActionsDisponibleParDate(Date d) const
{
    vector<string > actionDispo;
    if (dateAujourdhui<d)
        return actionDispo;
    PrixJournalier pj(d,"", 0);
    auto  pos=historique.lower_bound(pj.getDate());
    while (pos->first==d && pos!=historique.end())
    {
        actionDispo.push_back((pos->second).getNom());
        pos++;
    }
  return actionDispo;

}

vector<PrixJournalier> BourseMultiMap::getPrixJournalierParDate(Date d) const
{
    vector <PrixJournalier> prix;
    if (dateAujourdhui<d)
        return prix;
    PrixJournalier pj(d,"", 0);
    auto  pos=historique.lower_bound(pj.getDate());
    while (pos->first==d && pos!=historique.end())
    {
        prix.push_back(pos->second);
        pos++;
    }
    return prix;
}


vector<string> BourseMultiMap::getActionsDisponibleAujourdhui() const
{
    return getActionsDisponibleParDate(dateAujourdhui);
}
vector<PrixJournalier> BourseMultiMap::getPrixJournalierAujourdhui() const
{
    return getPrixJournalierParDate(dateAujourdhui);
}
void BourseMultiMap::setDateAujourdhui(Date d)
{
    dateAujourdhui=d;
}
vector<PrixJournalier> BourseMultiMap::getPrixJournalierParDateParPrix(Date d, double budget) const
{
    vector <PrixJournalier> prix;
    if (dateAujourdhui<d)
        return prix;
    PrixJournalier pj(d,"", 0);
    auto pos=historique.lower_bound(d);
    while (pos->first==d && pos!=historique.end())
    {
        if ((pos->second).getPrix()<= budget )
        {
            //cout<<pos->getDate()<<", ";
            prix.push_back(pos->second);
        }
        pos++;

    }

    return prix;
}
vector<string> BourseMultiMap::getActionsDisponibleParDateParPrix(Date d, double budget) const
{
    vector<string> actionDispo;
    PrixJournalier pj(d,"", 0);
    auto pos=historique.lower_bound(pj.getDate());
    while (pos->first==d && pos!=historique.end())
    {
        if (pos->second.getPrix()<= budget )
        {
            //cout<<pos->getDate()<<", ";
            actionDispo.push_back(pos->second.getNom());
        }
        pos++;

    }
    return actionDispo;
};
//fix warning here (return only inside if)
//PrixJournalier BourseMultiMap::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
//{
//
//    PrixJournalier pjRecent;
//
////    unsigned int i=0;
//    if (!(dateAujourdhui<dateFin))
//    {
//        dateFin.incrementerDate();
//        //PrixJournalier pj(dateFin, "", 0);
//        auto it=historique.begin();
//        while(it->second.getDate()<dateFin && it!=historique.end())
//        {
//            if (it->second.getNom()==nom)
//                pjRecent=it->second;
//            it++;
//        }
//        return pjRecent;
//    }
//
//};
PrixJournalier BourseMultiMap::getPrixJournalierLePlusRecent(string nom, Date dateFin) const
{
    PrixJournalier pj(dateFin, "", 0);
    PrixJournalier pjRecent(dateFin, "", -1);
    if (!(dateAujourdhui<dateFin))
    {
        auto it=historique.upper_bound(dateFin);
        if(it==historique.end())
            it--;

        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        if(dateFin<it->second.getDate())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        while(it->second.getNom()!=nom && it!=historique.begin())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        //cout<<!(dateFin<it->getDate())<<endl;
        if(it->second.getNom()==nom && !(dateFin<it->second.getDate()))
            return it->second;
    }
    return pjRecent;
}

//PrixJournalier BourseMultiMap::getPrixJournalierLePlusRecentV2(string nom, Date dateFin) const
//{
//
//    PrixJournalier pjRecent;
//
////    unsigned int i=0;
//    if (!(dateAujourdhui<dateFin))
//    {
//        //dateFin.incrementerDate();
//        //PrixJournalier pj(dateFin, "", 0);
//        auto it=historique.begin();
//        while(it->second.getDate()<dateFin && it!=historique.end())
//        {
//            if (it->second.getNom()==nom)
//                pjRecent=it->second;
//            it++;
//        }
//        return pjRecent;
//    }
//    //return pjRecent;
//
//};
PrixJournalier BourseMultiMap::getPrixJournalierLePlusRecentV2(string nom, Date dateFin) const
{
    PrixJournalier pj(dateFin, "", 0);
    PrixJournalier pjRecent(dateFin, "", -1);
    if (!(dateAujourdhui<dateFin))
    {
        auto it=historique.upper_bound(dateFin);
        if(it==historique.end())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;

        if(dateFin<it->second.getDate())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        while((it->second.getNom()!=nom || it->second.getDate()==dateFin) && it!=historique.begin())
            it--;
        //cout<<it->getNom()<<", "<<it->getPrix()<<", "<<it->getDate()<<endl;
        //cout<<!(dateFin<it->getDate())<<endl;
        if(it->second.getNom()==nom && !(dateFin<it->second.getDate()))
            return it->second;
    }
    return pjRecent;
}

//parcours sequentiel d'un set (arbre, non contigu) prend beaucoup plus de temps que le parcours sequentiel d'un vecteur (contigu)
vector<PrixJournalier> BourseMultiMap::getHistoriqueParAction(string nom) const
{
    vector<PrixJournalier> historiqueAction;
    auto it=historique.begin();
    while(it->first<dateAujourdhui && it!=historique.end())
    {
        if (it->second.getNom()==nom)
            historiqueAction.push_back(it->second);
        it++;
    }
    return historiqueAction;
}
double BourseMultiMap::movingAverage(string nom, unsigned int periode) const
{
    vector<PrixJournalier> historiqueAction=getHistoriqueParAction(nom);
    double m=0;
    if (periode>historiqueAction.size())
        periode=historiqueAction.size();
    if (historiqueAction.size()==0)
        return m;
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


