#ifndef H_CDE
#define H_CDE
#include "compte_depot.h"
#include "compte_entreprise.h"

class CompteDepotEntreprise: public CompteDepot, public CompteEntreprise{

public:

    CompteDepotEntreprise(vector<string> *perAuto, float mn=100, float mx=12000, float ff=100):
        CompteDepot(mn, mx, ff), CompteEntreprise(perAuto){}

    void afficher();
    void saisir(vector<string> *liste);

};

void CompteDepotEntreprise::saisir(vector<string> *liste){

    CompteDepot::saisir();
    /// Partie entreprise

        if(liste != NULL){
            cout << "Changement des personnes autorise en cours...\n";
            personneAutorises = *liste;
            cout << "Fin du Changement des personnes autorise!\n";
            compteOuvert[id] = *this;
        }


}

void CompteDepotEntreprise::afficher(){
    cout << *this;
    cout << "\nLa valeurs minimale necessaire pour ouvrir un compte: >>> "<< minimale <<endl;
    cout << "\nLa valeurs maximale autorise pour un compte depot: >>> "<< maximale <<endl;
    cout << "\nLa valeur des frais de gestion: "<< fraisFermeture <<endl;

    cout << "\nListe des personnes autorises: >>> \n"<<endl;
        for(unsigned int i = 0; i < personneAutorises.size(); i++)
            cout << personneAutorises[i] << "\n";
}
#endif // H_CDE

