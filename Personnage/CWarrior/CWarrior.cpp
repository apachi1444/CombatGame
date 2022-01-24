#include "./CWarrior.h"
#include "../CCharacter.h"
#include "../../Arme/Cweapon.h"
using namespace std;
#include <string>


// void Personnage::attaqueMainsNues(Personnage &cible) const
// {
//     cible.recevoirDegats(10);
// }

CWarrior::CWarrior( int valeur_special , Cweapon cweapon ,string nom,int valeur_vie,int valeur_esquive ,int vitesse ,int val_attaque,int val_defense,
        int val_agilite,int val_intelligence):CCharacter( nom, valeur_vie, valeur_esquive , vitesse , val_attaque, val_defense,
         val_agilite, val_intelligence , cweapon )
{
    this->valeur_special = valeur_special;
}


void CWarrior::Associer_Bonus(){
    valeur_esquive += valeur_special;
}


void CWarrior::reparer(){

    if ( cweapon.casse_ou_none()){
        cweapon.Durabilite++;
    }

    else{
        
        while(cweapon.Durabilite < cweapon.Durabilite_Init){
            int var  = rand() % 15 + 3 ;
            cweapon.Durabilite+=var;
        
        }
    }
}

 void CWarrior::reparer_coe(CCharacter & coequipier){
     if ( coequipier.cweapon.casse_ou_none()){
         coequipier.cweapon.Durabilite++;
    }

    else{
        
        while( coequipier.cweapon.Durabilite <  coequipier.cweapon.Durabilite_Init){
            int var  = rand() % 15 + 3 ;
             coequipier.cweapon.Durabilite+=var;
        
        }
    }
 }


void CWarrior::attaqueAvecSonArme(CCharacter & adversaire){
    // entre 1 et 0/85
    double coeff = (double) (rand() % ((int)(0.15*RAND_MAX)))/RAND_MAX  + 0.85;

    double degat = 7 * ( (*this).val_agilite + ( (*this).cweapon.Val_Degat) )  * coeff / adversaire.val_defense;

    adversaire.Durabilité -= degat;

    adversaire.EnVieOuNon();

}


void CWarrior::hurler(CCharacter & adversaire , int nombre_tours_actuel_du_jeu){
    
    if (  dernier_tour_utiliser_bonus == 0 || nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus >= 4) {
        dernier_tour_utiliser_bonus = nombre_tours_actuel_du_jeu;
        // le traitement du bonus de la personne
    }

    else{
        int tours_restants = 4 - (nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus);
        cout << "Désolé tu peux pas utilser ce bonus ! il faut attendre encore " << tours_restants << endl; 
    }

}


