//
// Created by Matteo Conti on 26/06/17.
//

#ifndef INC_777_ELEMENTOGRAFICO_HPP
#define INC_777_ELEMENTOGRAFICO_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class ElementoGrafico
{
    public:
        template<typename Object>
        static void disegnaElemento(RenderWindow &window, Object &element);

        static void disegnaElemento(RenderWindow &window, RectangleShape &element);
        static void disegnaElemento(RenderWindow &window, Sprite &element);
        static void disegnaElemento(RenderWindow &window, std::vector<Sprite> map, Sprite &element);
        static void prova1(RenderWindow &window);
        static void prova2(RenderWindow &window, Sprite &element);


    private:
};


#endif //INC_777_ELEMENTOGRAFICO_HPP
