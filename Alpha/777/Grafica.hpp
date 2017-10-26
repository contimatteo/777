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
    Utilities util; /*! \typedef util */
    int posizione_partenza_testo_x;
    int posizione_partenza_testo_y;
    Font font;
    Text status_eroe;
    Text vita_eroe;
    Text attacco_eroe;
    Text gittata_eroe;

    // metodi
    Grafica(int stack);

    // disegno la mappa
    void disegnaMappa(RenderWindow &Gioco, ListaTorre &lista_torre, int &stanza);
    // disegno i testi nella finestra sinistra
    void creaTestiFinestraSinistra(RenderWindow &Gioco, Personaggio &eroe);

};


#endif //INC_777_GRAFICA_HPP
