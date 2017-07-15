//
// Created by Matteo Conti on 26/06/17.
//

#include "ElementoGrafico.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

template<typename Object>
void ElementoGrafico::disegnaElemento(RenderWindow &window, Object &element) {
    window.display();
    window.draw(element);
    window.display();
}

void ElementoGrafico::disegnaElemento(RenderWindow &window, RectangleShape &element){
    window.display();
    window.draw(element);
    window.display();
}

void ElementoGrafico::disegnaElemento(RenderWindow &window, Sprite &element){
    window.display();
    window.draw(element);
    window.display();
}