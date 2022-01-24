#include "./CBow.h"
#include<string>
#include<iostream>
using namespace std;


    void CBow::utiliser_cet_arme() {
            (*this).consommable--;
        }

    void CBow::fin_consommable(){
        if ( (*this).consommable <= 0  ){
            (*this).~CBow();
        }
    }

    //Destructeur
    
    ~CBow() {
        cout<<"Nombre de fleches est épuisé"<<endl;
    }