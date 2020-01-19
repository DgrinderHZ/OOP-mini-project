#ifndef H_CDRE
#define H_CDRE
#include "compte_depot_entreprise.h"
#include "compte_remunere_entreprise.h"

class CompteDepotRemunereEntreprise:
    public CompteDepotEntreprise, virtual public CompteRemunereEntreprise{

public:

    CompteDepotRemunereEntreprise(vector<string> *perAuto, float mn=100, float mx=100000, float ff=200):
        CompteDepotEntreprise(perAuto, mn, mx, ff), CompteRemunereEntreprise(perAuto){}

    void afficher();
    void saisir(vector<string> *liste);
    void deposer(float);
    void fermer();

};

void CompteDepotRemunereEntreprise::fermer(){

        /**** partie remunere *****/
        calculerInteret();
        float interet = 0;
        for(int i = 0; i < 12; i++) interet += interetMensuel[i];

        /**** partie depot *****/
        cout << "\nApres ajout d'interet et prelevement des frais de gestion:\n";
        cout << "\n La banque doit rendre au client le solde = " << interet+solde - fraisFermeture << endl;

        if(compteOuvert.size())
            compteOuvert.erase(compteOuvert.begin()+id);
}

void CompteDepotRemunereEntreprise::deposer(float somme){
    /**** partie remuneré *****/
    if(somme > 1000) somme += (somme/1000+1);
    else somme += 1;
    /**** partie depot *****/
    if(somme > 10000) fraisFermeture += 20;
    else if(somme > 1000) fraisFermeture -= (somme/1000+1);
    else fraisFermeture--;

    Compte::deposer(somme);
}

void CompteDepotRemunereEntreprise::saisir(vector<string> *liste){

    CompteDepotEntreprise::saisir(liste);
    /// pas de saisie spécifique pour Compte Remunéré
}

void CompteDepotRemunereEntreprise::afficher(){

    CompteDepotEntreprise::afficher();

    /***** Partie Compte Remunere ****/
    calculerInteret();
    cout << "\nTaux de remuneration: >>> "<< taux <<endl;
    cout << "Interet mensuels: >>> MOIS(INTERET)\n";
    for(int i = 0; i < 12; i++) cout << i<<"(" << interetMensuel[i] <<")"<< "| ";
}

#endif // H_CRE


