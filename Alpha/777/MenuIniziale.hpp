//
// Created by Matteo Conti on 24/10/17.
//

#ifndef INC_777_MENUINIZIALE_HPP
#define INC_777_MENUINIZIALE_HPP

#include <iostream>
#include <SFML/Window.hpp>
#include "Utilities.hpp"
using namespace sf;
class MenuIniziale
{
 public:
    Utilities util;
    RenderWindow menu;
    // costruttore
    MenuIniziale(RenderWindow &Gioco);

};


#endif //INC_777_MENUINIZIALE_HPP
