#include "compte.h"

class CompteDepot: public Compte{

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
    if(compteOuvert.size()){
        cout << "Apres prelevement des frais de gestion:\n";
        cout << "\nLe solde = " << solde - fraisFermeture << endl;
        compteOuvert.erase(compteOuvert.begin()+id);
    }
}


void CompteDepot::deposer(float somme){

    if(somme > 10000) fraisFermeture += 20;
    else if(somme > 1000) fraisFermeture -= (somme/1000+1);
    else fraisFermeture--;

    Compte::deposer(somme);
}

void CompteDepot::saisir(){
    //CompteDebot& c = *this;
    //cin>>c;
    cout<< "Veuillez saisir information de compte: \n";
    cout<< "Date d'ouverture: \n"; cin>>dateOuverture;
    cout<< "Solde: <<< "; cin >> solde;
    cout<< "Liste des opérations: <<< " <<endl;
    cout<< "Proprietaires: <<< "; cin >> proprietaire;

    cout << "Si vous aimeriez changer les valeurs de:\
              La valeurs minimale necessaire pour ouvrir un compte:\n\
               La valeurs maximale autorise pour un compte depot:\n\
                La valeur des frais de gestion: \
                Tapez >>> 1, sinon tapez >>> 0!: ";
    int cc; cin >> cc;
    if(cc == 1){
        cout<< "Donner la valeurs minimale necessaire pour ouvrir un compte: >>> ";
        cin >> minimale ;
        cout << "Donner la valeurs maximale autorise pour un compte depot: >>> ";
        cin >>  maximale;
        cout << "Donner la valeur des frais de gestion: >>> ";
        cin >>  fraisFermeture;
    }

    compteOuvert[id] = *this;
}

void CompteDepot::afficher(){

        cout<< "Les information de compte: >>> ID= " << id <<endl;
        cout<< "Date d'ouverture: >>> ";
        dateOuverture.affiche();
        cout <<endl;
        cout<< "Solde: " << solde <<endl;
        cout<< "Liste des operations: " <<endl;

        for(auto it = listeOperation.begin(); it != listeOperation.end() ; it++){
            pair<Date, vector<float>> date = *it;
            cout<< " >>> Date: ";
            date.first.affiche();
            cout<< ":\n";
            for(unsigned int i = 0; i < date.second.size(); i++){
                cout << date.second[i] << " ";
            }
            cout<<endl;
        }
        cout << "Proprietaires: >>> ";
        afficheProprietaire();


        cout << "\nLa valeurs minimale necessaire pour ouvrir un compte: >>> "<< minimale <<endl;
        cout << "\nLa valeurs maximale autorise pour un compte depot: >>> "<< maximale <<endl;
        cout << "\nLa valeur des frais de gestion: "<< fraisFermeture <<endl;
}
