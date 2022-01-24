#include "./CStaff.h"
#include<string>
#include<iostream>
using namespace std;


    void CStaff::utiliser_cet_arme(CMage & possessur) {
            possessur.val_speciale -= (*this).consommable;
        }

    void CStaff::fin_consommable(CMage & possessur){
        if ( possessur.val_speciale <= 0  ){
            (*this).~CStaff();
        }
    }

    //Destructeur
    
    ~CStaff() {
        cout<<"Veuillez Recharger Du Mana"<<endl;
    }