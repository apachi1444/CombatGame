#ifndef Personnage
#define Personnage
#include "../Arme/Cweapon.h"
 
#include <iostream>
#include <string>

using namespace std ;
 
class CCharacter
{
    
    public:
        Cweapon cweapon ;
        string nom ;
        int valeur_vie;
        int valeur_vie_init;
        int valeur_esquive  ;
        int vitesse ;
        int val_attaque ;
        int val_defense ;
        int val_agilite;
        int val_intelligence;
        void attaqueMainsNues(CCharacter &adversaire) ;
        virtual void attaqueAvecSonArme(CCharacter &adversaire) = 0;
        bool EnVieOuNon();
        
        // void esquiver_attaque(CCharacter &adversaire);
};
 
#endif