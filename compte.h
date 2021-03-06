#ifndef H_COMPTE
#define H_COMPTE

#include<istream>
#include<ostream>
#include<iostream>
#include<map>
#include<vector>

#include "date.h"

using namespace std;

class Compte{

protected:
    int id;
    float solde;
    string proprietaire;
    Date dateOuverture;
    map<Date, vector<float> > listeOperation;

public:
    static vector<Compte> compteOuvert;
    int getId(){ return id; }

    string getProprietaires(){ return proprietaire; }
    map<Date, vector<float> >& getListeDesOperation(){
        return listeOperation;
    }
    void ouvrir();
    void deposer(float montant);
    void retirer(float montant);
    void afficheProprietaire();
    void fermer();

    friend ostream& operator<<(ostream& os, Compte& c){
        cout << "\n************ AFFICHAGE COMPTE ****************\n";
        cout<< "Les information de compte: >>> " << c.id <<endl;
        cout<< "Date d'ouverture: >>> ";
        c.dateOuverture.affiche();
        cout <<endl;
        cout<< "Solde: " << c.solde <<endl;
        cout<< "Liste des operations: " <<endl;

        for(auto it = c.listeOperation.begin(); it != c.listeOperation.end() ; it++){
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
        c.afficheProprietaire();
    return os;
    }

    friend istream& operator>>(istream& is, Compte& c){
        cout << "\n************ SAISIE COMPTE ****************\n";
        cout<< "Veuillez saisir information de compte: \n";
        cout<< "Date d'ouverture: \n"; cin>>c.dateOuverture;
        cout<< "Solde: <<< "; cin >> c.solde;
        cout<< "Liste des opérations: <<< " <<endl;
        cout<< "Proprietaires: <<< ";
        cout << "FORMAT: (PERSO ou ENTER) NOM PRENOM DATENAISSANCE:\n";
        cout << "Exemple Personne: PERSO ALI MOHAMED 17/01/1942\n";
        cout << "Exemple Entreprise: ENTER MICROSOFT 26/11/1976\n";
        cin.ignore(); /// vider le buffer
        getline(cin, c.proprietaire);
        c.compteOuvert[c.id] = c;
        return is;
    }

};

vector<Compte> Compte::compteOuvert;

void Compte::ouvrir(){
    cout << "\n************ OUVERTURE COMPTE ****************\n";
        id = compteOuvert.size();
        compteOuvert.push_back(*this);
}

void Compte::fermer(){
    cout << "\n************ FERMETURE COMPTE ****************\n";
    if(compteOuvert.size()){
        cout << "\n !!!!!! La banque doit rendre: solde = " << compteOuvert[id].solde << endl;
        compteOuvert.erase(compteOuvert.begin()+id);
    }
}


void Compte::afficheProprietaire(){
    cout << proprietaire;
}


void Compte::deposer(float somme){
    cout << "\n************ DEPOSER SOMME ****************\n";
    solde += somme;

    Date date;
    cout<< "Saisir la date d'operation: \n";
    cin >> date;

    vector<float> tmp = listeOperation[date];
    tmp.push_back(somme);
    listeOperation[date] = tmp;
    compteOuvert[id] = *this;
}

void Compte::retirer(float somme){
    cout << "\n************ RETIRER SOMME ****************\n";
    if(solde >= somme){
        solde -= somme;

        Date date;
        cout<< "Saisir la date d'operation: \n";
        cin >> date;

        vector<float> tmp = listeOperation[date];
        tmp.push_back(-somme);
        listeOperation[date] = tmp;
        compteOuvert[id] = *this;
    }
}

#endif // H_COMPTE
