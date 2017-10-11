//
// Created by enrico on 21-Jun-17.
//

#ifndef INC_777_NEMICO_H
#define INC_777_NEMICO_H

#include "ElementoGrafico.hpp"

class Nemico: public ElementoGrafico{

public:
    int attacco;
    //identificativo nemico
    int id;
    bool cancellato;
    int setAttacco(int nuovoAttacco);
    int setX(int xNuova);
    int setY (int yNuova);
    Nemico();
    Nemico(int stack);
    Nemico(int tipo_nemico, int x, int y, int identificatore, int attacco_nemico );

};

#endif //INC_777_NEMICO_H
