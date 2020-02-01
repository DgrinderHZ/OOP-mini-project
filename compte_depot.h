#ifndef H_CDEPOT
#define H_CDEPOT

#include "compte.h"

class CompteDepot: virtual public Compte{

protected:
    float minimale, maximale;
    float fraisFermeture;
public:

    CompteDepot(float mn=100, float mx=100000, float ff=200){
        minimale = mn;
        maximale = mx;
        fraisFermeture = ff;
    }

    void fermer();
    void deposer(float);
    void afficher();
    void saisir();
};


void CompteDepot::fermer(){

        cout << "Apres prelevement des frais de gestion:\n";
        cout << "\nLe solde = " << solde - fraisFermeture << endl;
        /// SUPPRIMER
        if(compteOuvert.size())
            compteOuvert.erase(compteOuvert.begin()+id);

}


void CompteDepot::deposer(float somme){
    /// spécialisation
    if(somme > 10000) fraisFermeture += 20;
    else if(somme > 1000) fraisFermeture -= (somme/1000+1);
    else fraisFermeture--;

    /// methode classe de base
    Compte::deposer(somme);
}

void CompteDepot::saisir(){

    /// attributs de base
    cin >> *this;

    /// specialisation
    cout << "Si vous aimeriez changer les valeurs de:\n\
             La valeurs minimale necessaire pour ouvrir un compte:\n\
             La valeurs maximale autorise pour un compte depot:\n\
             La valeur des frais de gestion:\n \
             Tapez >>> 1, sinon tapez >>> 0!: ";
    int cc; cin >> cc;
    if(cc == 1){
        cout<< "Donner la valeurs minimale necessaire pour ouvrir un compte: >>> ";
        cin >> minimale ;
        cout << "Donner la valeurs maximale autorise pour un compte depot: >>> ";
        cin >>  maximale;
        cout << "Donner la valeur des frais de gestion: >>> ";
        cin >>  fraisFermeture;
        compteOuvert[id] = *this;
    }

}

void CompteDepot::afficher(){

        /// attributs de base
        cout << *this;
        /// specialisation
        cout << "\nLa valeurs minimale necessaire pour ouvrir un compte: >>> "<< minimale <<endl;
        cout << "\nLa valeurs maximale autorise pour un compte depot: >>> "<< maximale <<endl;
        cout << "\nLa valeur des frais de gestion: "<< fraisFermeture <<endl;
}




#endif // H_CDEPOT
