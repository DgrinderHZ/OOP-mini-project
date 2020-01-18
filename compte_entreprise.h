#include "compte.h"
#include<string>

class CompteEntreprise: public Compte{

    vector<string> personneAutorises;
public:
    CompteEntreprise(vector<string> *perAuto){
        personneAutorises = *perAuto;
    }
    void afficher();
    void saisir(vector<string> *liste);
};


void CompteEntreprise::saisir(vector<string> *liste){

    cin >> *this;

    if(liste != NULL){
        cout << "Changement des personnes autorise en cours...\n";
        personneAutorises = *liste;
        cout << "Fin du Changement des personnes autorise!\n";
        compteOuvert[id] = *this;
    }

}

void CompteEntreprise::afficher(){

        cout << *this;

        cout << "\nListe des personnes autorises: >>> \n"<<endl;
        for(int i = 0; i < personneAutorises.size(); i++)
            cout << personneAutorises[i] << "\n";

}
