//
// Created by enrico on 21-Jun-17.
//

#ifndef INC_777_PERSONAGGIO_H
#define INC_777_PERSONAGGIO_H

#include "ElementoGrafico.hpp"
#include "ListaNemici.hpp"
#include "Utilities.hpp"


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
    int gittata= util.DIMENSIONE_CELLE*2;
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
    // metodi
    void setGraphics(int grafica);
    void setVitaAttuale(int vita);
    void setManaAttuale (int mana);
    void setLivello (int liv);
    void setArmatura (int arm);
    void setPotenza (int pot);
    void setSaggezza (int sag);
    void setLv_skill1 (int lv);
    void setLv_skill2 (int lv);
    void setLv_skill3 (int lv);
    void setLv_skill4 (int lv);
    void setCritico (int crit);
    //SETTIAMO LA POISIZIONE X
    void setX(int posizionex);
    //SETTIAMO LA POSIZIONE Y
    void setY(int posizioney);
    //SETTIAMO LA NUOVA ESPERIENZA OTTENUTA
    void setEsperienzaAttuale(int esperienzanuova);
    void setContatoreSkill1(int contatore);
    void setContatoreSkill2(int contatore);
    void setContatoreSkill3(int contatore);
    void setContatoreSkill4(int contatore);
    void personaggioAttaccaNemico(ListaNemici &nemici);

    //_____GETTER____________________
    int getVitaAttuale();
    int getVitaMassima();
    int getManaAttuale();
    int getManaMassimo();
    int getLivello();
    int getArmatura();
    int getPotenza();
    int getSaggezza();
    int getLv_skill1();
    int getLv_skill2();
    int getLv_skill3();
    int getLv_skill4();
    int getCritico();
    int getEsperienza();
    int getX();
    int getY();
    int getContatoreSkill1();
    int getContatoreSkill2();
    int getContatoreSkill3();
    int getContatoreSkill4();

    //Costruttore
    Personaggio();
    Personaggio(int tipo_personaggio);
};



/*
flow spostamento:
	1- Personaggio (pet)
	2- Controllo per togliere vita
	3- Nemico
*/

/*
array_nemici --> array di oggetti
ogni oggetto --> Nemico
class Nemico eredita di una classe --> ElementoGrafico
*/

/*
	class Nemico --> posX & posY (posizione);
*/



/*
sx --> -costante
dx--> +costante
giu--> + costante
su--> - costante

|--------------------|
| n
|          p  n
|
|      n
|--------------------|

*/
/*
class Personaggio
{
    // attributi
    // rappresenta l'array di nemici CORRENTE
    Nemico[] nemici;
    int posX, posY;

    // ----------------------------------------------------------------

    void gestoreEventi(int codice_spostamento, Nemico[] &array_nemici_aggiornato)
    {
        aggiornaArrayNemici(array_nemici_aggiornato);
        switch(codice_spostamento)
        {
            // sinistra
            case 0:
            {
                // aggiorno la posizione
                posX+=constante_spostamento;
                // disegni il personaggio spostato
                // controllare se finisce vicino a un nemico --> togli vita al personaggio
                if(this.posX-nemici[i].posX=constante_spostamento)
                {
                    // togli la vita al personaggio
                    // spostiamo il nemico????
                }
                // (non cancelli il nemico)
                // in caso contrario controlli se interagisce con elementi extra
            }
                // su
            case 1:
            { }
                // destra
            case 2:
            { }
                // giù
            case 3:
            { }
        }
    }

    // re-inizializziamo l'array di nemici quando cambia stanza
    void aggiornaArrayNemici(Nemico[] &nuovo_array_nemici)
    {
        nemici=nuovo_array_nemici;
    }

    // costruttore
    Personaggio(Nemico[] &array_nemici)
    {
        // instanziare l'array (succede solo alla prima mappa, al primo livello)
        nemici=nuovo_array_nemici;
        // instaziare posizione e vita, ecc..
        // prendere input array di nemici
        // disegna il personaggio
    }
}
*/


#endif //INC_777_PERSONAGGIO_H
