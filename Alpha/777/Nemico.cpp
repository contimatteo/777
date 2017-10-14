#include "Nemico.hpp"
#include <iostream>
#include "ElementoGrafico.hpp"

// costruttore
Nemico::Nemico(int tipo_nemico, int x, int y, int identificatore, int attacco_nemico ):ElementoGrafico(tipo_nemico)
{
    cancellato=false;
    pos_cella_y = y;
    pos_cella_x = x;
    posX += util.DIMENSIONE_CELLE * x;
    posY += util.DIMENSIONE_CELLE * y;
    id=identificatore;
    attacco=attacco_nemico;
    // imposto la poszione del nemico per disegnarlo
    //std::cout<<"creo nemico nella cella --> ["<<posX<<", "<<posY<<"] \n";
    grafica.setPosition(posX, posY);
}
