// Cmelee.h
#ifndef CRanged
#define CRanged
#include<string>
#include "../Cweapon.h"
#include "../../Personnage/CMage/CMage.h"
using namespace std;
    class CRanged : public Cweapon
    {
        
    public:
        double consommable;
    
        //Constructeur
        CRanged(string nom, double degat, double val_critique, double val_bonus, double consomme) ;
        virtual void utiliser_cet_arme(CMage & posseseur = NULL) = 0
        virtual void fin_consommable(CMage & posseseur = NULL) = 0
        
    };
#endif