#include <iostream>
#include "compte_depot_entreprise.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<string> dd(2);
    cin >> dd[0];
    cin >> dd[1];
    CompteDepotEntreprise c(&dd);
    c.ouvrir();
    c.saisir(NULL);

    c.deposer(100);
    //c.deposer(100);
    c.retirer(100);
    c.afficher();
    c.fermer();
    return 0;
}
