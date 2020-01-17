#include "compte.h"

class CompteDepot: public Compte{

    static float minimale, maximale;
    static float fraisFermeture;
public:
    void fermer();
    void deposer();
    void afficher();
    void saisir();
};
