#include "./Arme/Arme_DE_CONTACT/Csword/Csword.h"
#include "./Arme/Arme_DE_CONTACT/Cdagger/Cdagger.h"
#include "./Arme/Arme_De_Distance/CBow/CBow.h"
#include "./Arme/Arme_De_Distance/CStaff/CStaff.h"
#include "./Arme/Cweapon.h"

#include "./Personnage/CCharacter.h"
#include "./Personnage/CArcher/CArcher.h"
#include "./Personnage/CMage/CMage.h"
#include "./Personnage/CRogue/CRogue.h"
#include "./Personnage/CWarrior/CWarrior.h"

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>   
#include <vector>   

using namespace std ;



void lire_les_personnes(string filename){
    fstream file;
    string word;
  
    // filename of the file
    
  
    // opening file
    file.open(filename.c_str());
  
    // extracting words from the file
    while (file >> word)
    {
        // displaying content
        cout << word << endl;
    }

}

void lire_les_armes(string filename){
    fstream file;
    string word;
    vector <string> words;
    vector <Cweapon> persons;

    
    // opening file
    file.open(filename.c_str());
  
    // extracting words from the file
    while (file >> word)
    {
        // displaying content
        words.push_back(word);
    }

    for ( auto &word : words ){
        cout << word << endl;
    }

}


vector <Cweapon>  affectation_armes(){
    vector <Cweapon> liste_des_armes ;
    Cweapon weapon1 , weapon2  , weapon3  , weapon4  , weapon5 , weapon6 , weapon7;
    // pour - 30 : hp est le bonues
    weapon1 = new CStaff("Baguette de Sureau" , 7 , 0.12 , 0, 6 );

    weapon2 = new Csword("Excalibur" , 15 , 0.09 , 0 , 6 , 30 );
    
    weapon3 = new CBow("Gandiva" , 12 , 0.17 , 0 , 6 , 20 );
    
    weapon4 = new Cdagger("Perce-bourse" , 12 , 0.25 , 0 , 220 );
    
    weapon5 = new CBow("Thori'dal" , 10 , 0.12 , 0 , 22 );
    
    weapon6 = new CStaff("Atiesh" , 10 , 0.12 , 0 , 7 );
    
    weapon7 = new Cdagger("Sorcelame" , 12 , 0.24 , 0 , 180 );
 
    liste_des_armes.push_back( weapon1 );
    liste_des_armes.push_back( weapon2 );
    liste_des_armes.push_back( weapon3 );
    liste_des_armes.push_back( weapon4 );
    liste_des_armes.push_back( weapon5 );
    liste_des_armes.push_back( weapon6 );
    liste_des_armes.push_back( weapon7 );
    return liste_des_armes;
}

 vector<CCharacter> affectation_personnes{
      vector <CCharacter> liste_des_caracteres ;
    // pour - 30 : hp est le bonues

    CCharacter carac1 , carac2  , carac3  , carac4 , carac5  , carac6 , carac7 , carac8;

    carac1 = new CMage(weapon6,"Gandalf" ,150 , 0.12 , 23, 13 , 12 , 15 , 20 );

    carac2 = new CWarrior(0.06 , weapon2 , "Leoric" , 230 , 0.12 , 27 , 20 , 34 , 11 , 12);
    
    carac3 = new CArcher( weapon5 , "Sylvanas Coursevent" , 175 , 0.12 , 21 , 14 , 23 , 17 , 12 );
    
    carac4 = new CMage(weapon1 ,  "Jaina Portvaillant" , 125 , 0.12 , 22 , 14 , 14 , 17 , 19  );
    
    carac5 = new CRogue(weapon4 , "Garona" , 170, 0.25 , 19 , 12 , 20, 17 , 9 );
    
    carac6 = new CWarrior(weapon2 , "Xena" , 240 , 0.12 , 19 , 26 , 37 , 12 , 12 );
    
    carac7 = new CRogue(weapon7 , "Jorach Ravenholdt" , 170 , 0.2 , 18 , 11 , 21 , 18 , 9 );
    
    carac8 = new CArcher(weapon3 , "Oliver Queen" , 175 , 0.12 , 22 , 15 , 25 , 16 , 11 );


    liste_des_caracteres.push_back( carac1 );
    liste_des_caracteres.push_back( carac2 );
    liste_des_caracteres.push_back( carac3 );
    liste_des_caracteres.push_back( carac4 );
    liste_des_caracteres.push_back( carac5 );
    liste_des_caracteres.push_back( carac6 );
    liste_des_caracteres.push_back( carac7 );
    liste_des_caracteres.push_back( carac8 );
    return liste_des_caracteres;
}



vector<CCharacter>  selectionEquipe( vector <CCharacter> liste_des_caracteres){
     vector <CCharacter> liste_equipe_1 ;
     for ( int i = 0; i < 3 ; i++){
         // ici on va générer un indice d'une personne 
         int random_number = rand() %  8 ;
         liste_equipe_1.push_back(liste_des_caracteres[random_number]);
    }
}

void afficher_possibilite_actions_warrior(){
    cout << "--------------------------------" << endl;
    cout << "Cliquez sur 1 pour la fonction AttaqueMainsNues" << endl;
    cout << "Cliquez sur 2 pour la fonction AttaqueAvecSonArme" << endl;
    cout << "Cliquez sur 3 pour la fonction associer_bonus" << endl;
    cout << "Cliquez sur 4 pour la fonction reparer" << endl;
    cout << "Cliquez sur 5 pour la fonction reparer_coequipier" << endl;
}

void choix_action_speciale_warrior(char action  , CWarrior cwarrior){

    switch(action){
        case '1' : cwarrior.AttaqueMainsNues() ; break;
        case '2' : cwarrior.AttaqueAvecSonArme() ; break;
        case '3' : cwarrior.Associer_Bonus() ; break;
        case '4' : cwarrior.reparer() ; break;
        case '5' : cwarrior.reparer_coe() ; break;
    }

}

void afficher_possibilite_actions_archer(){
    cout << "--------------------------------" << endl;
    cout << "Cliquez sur 1 pour la fonction AttaqueMainsNues" << endl;
    cout << "Cliquez sur 2 pour la fonction AttaqueAvecSonArme" << endl;
    cout << "Cliquez sur 3 pour la fonction associer bonus" << endl;
    cout << "Cliquez sur 4 pour la fonction guerir" << endl;
    cout << "Cliquez sur 5 pour la fonction viser" << endl;
}

void choix_action_speciale_archer(char action  , CArcher carcher){

    switch(action){
        case '1' : carcher.AttaqueMainsNues() ; break;
        case '2' : carcher.AttaqueAvecSonArme() ; break;
        case '3' : carcher.Associer_Bonus() ; break;
        case '4' : carcher.guerir() ; break;
        case '5' : carcher.viser() ; break;
    }

}

void afficher_possibilite_actions_mage(){
    cout << "--------------------------------" << endl;
    cout << "Cliquez sur 1 pour la fonction AttaqueMainsNues" << endl;
    cout << "Cliquez sur 2 pour la fonction AttaqueAvecSonArme" << endl;
    cout << "Cliquez sur 3 pour la fonction associer_bonus" << endl;
    cout << "Cliquez sur 4 pour la fonction regenerer mana" << endl;
    cout << "Cliquez sur 5 pour la fonction guerir" << endl;
    cout << "Cliquez sur 6 pour la fonction guerir_lui_meme" << endl;
    cout << "Cliquez sur 7 pour la fonction guerir_coequipier" << endl;
    cout << "Cliquez sur 8 pour la fonction enchanter" << endl;
}

void choix_action_speciale_mage(char action  , CMage cmage){

    switch(action){
        case '1' : cmage.AttaqueMainsNues() ; break;
        case '2' : cmage.AttaqueAvecSonArme() ; break;
        case '3' : cmage.Associer_Bonus() ; break;
        case '4' : cmage.regenerer_mana() ; break;
        case '5' : cmage.guerir() ; break;
        case '6' : cmage.guerir_lui_meme() ; break;
        case '7' : cmage.guerir_coequipier() ; break;
        case '8' : cmage.enchanter() ; break;
    }

}

void afficher_possibilite_actions_rogue(){
    cout << "--------------------------------" << endl;
    cout << "Cliquez sur 1 pour la fonction AttaqueMainsNues" << endl;
    cout << "Cliquez sur 2 pour la fonction AttaqueAvecSonArme" << endl;
    cout << "Cliquez sur 3 pour la fonction rendre_furtif" << endl;
    cout << "Cliquez sur 4 pour la fonction empoisoner" << endl;
}

void choix_action_speciale_rogue(char action  , CRogue crogue){

    switch(action){
        case '1' : crogue.AttaqueMainsNues() ; break;
        case '2' : crogue.AttaqueAvecSonArme() ; break;
        case '3' : crogue.rendre_furtif() ; break;
        case '4' : crogue.empoisoner() ; break;
    }

}





void choix_actions_possible_pour_cette_personne(CCharacter ccharacter){
    char * nom = typeid(ccharacter).name();
    char action ;
    switch(nom){
        case 'CRogue': afficher_possibilite_actions_rogue() ; cin>>action ; choix_action_speciale_rogue(action ,ccharacter); break;
        case 'CWarrior': afficher_possibilite_actions_warrior() ; cin >> action ; choix_action_speciale_warrior(action ,ccharacter); break;
        case 'CArcher': afficher_possibilite_actions_archer() ; cin >> action ; choix_action_speciale_archer(action ,ccharacter); break;
        case 'CMage': afficher_possibilite_actions_mage() ; cin >> action ; choix_action_speciale_mage(action ,ccharacter); break;
    }

}

void deroulement_du_jeu(CCharacter[] liste_des_caracteres , Cweapon[] listte_des_armes){
     vector<CCharacter> liste_des_caracteres = affectation_personnes();
     vector<Cweapon> liste_des_armes = affectation_armes();
     vector<CCharacter> equipe1 = selectionEquipe(liste_des_caracteres); 
     vector<CCharacter> equipe2 = selectionEquipe(liste_des_caracteres); 
     bool game_termine = false ;
     char choix_action_speciale = '';
     int vainquer_equipe_1 = 0 ;
     int vainquer_equipe_2 = 0 ;

     
         for ( int i = 0; i < 3 ; i++ ){
             int nombre_tours_membre_equipe1= equipe1[i].vitesse - 1;
             int nombre_tours_membre_equipe2= equipe2[i].vitesse - 1;
             if ( equipe1[i].vitesse < equipe2[i].vitesse ){
                while(equipe1[i].EnVieOuNon() && equipe2[i].EnVieOuNon() ){
                    cout << " le membre " << i << " de l equipe 1 va commencer " << endl;
                    if (nombre_tours_membre_equipe1 ){choix_actions_possible_pour_cette_personne(equipe1[i]); nombre_tours_membre_equipe1--;}
                    cout << " le membre " << i << " de l equipe 2 va jouer " << endl;
                    if (nombre_tours_membre_equipe2 ){choix_actions_possible_pour_cette_personne(equipe2[i]); nombre_tours_membre_equipe2--;}
                    if ( nombre_tours_membre_equipe2==0 && nombre_tours_membre_equipe1==0 ) break;
                }
             }
             else {

                while(equipe1[i].EnVieOuNon() && equipe2[i].EnVieOuNon()){
                    cout << " le membre " << i << " de l equipe 2 va commencer " << endl;
                    if (nombre_tours_membre_equipe2 ){choix_actions_possible_pour_cette_personne(equipe2[i]); nombre_tours_membre_equipe2--;}
                    cout << " le membre " << i << " de l equipe 1 va jouer " << endl;
                    if (nombre_tours_membre_equipe1 ){choix_actions_possible_pour_cette_personne(equipe1[i]); nombre_tours_membre_equipe1--;}
                    if ( nombre_tours_membre_equipe2==0 && nombre_tours_membre_equipe1==0 ) break;
                }

                }

                if(equipe1[i].EnVieOuNon()) {
                 vainquer_equipe_1++;
                }
                else if(equipe2[i].EnVieOuNon()) {
                    vainquer_equipe_2++;
                }

             }

            if ( vainquer_equipe_1 == vainquer_equipe_) cout << "  MATCH NUL ! " << endl;
            else if ( vainquer_equipe_1 < vainquer_equipe_2) cout " EQUIPE 2 A GAGNE !!" << endl;
            else cout << " EQUIPE 1 A GAGNE !!" << endl;

}


int main(){


    srand (time(NULL));
    char yes_or_no;

    // ici on va lire le fichier texte qu'on a dans le dossier

    bool jeu_en_cours = true ;
    while(jeu_en_cours){

        cout << "********" << endl;
        cout << " Le Jeu est juste commencé " << endl;
        cout << "********" << endl;
        
        deroulement_du_jeu();

        cout << "********" << endl;
        cout << "le jeu est juste terminée "  << endl;
        cout << "********" << endl;

        cout << "voulez vous repeter ? Y pour oui et N pour non" << endl;
        cin >> yes_or_no ;

        if (yes_or_no =='Y') jeu_en_cours= true ;
        else jeu_en_cours= false ;

    }

    return 0 ;
}