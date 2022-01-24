#include "./CMage.h"
using namespace std;
#include <string>


// void Personnage::attaqueMainsNues(Personnage &cible) const
// {
//     cible.recevoirDegats(10);
// }

CMage::CMage( Cweapon cweapon ,string nom,int valeur_vie,int valeur_esquive ,int vitesse ,int val_attaque,int val_defense,
        int val_agilite,int val_intelligence ):CCharacter( nom, valeur_vie, valeur_esquive , vitesse , val_attaque, val_defense,
         val_agilite, val_intelligence , Cweapon cweapon)
{}





void CMage::Associer_Bonus(){
    valeur_esquive += valeur_special;
}



void CMage::attaqueAvecSonArme(CCharacter & adversaire){
    // entre 1 et 0/85
    double coeff =(double) (rand() % ((int)(0.15*RAND_MAX)))/RAND_MAX  + 0.85;

    double degat = 5 * ( (*this).val_intelligence + ( (*this).cweapon.Val_Degat) )  * coeff / adversaire.val_defense;

    adversaire.Durabilité -= degat;

    adversaire.EnVieOuNon();

}


void CMage::regenerer_mana(){
    
    int valeur_ajoutée = rand() % 5 + 2 ;
    val_speciale+=valeur_ajoutée;
    

}


bool CMage::guerir(){
    
    if ( (string) typeid(&cweapon).name() == "CStaff"){
        val_speciale-=5 ;
        return true ;
    }
    return false ;
}

void CMage::guerir_lui_meme(int nombre_tours_actuel_du_jeu){

     if (  dernier_tour_utiliser_bonus_soigner == 0 || nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus_soigner >= 4) {
        dernier_tour_utiliser_bonus_soigner = nombre_tours_actuel_du_jeu;
        // le traitement du bonus de la personne
        if(guerir())
        valeur_vie = valeur_vie_init ;
    }

    else{
        int tours_restants = 4 - (nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus_soigner);
        cout << "Désolé tu peux pas utilser ce bonus ! il faut attendre encore " << tours_restants << endl; 
    }
    

}


void CMage::guerir_coequipier(CCharacter & coequip){
     if (  dernier_tour_utiliser_bonus_soigner == 0 || nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus_soigner >= 4) {
        dernier_tour_utiliser_bonus_soigner = nombre_tours_actuel_du_jeu;
        // le traitement du bonus de la personne
        if (guerir()){
        int valeur_ajoutée = rand() % 20 + 10 ;
        coequip.valeur_vie += valeur_ajoutée;
        if ( coequip.valeur_vie > coequip.valeur_vie_init ) coequip.valeur_vie_init = coequip.valeur_vie_init; 
        }
    }
    }

    else{
        int tours_restants = 4 - (nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus_soigner);
        cout << "Désolé tu peux pas utilser ce bonus ! il faut attendre encore " << tours_restants << endl; 
    }



void CMage::enchanter(CCharacter & coequip = NULL){
     if (  dernier_tour_utiliser_bonus_enchanter == 0 || nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus_enchanter >= 3) {
        dernier_tour_utiliser_bonus_soigner = nombre_tours_actuel_du_jeu;
        // le traitement du bonus de la personne
        if ( coequip == NULL ) (*this).val_attaque *= 4/3;
        else{
            coequip.val_attaque *= 4/3;
        }
    }

    else{
        int tours_restants = 3 - (nombre_tours_actuel_du_jeu - dernier_tour_utiliser_bonus_enchanter);
        cout << "Désolé tu peux pas utilser ce bonus ! il faut attendre encore " << tours_restants << endl; 
    }
}


