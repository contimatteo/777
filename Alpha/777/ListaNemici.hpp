//
// Created by enrico on 11/10/2017.
//

#ifndef INC_777_LISTANEMICI_HPP
#define INC_777_LISTANEMICI_HPP

#include "Nemico.hpp"
#include "Personaggio.hpp"
#include "Utilities.hpp"

const int NUMERO_NEMICI_MASSIMO=100;

class ListaNemici
{
    public:
        Utilities util;
        int numeroNemici;
        // array nemici
        Nemico *array_nemici[NUMERO_NEMICI_MASSIMO];
        // array delle posizioni random generate
        sf::Vector2<int> lista_posizioni[NUMERO_NEMICI_MASSIMO];
        // costruttori
        ListaNemici(int stack);

        void creaNemici(int pianoCorrente, int stanzaCorrente);
        void attaccoNemico(Personaggio &eroe);
        void eliminaNemico(Personaggio eroe1);
        void cancellaArray();
};


#endif //INC_777_LISTANEMICI_HPP
