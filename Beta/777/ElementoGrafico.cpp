//
// Created by Matteo Conti on 26/06/17.
//

#include "ElementoGrafico.hpp"
#include "Pet.hpp"
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

/*
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
*/

// disegna elemento per la prima volta
void ElementoGrafico::disegnaElemento(RenderWindow &window, Sprite &element)
{
    window.display();
    ////// draw  ///////
    window.draw(element);
    window.display();
}

// aggiorna la posizione di un elemento e ridisegna la mappa
void ElementoGrafico::disegnaElemento(RenderWindow &window, std::vector<Sprite> map, Sprite &element)
{
    ////// draw  ///////
    window.clear();
    // disegno la mappa corrente aggiornata
    for (Sprite oggetto_grafico : map)
    {
        window.draw(oggetto_grafico);
    }
    // aggiungo l'elemento corrente
    window.draw(element);
    window.display();
}


void ElementoGrafico::prova1(RenderWindow &window)
{
    int size=10;
    int W = 150;
    int H = 150;
    // pulisco tutti
    window.clear();
    // preparo la mappa
    /*Pet temp("white");
    //pet.setX(25); pet.setY(25);
    temp.setImmagine("../risorse/immagini/white.png");
    for (int i=0; i<W; i+=2)
        for (int j=0; j<H; j+=2)
        {
            temp.grafica.setPosition(i*size,j*size);
            prova2(window, temp.grafica);
        }*/
}

void ElementoGrafico::prova2(RenderWindow &window, Sprite &element)
{
    disegnaElemento(window, element);
}



/*
 * 1 metodo --> disegna cancella tutto + disegna la mappa + (disegna il nostro amico)
 * 2 metodo --> disegna elemento
 */