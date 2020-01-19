#ifndef H_GEST
#define H_GEST
#include<ctime>

#include "date.h"
#include "compte.h"
#include "compte_depot.h"
#include "compte_remunere.h"
#include "compte_personne.h"
#include "compte_entreprise.h"
#include "compte_depot_personne.h"
#include "compte_depot_entreprise.h"
#include "compte_remunere_personne.h"
#include "compte_remunere_entreprise.h"
#include "compte_depot_remunere_personne.h"
#include "compte_depot_remunere_entreprise.h"

class GestionComptes{
public:

    /// (a) ouverture des comptes
    void ouvreUnCompte(){
        encore:
        cout << "############################################################\n";
        cout << "####                                                     ###\n";
        cout << "####         ----> Quelle type du compte? <----          ###\n";
        cout << "####\t\t1. Compte depot;                         ###\n";
        cout << "####\t\t2. Compte remunere;                      ###\n";
        cout << "####\t\t3. Compte personne;                      ###\n";
        cout << "####\t\t4. Compte entreprise;                    ###\n";
        cout << "####\t\t5. Compte depot personne;                ###\n";
        cout << "####\t\t6. Compte depot entreprise;              ###\n";
        cout << "####\t\t7. Compte remunere personne;             ###\n";
        cout << "####\t\t8. Compte remunere entreprise;           ###\n";
        cout << "####\t\t9. Compte depot remunere personne;       ###\n";
        cout << "####\t\t10. Compte depot remunere entreprise;    ###\n";
        cout << "####                                                     ###\n";
        cout << "############################################################\n";
        cout << "\t\t=====> Veuilez saisir votre choix: \n";
        cout << "\t\t=====> choix: ";
        int choix; cin >> choix;

        switch(choix){
        case 1:
            /// code
            {
                CompteDepot c;
                c.ouvrir();
                c.saisir();
                /* c.deposer(100); c.retirer(100); c.afficher(); c.fermer();*/
            }
            break;
        case 2:
            /// code
            {
                CompteRemunere c;
                c.ouvrir();
                c.saisir();
                c.deposer(100);
                c.retirer(100);
                c.afficher();
                c.fermer();
            }
            break;
        case 3:
            /// code
            {
                ComptePersonne c;
                c.ouvrir();
                c.saisir();
                c.deposer(1000);
                c.retirer(1000);
                c.afficher();
                c.fermer();
            }
            break;
        case 4:
            {

                cout << "Vous etres sur le point de creer un compte entreprise!\n" << endl;
                cout << "Veuillez saisir la liste des personnes autorises a faire de retraits.\n";
                cout << "===> donner le nombre des personnes: ";
                int nbrPer; cin >> nbrPer;
                cout << "===> donner le nom complet des personnes a raison d'une par ligne:\n ";
                vector<string> dd(nbrPer);
                for(int i = 0; i < nbrPer; i++) getline(cin, dd[i]);
                cout << "Creation...";

                CompteEntreprise c(&dd);
                c.ouvrir();
                c.saisir(NULL);
                c.deposer(1000);
                c.retirer(1000);
                c.afficher();
                c.fermer();
            }
            break;
        case 5:
            {
                CompteDepotPersonne c;
                c.ouvrir();
                c.saisir();
                c.deposer(1000);
                c.retirer(1000);
                c.afficher();
                c.fermer();
            }
            break;
        case 6:
            {
               /// code
                cout << "Vous etres sur le point de creer un compte entreprise!\n" << endl;
                cout << "Veuillez saisir la liste des personnes autorises a faire de retraits.\n";
                cout << "===> donner le nombre des personnes: ";
                int nbrPer; cin >> nbrPer;
                cout << "===> donner le nom complet des personnes a raison d'une par ligne:\n ";
                vector<string> dd(nbrPer);
                for(int i = 0; i < nbrPer; i++) getline(cin, dd[i]);
                cout << "Creation...";

                CompteDepotEntreprise c(&dd);
                c.ouvrir();
                c.saisir(NULL);
                /*c.deposer(1000); c.retirer(1000); c.afficher(); c.fermer();*/
            }
            break;
        case 7:
            {
                CompteRemunerePersonne c;
                c.ouvrir();
                c.saisir();
                /*c.deposer(1000); c.retirer(1000); c.afficher(); c.fermer();*/
            }
            break;
        case 8:
            {
               /// code
            cout << "Vous etres sur le point de creer un compte entreprise!\n" << endl;
            cout << "Veuillez saisir la liste des personnes autorises a faire de retraits.\n";
            cout << "===> donner le nombre des personnes: ";
            int nbrPer; cin >> nbrPer;
            cout << "===> donner len nom complet des personnes a raison d'une par ligne:\n ";
            vector<string> dd(nbrPer);
            for(int i = 0; i < nbrPer; i++) getline(cin, dd[i]);
            cout << "Creation...";

            CompteEntreprise c(&dd);
            c.ouvrir();
            c.saisir(NULL);
            /*c.deposer(1000); c.retirer(1000); c.afficher(); c.fermer();*/
            }
            break;
        case 9:
            {
                CompteDepotRemunerePersonne c;
                c.ouvrir();
                c.saisir();
                /*c.deposer(1000); c.retirer(1000); c.afficher(); c.fermer();*/
            }
            break;
        case 10:
            {
               /// code
            cout << "Vous etres sur le point de creer un compte entreprise!\n" << endl;
            cout << "Veuillez saisir la liste des personnes autorises a faire de retraits.\n";
            cout << "===> donner le nombre des personnes: ";
            int nbrPer; cin >> nbrPer;
            cout << "===> donner le nom complet des personnes a raison d'une par ligne:\n ";
            vector<string> dd(nbrPer);
            for(int i = 0; i < nbrPer; i++) getline(cin, dd[i]);
            cout << "Creation...";

            CompteDepotRemunereEntreprise c(&dd);
            c.ouvrir();
            c.saisir(NULL);
            /*c.deposer(1000);c.retirer(1000);c.afficher();c.fermer();*/
            }
            break;
        default:
            cout << "Choix non valide!"; goto encore;
        }
    }

/****************************************** (b) deposer un somme *****************************/

    void deposerUnSomme(){

         cout << "Voici la liste des IDs des comptes ouverts:\n";
         for(unsigned int i= 0; i < Compte::compteOuvert.size(); i++){
            cout << Compte::compteOuvert[i].getId() <<", ";
         }

         cout << "Veuillez choisir votre ID: ";
         int id; cin >> id;
         cout << "Veuillez saisir la somme a deposer: ";
         float somme; cin >> somme;
         Compte::compteOuvert[id].deposer(somme);
    }

/********************** (c) affichage des opération de mois en cours *********************/

    void afficherDesOperationDeMoisCourant(){

         cout << "Voici la liste des IDs des comptes ouverts:\n";
         for(unsigned int i= 0; i < Compte::compteOuvert.size(); i++){
            cout << Compte::compteOuvert[i].getId() <<", ";
         }

         cout << "\nVeuillez choisir votre ID: ";
         int id; cin >> id;
         cout << "Voici la liste des operation de mois en cours: \n";
         /// TODO
         char moisEnCours[3];
         time_t t = time(0);
         strftime(moisEnCours, 3, "%m", localtime(&t));
         auto fin = Compte::compteOuvert[id].getListeDesOperation().end();
         for(auto it = Compte::compteOuvert[id].getListeDesOperation().begin(); it != fin ; it++){
            pair<Date, vector<float>> date = *it;
            if(atoi(moisEnCours) == date.first.mois){
                cout<< " >>> Date: ";
                date.first.affiche();
                cout<< ":\n";
                cout << "Operations: ";
                for(unsigned int ii = 0; ii < date.second.size(); ii++){
                    cout << date.second[ii] << " ";
                }
                cout<<endl;
            }
        }
    }


/****************** (d) afficher la liste des comptes ouverts (+infos) *******************/

    void afficherListesDesComptes(){
         cout << "Voici la liste des comptes ouverts:\n";
         for(unsigned int i= 0; i < Compte::compteOuvert.size(); i++){
            cout << Compte::compteOuvert[i];
            cout <<"\n______________________________________________________________\n ";
         }
    }

/********************* (e) afficher les informations concernant des propriétaires d'un compte */

    void afficherLesInfoDesProprietaires(){
         cout << "Voici la liste des IDs comptes ouverts avec leurs proprietaires:\n";
         for(unsigned int i= 0; i < Compte::compteOuvert.size(); i++){
            cout << "ID: "<< Compte::compteOuvert[i].getId() <<"\n";
            cout << "Proprietaires: ";
            Compte::compteOuvert[i].afficheProprietaire();
            cout <<"\n";
            cout <<"\n______________________________________________________________\n ";
         }
    }
/************************** (f) chercher un compte selon: nom, prénom et date ***************/
                        ///     de naissance de l'un de ses propriétaires
    void chercherUnCompte(){
        cout << "Veuillez saisir le nom, prénom et date de naissance de ses propriétaires:\n";
        cout << "FORMAT: (PERSO ou ENTER) NOM PRENOM DATENAISSANCE:\n";
        cout << "Exemple Personne: PERSO ALI MOHAMED 17/01/1942\n";
        cout << "Exemple Personne: ENTER MICROSOFT 26/11/1976\n";
        string info;
        cin.ignore();
        getline(cin, info);
        for(unsigned int i= 0; i < Compte::compteOuvert.size(); i++){
            if(Compte::compteOuvert[i].getProprietaires() == info){
                cout << Compte::compteOuvert[i];
                break;
            }
         }

    }

/****************** (g) fermer un compte en donnant la liste de ses propriétaires **********/
    void fermerUnCompte(){
        cin.ignore(); /// vider le buffer
        cout << "Vous etres sur le point de fermer un compte!\n" << endl;
        cout << "Veuillez saisir le nom de ses propriétaires:\n ";
        cout << "FORMAT: (PERSO ou ENTER) NOM PRENOM DATENAISSANCE\n";
        string proprietaires;
        getline(cin, proprietaires);
        for(unsigned int i= 0; i < Compte::compteOuvert.size(); i++){
            if(Compte::compteOuvert[i].getProprietaires() == proprietaires){
                Compte::compteOuvert[i].fermer();
                break;
            }
         }
    }
/***************** (h) fermer des comptes ****************************/
    void fermerDesComptes(){
        while(Compte::compteOuvert.size() > 0){
                Compte::compteOuvert[0].fermer();
         }
    }

};

#endif // H_GEST
