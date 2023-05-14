#ifndef TRADER_H_INCLUDED
#define TRADER_H_INCLUDED
#include "Transaction.h"
#include "Bourse.h"
#include "Portefeuille.h"

class Trader
{
    public:
        virtual Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille)=0;
        virtual ~Trader(){};
};

class TraderAleatoir1: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
        ~TraderAleatoir1(){};
};

class TraderAleatoir2: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
        ~TraderAleatoir2(){};
};

class TraderMovingAverage: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
        ~TraderMovingAverage(){};
};

class TraderMovingAverage2: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
        ~TraderMovingAverage2(){};
};

class TraderComparaison: public Trader
{
    public:
        Transaction choisirTransaction(const Bourse& bourse, const Portefeuille &portefeuille);
        ~TraderComparaison(){};
};
#endif // TRADER_H_INCLUDED
