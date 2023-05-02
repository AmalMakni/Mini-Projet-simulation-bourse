#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

enum TypeTransaction {achat, vente, rien};

class Transaction
{
    private:
        enum TypeTransaction type;
        string nomAction;
        int quantite;
    public:
        Transaction(enum TypeTransaction, string nom, int qte);
        Transaction(){};
        enum TypeTransaction getType()const;
        string getNomAction()const;
        int getQuantite() const;

};

class TestTransaction
{
    public:
        void initialiserTransaction();
};

#endif // TRANSACTION_H_INCLUDED
