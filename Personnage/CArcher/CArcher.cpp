#include "./CArcher.h"
using namespace std;
#include <string>


// void Personnage::attaqueMainsNues(Personnage &cible) const
// {
//     cible.recevoirDegats(10);
// }



void CArcher::Associer_Bonus(){
    valeur_esquive += valeur_special;
}


void CArcher::attaqueAvecSonArme(CCharacter & adversaire){
    // entre 1 et 0/85
    double coeff =(double) (rand() % ((int)(0.15*RAND_MAX)))/RAND_MAX  + 0.85;

    double degat = 7 * ( (*this).val_agilite + ( (*this).cweapon.Val_Degat) )  * coeff / adversaire.val_defense;

    adversaire.Durabilité -= degat;

    adversaire.EnVieOuNon();

}

void CArcher::guerir(CCharacter & coequiper){
    if ( nombre_guerir <= 0 ) {
        cout << "tu peux plus guérir ton coequipier" << endl;
    }
    else{
        coequiper.valeur_vie = coequiper.valeur_vie_init;
        nombre_guerir--;
    }
}


void CArcher::viser(){
    if ( cweapon.getConsommable() <=0){

        (*this).val_agilite *= 1.33
    }

    else {

        (*this).val_agilite *= 1;

    }
}



