#include "./Csword.h"
#include<string>
#include<iostream>
using namespace std;


    //function
     void Csword::utiliser_arme()(){
         Durabilite-=rand()%5+2;     
         (*this).arme_detrui();   
     }



    //Destructeur
    Csword::~Csword() {
        cout<<"Csword detruit"<<endl;
    }

