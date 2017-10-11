#include "Nemico.hpp"
#include <iostream>
#include "ElementoGrafico.hpp"

    //ABLITA IN SOSPESO.


    int Nemico::setAttacco(int nuovoAttacco) {attacco = nuovoAttacco;}
   // int Nemico::setX(int xNuova) { x = xNuova; }
    //int Nemico::setY (int yNuova) { y = yNuova;}

    Nemico::Nemico(int tipo_nemico, int x, int y, int identificatore, int attacco_nemico ):ElementoGrafico(tipo_nemico)
    {
        posY=y;
        posX=x;
        id=identificatore;
        attacco=attacco_nemico;
    }
