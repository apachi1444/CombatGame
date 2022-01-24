#ifndef DEF_WARRIOR
#define DEF_WARRIOR
 
#include <iostream>
#include <string>
#include "../CCharacter.h"

//Ne pas oublier d'inclure Personnage.h pour pouvoir en hériter !
 
class CWarrior : public CCharacter
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
    

    public :
        double val_special = 0.0;
        // pour dire qu'on a pas encore utilisé le bonus de cette personne
        int dernier_tour_utiliser_bonus = 0 ;
        void Associer_Bonus();
        void hurler();
        // les siennes et celles de ses coeequipiers
        void reparer();
        void reparer_coe(CCharacter & coeequipier);
        
};
 
#endif