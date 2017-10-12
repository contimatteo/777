//
// Created by Matteo Conti on 10/10/17.
//

#ifndef INC_777_UTILITIES_HPP
#define INC_777_UTILITIES_HPP
#include <SFML/System/Vector2.hpp>

class Utilities
{
    public:
        static const int DIMENSIONE_CELLE;
        static const int ALTEZZA_FINESTRA_GIOCO;
        static const int LARGHEZZA_FINESTRA_GIOCO;
        static const int NUMERO_CASELLE_ASSE_X;
        static const int NUMERO_CASELLE_ASSE_Y;
        static const int NUMERO_NEMICI_MASSIMO;

        //metodi
         static bool controlloDuplicato(sf::Vector2<int> pos);
         static sf::Vector2<int> generaPosizioneRandom();



};


#endif //INC_777_UTILITIES_HPP
