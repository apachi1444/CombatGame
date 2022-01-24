#include "./CCharacter.h"
using namespace std;
#include <string>


 
// void Personnage::attaqueMainsNues(Personnage &cible) const
// {
//     cible.recevoirDegats(10);
// }

CCharacter::CCharacter( Cweapon cweapon, string nom,int valeur_vie,int valeur_esquive ,int vitesse ,int val_attaque,int val_defense,
        int val_agilite,int val_intelligence ){
             this->nom = nom;
             this->valeur_vie = valeur_vie;
             this->valeur_esquive = valeur_esquive;
             this->vitesse = vitesse;
             this->val_attaque = val_attaque;
             this->val_defense = val_defense;val_attaque;
             this->val_agilite= val_agilite;
             this->val_intelligence = val_intelligence;
             this->valeur_vie_init = valeur_vie;
             this->cweapon = cweapon;
}
void CCharacter::attaqueMainsNues(CCharacter &adversaire){
    double coef = rand() % 1 ;
    double degat = 15 * val_attaque * coeff / adversaire.val_defense;
    adversaire.valeur_vie -= degat*(1-adversaire.valeur_esquive) ;
}



bool CCharacter::EnVieOuNon(){
    if ( valeur_vie <= 0 ){
        valeur_vie =0;
        this->~CCharacter();
        delete this;
        return false;
    }
    return true ;
}
