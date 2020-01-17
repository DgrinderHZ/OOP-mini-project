#include <iostream>
#include "compte.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Compte c;
    c.ouvrir();
    cin >> c;

    c.deposer(100);
    //c.deposer(100);
    c.retirer(100);
    cout << c;
    c.fermer();
    return 0;
}
