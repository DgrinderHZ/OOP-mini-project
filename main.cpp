#include <iostream>
#include "gestion.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    GestionComptes gerer;
    cout << "\n############### ouvrir une compte?\n";
    gerer.ouvreUnCompte();
    cout << "\n############### deposerUnSomme()?\n";
    gerer.deposerUnSomme();
    cout << "\n############### afficherDesOperationDeMoisCourant()?\n";
    gerer.afficherDesOperationDeMoisCourant();
    cout << "\n############### afficherLesInfoDesProprietaires()?\n";
    gerer.afficherLesInfoDesProprietaires();
    cout << "\n############### afficherListesDesComptes()?\n";
    gerer.afficherListesDesComptes();
    cout << "\n############### chercherUnCompte()?\n";
    gerer.chercherUnCompte();
    cout << "\n############### ouvreUnCompte()?\n";
     gerer.ouvreUnCompte();
    cout << "\n############### deposerUnSomme()?\n";
    gerer.deposerUnSomme();
    cout << "\n############### afficherDesOperationDeMoisCourant()?\n";
    gerer.afficherDesOperationDeMoisCourant();
    cout << "\n############### afficherLesInfoDesProprietaires()?\n";
    gerer.afficherLesInfoDesProprietaires();
    cout << "\n############### afficherListesDesComptes()?\n";
    gerer.afficherListesDesComptes();
    cout << "\n############### chercherUnCompte()?\n";
    gerer.chercherUnCompte();
    cout << "\n############### fermerDesComptes()?\n";
    gerer.fermerDesComptes();
    return 0;
}
