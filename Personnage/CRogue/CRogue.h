#ifndef DEF_ROGUE
#define DEF_ROGUE
 
#include <iostream>
#include <string>
#include "../CCharacter.h"

//Ne pas oublier d'inclure Personnage.h pour pouvoir en hériter !
 
class CRogue : public CCharacter
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
    public :
        double val_special = 0.0;

        int dernier_tour_utiliser_bonus = 0 ;

        bool CacheOuNon;
        void Associer_Bonus();
        void empoisoner(CCharacter & adversaire);
        void rendre_furtif();
};
 
#endif