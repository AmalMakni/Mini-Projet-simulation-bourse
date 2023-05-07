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

class TraderAleatoir1: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
};

class TraderAleatoir2: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
};

class TraderMovingAverage: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
};

class TraderMovingAverage2: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
};
#endif // TRADER_H_INCLUDED
