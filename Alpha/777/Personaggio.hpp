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
#include "ListaTorre.hpp"

/*! definizione della classe ListaNemici */
class ListaNemici;

/*! \class Personaggio
 *  @details classe Personaggio estensione della classe ElementoGrafico
 */
class Personaggio:public ElementoGrafico {

public:
    Utilities util;
    //int graphics;
    int vitaMassima = 1000; /** <enum valore vitaMassima. */
    int vitaAttuale = 1000; /** <enum valore vitaAttuale. */
    int manaMassimo = 100;
    int manaAttuale = 100;
    int esperienza = 0;
    int livello = 1;
    int gittata= 2; /** <enum valore gittata. */
    int armatura = 10; //pet-
    int potenza = 10; /** <enum valore potenza. */
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

    /*! \fn void personaggioAttaccaNemico (ListaNemici &nemici)
     * @param nemici
     * @details questa funzione viene richiamata quando il personaggio attacca il nemico vicino
     */
    void personaggioAttaccaNemico(ListaNemici &nemici);

    /*! \fn  void eliminiNemico(ListaNemici &nemici, int posizione, bool &flag)
     *
     * @param nemici
     * @param posizione
     * @param flag
     * @details la funzione elimina un nemico ogni volta che il personaggio lo sconfigge
     */
     void eliminaNemico(ListaNemici &nemici, int posizione, bool &flag);


    //Costruttore
    Personaggio();
    /**
    * \brief Personaggio costruttore
    * @param tipo_personaggio
    */
    Personaggio(int tipo_personaggio, ListaTorre &lista_torre, int stanza);

    void impostaPosizionePartenzaPersonaggio(int x, int y);

};


#endif //INC_777_PERSONAGGIO_H
