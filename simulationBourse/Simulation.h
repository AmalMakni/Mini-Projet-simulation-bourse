#ifndef SIMULATION_H_INCLUDED
#define SIMULATION_H_INCLUDED

#include<map>

class Simulation
{
    private :

    public:
        //static void executer(Bourse& b, Trader& t, Date dateDebut, Date dateFin, double solde);
        static map<string,long> executer(Bourse& b, Trader& t, Date dateDebut, Date dateFin, double solde);
};

#endif // SIMULATION_H_INCLUDED
