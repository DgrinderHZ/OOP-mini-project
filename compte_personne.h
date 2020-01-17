#include "compte.h"

class ComptePersonne: public Compte{

    int valeurDecouvert; /// nombre de jours
public:
    ComptePersonne(int v=30): valeurDecouvert(v){}
    void afficher();
    void saisir();
};


void ComptePersonne::saisir(){
    //CompteDebot& c = *this;
    //cin>>c;
    cout<< "Veuillez saisir information de compte: \n";
    cout<< "Date d'ouverture: \n"; cin>>dateOuverture;
    cout<< "Solde: <<< "; cin >> solde;
    cout<< "Liste des opérations: <<< " <<endl;
    cout<< "Proprietaires: <<< "; cin >> proprietaire;

    cout << "Si vous aimeriez changer les valeurs de:\
             La valeurs du decouvert:  \
             Tapez >>> 1, sinon tapez >>> 0!: \n";

    int cc; cin >> cc;

    if(cc == 1){
        cout << "Donner La valeurs du decouvert: >>> ";
        cin >> valeurDecouvert;
    }

    compteOuvert[id] = *this;
}

void ComptePersonne::afficher(){

        cout << *this;

        cout << "\nLa valeurs du decouvert: >>> "<< valeurDecouvert <<endl;
}
