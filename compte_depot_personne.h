#ifndef H_CDP
#define H_CDP
#include "compte_depot.h"
#include "compte_personne.h"

class CompteDepotPersonne: public CompteDepot, virtual public ComptePersonne{

public:

    CompteDepotPersonne(float mn=100, float mx=12000, float ff=100, int valeurDec=30):
        CompteDepot(mn, mx, ff), ComptePersonne(valeurDec){}

    void afficher();
    void saisir();

};

void CompteDepotPersonne::saisir(){

    CompteDepot::saisir();
    /// Partie personne
    cout << "Si vous aimeriez changer les valeurs par defaut de:\
             La valeurs du decouvert:  \
             Tapez >>> 1, sinon tapez >>> 0!: \n";

    int cc; cin >> cc;

    if(cc == 1){
        cout << "Donner La valeurs du decouvert: >>> ";
        cin >> valeurDecouvert;
        compteOuvert[id] = *this;
    }

}

void CompteDepotPersonne::afficher(){
    cout << *this;
    cout << "\nLa valeurs minimale necessaire pour ouvrir un compte: >>> "<< minimale <<endl;
    cout << "\nLa valeurs maximale autorise pour un compte depot: >>> "<< maximale <<endl;
    cout << "\nLa valeur des frais de gestion: "<< fraisFermeture <<endl;

    cout << "\nLa valeurs du decouvert: >>> "<< valeurDecouvert <<endl;

}
#endif // H_CDP
