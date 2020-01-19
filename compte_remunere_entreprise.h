#ifndef H_CRE
#define H_CRE
#include "compte_remunere.h"
#include "compte_entreprise.h"

class CompteRemunereEntreprise: public CompteRemunere, public CompteEntreprise{

public:

    CompteRemunereEntreprise(vector<string> *perAuto):
        CompteEntreprise(perAuto){}

    void afficher();
    void saisir(vector<string> *liste);

};

void CompteRemunereEntreprise::saisir(vector<string> *liste){

    CompteRemunere::saisir();
    /// Partie entreprise
    if(liste != NULL){
        cout << "Changement des personnes autorise en cours...\n";
        personneAutorises = *liste;
        cout << "Fin du Changement des personnes autorise!\n";
        compteOuvert[id] = *this;
    }
}

void CompteRemunereEntreprise::afficher(){

    CompteRemunere::afficher();

    cout << "\nListe des personnes autorises: >>> \n"<<endl;
        for(unsigned int i = 0; i < personneAutorises.size(); i++)
            cout << personneAutorises[i] << "\n";


}
#endif // H_CRE

