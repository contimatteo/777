//
// Created by Matteo Conti on 18/10/17.
//

#ifndef INC_777_GRAFICA_HPP
#define INC_777_GRAFICA_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
#include "ListaTorre.hpp"
using namespace sf;

/*! \class \brief Grafica
 *  @details la classe che disegna graficamente la mappa
 */
class Grafica
{
 public:
    // attributi
    Utilities util; /*! \typedef util */
    //Texture texture_mappa; /*! \typedef texture_mappa */

    // metodi
    Grafica(int stack);

    // disegno la mappa
    void disegnaMappa(RenderWindow &Gioco, ListaTorre &lista_torre, int &stanza);

};


#endif //INC_777_GRAFICA_HPP
