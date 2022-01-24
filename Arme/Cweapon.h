#ifndef DEF_WEAPON
#define DEF_WEAPON
 
#include <iostream>
#include <string>

using namespace std ;
 
class Cweapon
    {
        
       
       
        public:
            string Nom ;
            double Val_Degat;
            double Val_Critique;
            double Val_Bonus;
            //CONSTRUCTEUR
            Cweapon(string nom, double degat, double critique, double bonus);


    };
 
#endif