#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include "Transaction.h"
#include "Bourse.h"
#include "Portefeuille.h"

class Trader
{
    public:
        virtual Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille)=0;
};

class TraderAleatoir
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
};


#endif // TRADER_H_INCLUDED
