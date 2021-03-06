#ifndef H_CDRP
#define H_CDRP
#include "compte_depot_personne.h"
#include "compte_remunere_personne.h"

class CompteDepotRemunerePersonne:
    public CompteDepotPersonne, public CompteRemunerePersonne{

public:

    CompteDepotRemunerePersonne(float mn=100, float mx=100000, float ff=200, int valeurDec=30):
        CompteDepotPersonne(mn, mx, ff, valeurDec){}

    void afficher();
    void saisir();
    void deposer(float);
    void fermer();

};

void CompteDepotRemunerePersonne::fermer(){

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

void CompteDepotRemunerePersonne::deposer(float somme){
    /**** partie remuner� *****/
    if(somme > 1000) somme += (somme/1000+1);
    else somme += 1;
    /**** partie depot *****/
    if(somme > 10000) fraisFermeture += 20;
    else if(somme > 1000) fraisFermeture -= (somme/1000+1);
    else fraisFermeture--;

    Compte::deposer(somme);
}

void CompteDepotRemunerePersonne::saisir(){

    CompteDepotPersonne::saisir();
    /// pas de saisie sp�cifique pour Compte Remun�r�
}

void CompteDepotRemunerePersonne::afficher(){

    CompteDepotPersonne::afficher();

    /***** Partie Compte Remunere ****/
    calculerInteret();
    cout << "\nTaux de remuneration: >>> "<< taux <<endl;
    cout << "Interet mensuels: >>> MOIS(INTERET)\n";
    for(int i = 0; i < 12; i++) cout << i<<"(" << interetMensuel[i] <<")"<< "| ";

}
#endif // H_CDRP

