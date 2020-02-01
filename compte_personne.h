#ifndef H_CPERS
#define H_CPERS

#include "compte.h"

class ComptePersonne: virtual public Compte{
protected:
    int valeurDecouvert; /// nombre de jours
public:
    ComptePersonne(int v=30): valeurDecouvert(v){}
    void afficher();
    void saisir();
};


void ComptePersonne::saisir(){

    cin >> *this;

    cout << "Si vous aimeriez changer les valeurs de:\n\
             La valeurs du decouvert:\n  \
             Tapez >>> 1, sinon tapez >>> 0!: \n";

    int cc; cin >> cc;

    if(cc == 1){
        cout << "Donner La valeurs du decouvert: >>> ";
        cin >> valeurDecouvert;
        compteOuvert[id] = *this;
    }

}

void ComptePersonne::afficher(){

        cout << *this;

        cout << "\nLa valeurs du decouvert: >>> "<< valeurDecouvert <<endl;
}


#endif // H_CPERS
