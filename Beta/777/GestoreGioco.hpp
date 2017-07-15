//
// Created by Matteo Conti on 25/06/17.
//

#ifndef INC_777_GESTOREGIOCO_HPP
#define INC_777_GESTOREGIOCO_HPP
#include "MenuIniziale.hpp"
#include "ElementoGrafico.hpp"


class GestoreGioco
{
    private:
        // attributi
        RenderWindow        Gioco;
        RenderWindow        Tutorial;
        RenderWindow        Info;
        RenderWindow        *MenuInizialeGioco;
        // metodi
        void creaGioco();

    public:
        //costruttore
        GestoreGioco(int scelta, RenderWindow &menu);

};

#endif //INC_777_GESTOREGIOCO_HPP
