//
// Created by Matteo Conti on 10/10/17.
//

#ifndef INC_777_UTILITIES_HPP
#define INC_777_UTILITIES_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

using namespace sf;

class Utilities
{
    public:
        static const int SPAZIO_CELLE;
        static const int DIMENSIONE_CELLE;

        static const int NUMERO_CASELLE_ASSE_X;
        static const int NUMERO_CASELLE_ASSE_Y;
        static const int ALTEZZA_DISPLAY;
        static const int LARGHEZZA_DISPLAY;
        static const int NUMERO_NEMICI_MASSIMO;
        static const int ALTEZZA_MAPPA;
        static const int LARGHEZZA_MAPPA;
        static const int POSIZIONE_PARTENZA_MAPPA_X;
        static const int POSIZIONE_PARTENZA_MAPPA_Y;

        static const int MARGINE_MAPPA;
        static const Color COLORE_SFONDO;

        static const int ALTEZZA_CONSOLE;
        static const int LARGHEZZA_CONSOLE ;
        static const int POSIZIONE_PARTENZA_CONSOLE_X;
        static const int POSIZIONE_PARTENZA_CONSOLE_Y;
        static const int ALTEZZA_FINESTRAsx;
        static const int LARGHEZZA_FINESTRAsx;
        static const int POSIZIONE_PARTENZA_FINESTRAsx_X;
        static const int POSIZIONE_PARTENZA_FINESTRAsx_Y;
        static const int ALTEZZA_FINESTRAdx;
        static const int LARGHEZZA_FINESTRAdx;
        static const int POSIZIONE_PARTENZA_FINESTRAdx_X;
        static const int POSIZIONE_PARTENZA_FINESTRAdx_Y;

        //metodi
         static bool controlloDuplicato(sf::Vector2<int> pos);
         static sf::Vector2<int> generaPosizioneRandom();

};


#endif //INC_777_UTILITIES_HPP
