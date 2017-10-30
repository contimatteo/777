//
// Created by Matteo Conti on 10/10/17.
//

#ifndef INC_777_UTILITIES_HPP
#define INC_777_UTILITIES_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>
#include "ListaTorre.hpp"

using namespace sf;

class Utilities
{
public:
    static const int SPAZIO_CELLE;
    static const int DIMENSIONE_CELLE;

    static const int GIOCO_FINITO_PIANO;
    static const int GIOCO_FINITO_STANZA;

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

    static int posizione_partenza_personaggio_x;
    static int posizione_partenza_personaggio_y;

    //metodi
    /*! \brief \fn bool controlloDuplicato(sf::Vector2<int> pos)
     * @details controlla se la posizione generata è unica
     */
    static bool controlloDuplicato(sf::Vector2<int> pos);
    /*! \brief \fn Vector2<int> generaPosizioneRandom();
     * @details crea una nuova posizione random.
     */

    /*static Vector2<int> generaPosizioneRandom();
    static Vector2<int> generaPosizioneRandom(ListaTorre &lista_torre, int stanz, int eroe_x, int eroe_y);
    static Vector2<int> generaPosizioneRandom(int eroe_x, int eroe_y);*/
    static void generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int stanza, Vector2<int> &posizione_generata);
    static void generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int eroe_x, int eroe_y, int stanza, Vector2<int> &posizione_generata);


    static bool controlloPosizioneConsentita(Vector2<int> array_posizioni_consentite[], int length, Vector2<int> posizione_generata);
    static void azzeraPosizioni();
    void eliminaPosizione(int x, int y);
    static bool controllaElementoGrafico(ListaTorre &lista_torre, int stanza, int x, int y);


    std::string convertInt(int number);


};


#endif //INC_777_UTILITIES_HPP
