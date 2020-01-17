#include "compte.h"
#include<string>

class CompteEntreprise: public Compte{

    vector<string> personneAutorises;
public:
    void afficher();
    void saisir();
};

