#include "compte.h"

class CompteDepot: public Compte{

    float minimale, maximale;
    float fraisFermeture;
public:
    void fermer();
    void deposer();
    void afficher();
    void saisir();
};


void CompteRemunere::calculerInteret(){
    /// 1. calculer la moyenne du solde journalier
    /// pour chaque mois dans la liste des operations
    /// ajouter le solde au mois correspondant
    int operParMois[12];
    for(int i = 0; i < 12; i++) {
            interetMensuel[i] = 0.0;
            operParMois[i] = 0;
    }
    /// calculer les sommes
    for(auto it = listeOperation.begin(); it != listeOperation.end() ; it++){
            pair<Date, vector<float>> date = *it;
            for(unsigned int i = 0; i < date.second.size() ; i++){
                interetMensuel[date.first.mois - 1] += date.second.at(i);
                operParMois[date.first.mois - 1] += 1;
            }
        }
    /// calcules les moyennes et multiplier par le taux
    for(int i = 0; i < 12; i++){
        if(operParMois[i] == 0)
            interetMensuel[i] = 0;
        else
            interetMensuel[i] = (interetMensuel[i]/operParMois[i])*taux;
    }
}

void CompteRemunere::fermer(){
    if(compteOuvert.size()){
        calculerInteret();
        float interet = 0;
        for(int i = 0; i < 12; i++) interet += interetMensuel[i];
        cout << "\nPlus a un interet de = " << interet << endl;
        Compte::fermer();
    }
}


void CompteRemunere::deposer(float somme){
    if(somme > 1000) somme += (somme/1000+1);
    else somme += 1;
    Compte::deposer(somme);
}

void CompteRemunere::saisir(){
    //CompteDebot& c = *this;
    //cin>>c;
    cout<< "Veuillez saisir information de compte: \n";
    cout<< "Date d'ouverture: \n"; cin>>dateOuverture;
    cout<< "Solde: <<< "; cin >> solde;
    cout<< "Liste des opérations: <<< " <<endl;
    cout<< "Proprietaires: <<< "; cin >> proprietaire;
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
