#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

enum TypeTx {achat, vente, rien};

class Transaction
{
    private:
        enum TypeTx type;
        string nomAction;
        int quantite;
    public:
        Transaction(enum TypeTx t, string nom, int qte);
        enum TypeTx getType()const;
        string getNomAction()const;
        int getQuantite() const;
};

class TestTransaction
{
    public:
        void initialiserTransaction();
};

#endif // TRANSACTION_H_INCLUDED
