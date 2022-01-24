#include "./Cdagger.h"
#include<string>
#include<iostream>
using namespace std;


    
    //function
     void Cdagger::utiliser_arme()(){
         Durabilite-=1;     
         (*this).arme_detrui();   
     }


    //Destructeur
    ~Cdagger() {
        cout<<"Csdagger detruit"<<endl;
    }
