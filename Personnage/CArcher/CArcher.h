#ifndef DEF_ARCHER
#define DEF_ARCHER
 
#include <iostream>
#include <string>
#include "../CCharacter.h"
#include "../../Arme/Cweapon.h"

//Ne pas oublier d'inclure Personnage.h pour pouvoir en hériter !
 
class CArcher : public CCharacter
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
     

    public :
        double val_special = 0.0;
        int nombre_guerir = 3 ;
        void Associer_Bonus();
        void hurler();
        // les siennes et celles de ses coeequipiers
        void guerir(CCharacter & coeequipier);
        void viser();
};
 
#endif