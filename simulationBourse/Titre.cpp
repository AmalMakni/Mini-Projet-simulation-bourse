#include "Titre.h"
using namespace std;



Titre::Titre(string nom, int qte):nomAction(nom), quantite(qte){};
string Titre::getNomAction() const {return nomAction;};
int Titre::getQuantite() const {return quantite;};

 void TestTitre::initialiserTitre()
 {
     Titre t("abc", 12);
     if (t.getNomAction()=="abc" && t.getQuantite()==12)
        cout<<"Succes"<<endl;
     else
        cout<<"Echec de l'initialisation d'un titre."<<endl;
 }
