//
// Created by Matteo Conti on 10/10/17.
//

#ifndef INC_777_ELEMENTOGRAFICO_HPP
#define INC_777_ELEMENTOGRAFICO_HPP

#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
using namespace sf;

class ElementoGrafico
{
    private:

    public:
        // ATTRIBUTI
        Sprite grafica;
        Texture texture;
        Utilities util;
        RenderWindow Gioco;
        int posX;
        int posY;


        //METODI
        void muovi(int x, int y);
        void muovi();
        void setPosizione(int x, int y);
        //------------------------------------------
        /*
         * 1: erore
         * 2: pet
         * 3: nemico
         * 4: altri
         * 5: ..
         * --------------
         * 10: mura mappa
         * 11: pavimento mappa
         * 12: ..
         */
        ElementoGrafico(int tipo_personaggio);
        //------------------------------------------

};


#endif //INC_777_ELEMENTOGRAFICO_HPP