#include <iostream>
#include "gestion.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    GestionComptes gerer;

    gerer.ouvreUnCompte();
    gerer.deposerUnSomme();
    gerer.afficherDesOperationDeMoisCourant();
    gerer.afficherLesInfoDesProprietaires();
    gerer.afficherListesDesComptes();
    gerer.chercherUnCompte();
    gerer.fermerUnCompte();
    return 0;
}
