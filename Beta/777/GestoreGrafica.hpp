//
// Created by Matteo Conti on 21/08/17.
//

#ifndef INC_777_GESTOREGRAFICA_HPP
#define INC_777_GESTOREGRAFICA_HPP

#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class GestoreGrafica
{
    private:
        int dimensione_mappa;


    public:
        // attributi
        std::vector<Sprite> mappa;
        // metodi
        GestoreGrafica(int stack);
        void aggiungiElemento(Sprite oggetto);
        std::vector<Sprite> getMappa();
        void disegnaMappa(RenderWindow &window);
        void instanzioMappa();


};


#endif //INC_777_GESTOREGRAFICA_HPP
