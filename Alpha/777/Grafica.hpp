//
// Created by Matteo Conti on 18/10/17.
//

#ifndef INC_777_GRAFICA_HPP
#define INC_777_GRAFICA_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
using namespace sf;


class Grafica
{
 public:
    // attributi
    Utilities util;
    Texture texture_mappa;

    // metodi

    // costruttore
    Grafica(int stack);
    void disegnaMappa(RenderWindow &Gioco);

};


#endif //INC_777_GRAFICA_HPP
