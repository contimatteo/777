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
    int vitaMassima = 1000; /*! \var int vitaMassima*/
    int vitaAttuale = 1000; /*! \var int vitaAttuale*/
    int esperienza = 0; /*! \var int esperienza*/
    int potenza = 10; /*! \var int potenza*/
    int livello=1; /*! \var int livello*/
    int gittata= 2; /*! \var int gittata*/
    int cella_di_patenza_asse_x; /*! \var int cella_di_patenza_asse_x*/
    int cella_di_patenza_asse_y; /*! \var int cella_di_patenza_asse_y*/

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

    void fineGiocoHaPerso(RenderWindow &Gioco);
    void fineGiocoHaVinto(RenderWindow &Gioco, int piano, int stanza);


    //Costruttore
    Personaggio();

    /*! \brief \fn Personaggio
     * @param tipo_personaggio
     * @param lista_torre
     * @param stanza
     * @details cstruttore classe Personaggio
     */
    Personaggio(int tipo_personaggio, ListaTorre &lista_torre, int stanza);
    /*! \brief \fn impostaPosizionePartenzaPersonaggio
     * @param x
     * @param y
     * @details imposta sulla finestra di gioco dove deve partire il personaggio
     */
    void impostaPosizionePartenzaPersonaggio(int x, int y);

    /*! \brief \fn resetPosizionePersonaggio
     * @param lista_torre
     * @param stanza
     * @details funzione che cerca da dove far ripartire il personaggio
     */
    void resetPosizionePersonaggio(ListaTorre &lista_torre, int stanza);


};


#endif //INC_777_PERSONAGGIO_H
