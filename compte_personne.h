#include "compte.h"

class ComptePersonne: public Compte{

    int valeurDecouvert; /// nombre de jours
public:
    void afficher();
    void saisir();
};

