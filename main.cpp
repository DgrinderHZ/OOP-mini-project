#include <iostream>
#include "compte_remunere.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    CompteRemunere c;
    c.ouvrir();
    c.saisir();

    c.deposer(100);
    //c.deposer(100);
    c.retirer(100);
    c.afficher();
    c.fermer();
    return 0;
}
