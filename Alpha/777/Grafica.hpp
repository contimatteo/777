//
// Created by Matteo Conti on 18/10/17.
//

#ifndef INC_777_GRAFICA_HPP
#define INC_777_GRAFICA_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
#include "ListaTorre.hpp"
#include "Personaggio.hpp"
using namespace sf;

/*! \class \brief Grafica
 *  @details la classe che disegna graficamente la mappa
 */
class Grafica
{
 public:
    // attributi
    Vector2<int> array_posizioni_consentite[1000];
    int lunghezza_array;
    Utilities util; /*! \typedef util */
    int posizione_partenza_testo_x;
    int posizione_partenza_testo_y;
    Font font;
    Text status_eroe;
    Text vita_eroe;
    Text attacco_eroe;
    Text gittata_eroe;
    Text esperienza_eroe;
    Text livello_eroe;
    Text istruzioni_gioco;
    Text titolo_istruzioni_gioco;
    Text stanza_attuale;
    Text piano_attuale;

    // metodi
    Grafica(int stack);

    // disegno la mappa
    void disegnaMappa(RenderWindow &Gioco, ListaTorre &lista_torre, int &stanza);
    // disegno i testi nella finestra sinistra
    void creaTestiFinestraSinistra(Personaggio &eroe);
    //----------------------------------
    void agiornaVitaAttuale(Personaggio &eroe);
    void agiornaAttacco(Personaggio &eroe);
    void agiornaGittata(Personaggio &eroe);
    void agiornaEsperienza(Personaggio &eroe);
    void agiornaLivello(Personaggio &eroe);
    void istruzioniGioco();
    void creoArrayPosizioni(ListaTorre &lista_torre, int stanza, int eroe_x, int eroe_y);
    void agiornaPiano(Personaggio &eroe);
    void agiornaStanza(Personaggio &eroe);
    //------------------------------------------

};


#endif //INC_777_GRAFICA_HPP
