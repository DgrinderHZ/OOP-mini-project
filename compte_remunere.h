#ifndef H_CRENUM
#define H_CRENUM

#include "compte.h"

class CompteRemunere: virtual public Compte{
protected:
    static float taux;
    float interetMensuel[12];
public:
    void calculerInteret();
    void fermer();
    void deposer(float);
    void afficher();
    void saisir();
};
float CompteRemunere::taux = 0.2;

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
    cin >> *this;
    compteOuvert[id] = *this;
}

void CompteRemunere::afficher(){
        cout << *this;

        calculerInteret();
        cout << "\nTaux de remuneration: >>> "<< taux <<endl;
        cout << "Interet mensuels: >>> MOIS(INTERET)\n";
        for(int i = 0; i < 12; i++) cout << i<<"(" << interetMensuel[i] <<")"<< "| ";
}


#endif // H_CRENUM
