// Cmelee.h
#ifndef Cmelee 
#define Cmelee
#include<string>
#include "../Cweapon.h"
using namespace std;
    class Cmelee : public Cweapon
    {
        
    public:
        double Durabilite;
        double Durabilite_Init;
        bool casse;
        


        //Constructeur
        
        Cmelee(string nom, double degat, double val_critique, double val_bonus, double durabilite, bool casse ) ;



        //Accesseur
        
       // double getVal_Durabilite();
        //bool get_casse();

        //Modificateur
        
      //  void setVal_Durabilite();
       // void set_casse(bool d);
        //funtion
        void arme_detrui();
        void casse_ou_non();
        virtual void utiliser_arme() = 0;

        
    };



#endif //Cmelee