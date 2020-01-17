#include "compte.h"

class CompteRemunere: public Compte{

    static float taux;
    float interetMensuel[12];
public:
    void calculerInteret();
    void fermer();
    void deposer();
    void afficher();
    void saisir();
};
