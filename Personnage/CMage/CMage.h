#ifndef DEF_MAGE
#define DEF_MAGE
 
#include <iostream>
#include <string>
#include "../CCharacter.h"
#include "../../Arme/Cweapon.h"


//Ne pas oublier d'inclure Personnage.h pour pouvoir en hériter !
 
class CMage : public CCharacter
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
    

    public :
        double val_speciale = 10 * (*this).val_intelligence;

        // pour dire qu'on a pas encore utilisé le bonus de cette personne
        int dernier_tour_utiliser_bonus_soigner = 0 
        int dernier_tour_utiliser_bonus_enchanter = 0 

        //ceci pour la partie disparu du voleur

        void Associer_Bonus();
        void regenerer_mana();
        bool guerir();
        void enchanter(); 
        void guerir_lui_meme();
        void guerir_coequipier(CCharacter &coequip);


          
};
 
#endif