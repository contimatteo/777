//
// Created by Matteo Conti on 18/10/17.
//

#ifndef INC_777_GRAFICA_HPP
#define INC_777_GRAFICA_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
using namespace sf;

/*! \class \brief Grafica
 *  @details la classe che disegna graficamente la mappa
 */
class Grafica
{
 public:
    // attributi
    Utilities util; /*! \typedef util */
    Texture texture_mappa; /*! \typedef texture_mappa */

    // metodi
    /*! \brief Grafica costruttore
     * @param stack
     */
    Grafica(int stack);

    /*! \brief \fn disegnaMappa(RenderWindow &Gioco)
     * @param Gioco
     * @details disegna la mappa
     */
    void disegnaMappa(RenderWindow &Gioco);

};


#endif //INC_777_GRAFICA_HPP
