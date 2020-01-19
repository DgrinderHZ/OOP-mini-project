#ifndef H_CRP
#define H_CRP

#include "compte_remunere.h"
#include "compte_personne.h"

class CompteRemunerePersonne: public CompteRemunere, virtual public ComptePersonne{

public:

    CompteRemunerePersonne(int valeurDec=30):
        ComptePersonne(valeurDec){}

    void afficher();
    void saisir();

};

void CompteRemunerePersonne::saisir(){

    CompteRemunere::saisir();
    /// Partie personne
    cout << "Si vous aimeriez changer les valeurs de:\
             La valeurs du decouvert:  \
             Tapez >>> 1, sinon tapez >>> 0!: \n";

    int cc; cin >> cc;

    if(cc == 1){
        cout << "Donner La valeurs du decouvert: >>> ";
        cin >> valeurDecouvert;
        compteOuvert[id] = *this;
    }

}

void CompteRemunerePersonne::afficher(){
    cout << *this;
    calculerInteret();
    cout << "\nTaux de remuneration: >>> "<< taux <<endl;
    cout << "Interet mensuels: >>> MOIS(INTERET)\n";
    for(int i = 0; i < 12; i++) cout << i<<"(" << interetMensuel[i] <<")"<< "| ";

    cout << "\nLa valeurs du decouvert: >>> "<< valeurDecouvert <<endl;

}


#endif // H_CRP
