//
// Created by enrico on 21-Jun-17.
//

#ifndef INC_777_PERSONAGGIO_H
#define INC_777_PERSONAGGIO_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ElementoGrafico.hpp"
#include "ListaNemici.hpp"
#include "Utilities.hpp"


class ListaNemici;

class Personaggio:public ElementoGrafico {

public:
    Utilities util;
    //int graphics;
    int vitaMassima = 1000; //pet-
    int vitaAttuale = 1000;
    int manaMassimo = 100;  //pet-
    int manaAttuale = 100;
    int esperienza = 0;
    int livello = 1;
    int gittata= 2;
    int armatura = 10; //pet-
    int potenza = 10; //pet-
    int saggezza = 10; //pet-
    int critico = 5; //pet-
    //SETTARE POI DA DOVE FAR INIZIARE IL PERSONAGGIO
    int contatoreSkill1=0;
    int contatoreSkill2=0;
    int contatoreSkill3=0;
    int contatoreSkill4=0;
    int lv_skill1=1;
    int lv_skill2=1;
    int lv_skill3=1;
    int lv_skill4=1;
    //______________________________

    //int dmg_skill1 = (1 + (saggezza/50) ) *100* (1+(lv_skill1/10))  + valore random da 1 a 19+lv skill  ;

    //int dmg_skill2 = (1 + (lv_skill2/50) ) *100*(1+(lv_skill2/10)) /* + valore random da 1 a 19+lv skill */ ;

    //int dmg_skill3 = (1 + (lv_skill3/50) ) *100* (1+(lv_skill3/10)) /* + valore random da 1 a 19+lv skill */ ;

    //int dmg_skill4 = (1 + (lv_skill4/50) ) *100* (1+(lv_skill4/10))/* + valore random da 1 a 19+lv skill */ ;

    //_______________________________

    // qundo il personaggio attacca un nemico
    void personaggioAttaccaNemico(ListaNemici &nemici);
    void eliminaNemico(ListaNemici &nemici, int posizione, bool &flag);


    //Costruttore
    Personaggio();
    Personaggio(int tipo_personaggio);
};


#endif //INC_777_PERSONAGGIO_H
