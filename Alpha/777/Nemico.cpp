#include "Nemico.hpp"
#include <iostream>
#include "ElementoGrafico.hpp"

// costruttore
Nemico::Nemico(int tipo_nemico, int x, int y, int identificatore, int attacco_nemico ):ElementoGrafico(tipo_nemico)
{
    cancellato=false;
    pos_cella_y = y+1;
    pos_cella_x = x+1;
    posX += util.SPAZIO_CELLE * x;
    posY += util.SPAZIO_CELLE * y;
    id=identificatore;
    attacco=attacco_nemico;
    // imposto la poszione del nemico per disegnarlo
    grafica.setPosition(posX, posY);
    //std::cout<<id<<" >> creo un nemico in posizione --> ["<<pos_cella_x<<", "<<pos_cella_y<<"] \n";
}
