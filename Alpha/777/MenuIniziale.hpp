//
// Created by Matteo Conti on 24/10/17.
//

#ifndef INC_777_MENUINIZIALE_HPP
#define INC_777_MENUINIZIALE_HPP

#include <iostream>
#include <SFML/Window.hpp>
#include "Utilities.hpp"
using namespace sf;

/*! \brief \class MenuIniziale
 * @details questa classe serve per impostare il menu inziale del gioco
 */
class MenuIniziale
{
 public:
    Utilities util; /*! \typedef Utilities util */
    RenderWindow menu; /*! \typedef RenderWindow menu */
    // costruttore

    /*! \brief \fn MenuIniziale
    * @details costruttore della classe
    */
    MenuIniziale(RenderWindow &Gioco);

};


#endif //INC_777_MENUINIZIALE_HPP
