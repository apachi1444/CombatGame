#include "./CRogue.h"
#include "../CCharacter.h"
#include "../../Arme/Cweapon.h"
using namespace std;
#include <string>


// void Personnage::attaqueMainsNues(Personnage &cible) const
// {
//     cible.recevoirDegats(10);
// }

CRogue::CRogue( int valeur_special ,string nom,int valeur_vie,int valeur_esquive ,int vitesse ,int val_attaque,int val_defense,
        int val_agilite,int val_intelligence , Cweapon cweapon):CCharacter( nom, valeur_vie, valeur_esquive , vitesse , val_attaque, val_defense,
         val_agilite, val_intelligence , cweapon )
{
    this->valeur_special = valeur_special;
}


void CRogue::attaqueAvecSonArme(CCharacter & adversaire){
    // entre 1 et 0/85
    double coeff = (double) (rand() % ((int)(0.15*RAND_MAX)))/RAND_MAX  + 0.85;

    double degat = 7 * ( (*this).val_agilite + ( (*this).cweapon.Val_Degat) )  * coeff / adversaire.val_defense;

    adversaire.Durabilité -= degat;

    adversaire.EnVieOuNon();

}
void CRogue::rendre_furtif( int nombre_tours_actuel_du_jeu){
     if (  dernier_tour_utiliser_bonus == 0 || nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus >= 4) {
        dernier_tour_utiliser_bonus = nombre_tours_actuel_du_jeu;
        // le traitement du bonus de la personne
        // de 1  a  2 tours
        (*this).CacheOuNon  = true ;
    }

    else{
        int tours_restants = 4 - (nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus);
        cout << "Désolé tu peux pas utilser ce bonus ! il faut attendre encore " << tours_restants << endl; 
    }

}
void CRogue::empoisoner(CCharacter & adversaire){
  
    if ( (string) typeid(&cweapon).name() == "CDagger"){
        adversaire.valeur_vie *= 11/12; 
        adversaire.EnVieOuNon();
    }

}


