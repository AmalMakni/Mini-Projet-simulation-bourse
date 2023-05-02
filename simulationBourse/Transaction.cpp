# include "Transaction.h"
using namespace std;


Transaction::Transaction(enum TypeTransaction t, string nom, int qte): type(t), nomAction(nom), quantite(qte){};
enum TypeTransaction Transaction::getType()const {return type;};
string Transaction::getNomAction()const {return nomAction;};
int Transaction::getQuantite() const {return quantite;};


void TestTransaction::initialiserTransaction()
{
    Transaction t(achat, "abc", 12);
    if (t.getType()==achat, t.getNomAction()=="abc", t.getQuantite()==12)
        cout<<"Succes"<<endl;
    else
        cout<<"Echec initialisation d'une transaction."<<endl;
}
