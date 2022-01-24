#include "Cmelee.h"
#include<string>
#include<iostream>
using namespace std;

    //CONSTRUCTEUR
    Cmelee::Cmelee(string nom , double degat , double critique, double bonus ,  double durabilite, bool casse =false) : Cweapon(nom , degat , critique , bonus
    ) , Durabilite(durabilite), casse(casse){
        Durabilite_Init = durabilite;
    }

    //Destructeur
    void Cmelee::arme_detrui(){
        if ( (*this).Durabilite <= 0){
            (*this).~Cmelee() 
        }
    }
    void Cmelee::casse_ou_non(){
        if(casse==1){
           
            Val_Degat/=10;
        }
    }

    Cmelee::~Cmelee(){
        cout << "cet arme est detruit" << endl;
    }
