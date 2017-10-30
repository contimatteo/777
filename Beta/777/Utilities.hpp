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
    static const int SPAZIO_CELLE; /*! \var static const int SPAZIO_CELLE */
    static const int DIMENSIONE_CELLE; /*! \var static const int DIMENSIONE_CELLE */

    static const int GIOCO_FINITO_PIANO; /*! \var static const int GIOCO_FINITO_PIANO */
    static const int GIOCO_FINITO_STANZA; /*! \var static const int GIOCO_FINITO_STANZA */

    static const int NUMERO_CASELLE_ASSE_X; /*! \var static const int NUMERO_CASELLE_ASSE_X */
    static const int NUMERO_CASELLE_ASSE_Y; /*! \var static const int NUMERO_CASELLE_ASSE_Y */
    static const int ALTEZZA_DISPLAY; /*! \var static const int ALTEZZA_DISPLAY */
    static const int LARGHEZZA_DISPLAY; /*! \var static const int LARGHEZZA_DISPLAY */
    static const int NUMERO_NEMICI_MASSIMO; /*! \var static const int NUMERO_NEMICI_MASSIMO */
    static const int ALTEZZA_MAPPA; /*! \var static const int ALTEZZA_MAPPA */
    static const int LARGHEZZA_MAPPA; /*! \var static const int LARGHEZZA_MAPPA */
    static const int POSIZIONE_PARTENZA_MAPPA_X; /*! \var static const int POSIZIONE_PARTENZA_MAPPA_X */
    static const int POSIZIONE_PARTENZA_MAPPA_Y; /*! \var static const int POSIZIONE_PARTENZA_MAPPA_Y */

    static const int MARGINE_MAPPA; /*! \var static const int MARGINE_MAPPA */
    static const Color COLORE_SFONDO; /*! \var static const Color COLORE_SFONDO */

    static const int ALTEZZA_CONSOLE; /*! \var static const int ALTEZZA_CONSOLE */
    static const int LARGHEZZA_CONSOLE ; /*! \var static const int LARGHEZZA_CONSOLE */
    static const int POSIZIONE_PARTENZA_CONSOLE_X; /*! \var static const int POSIZIONE_PARTENZA_CONSOLE_X */
    static const int POSIZIONE_PARTENZA_CONSOLE_Y; /*! \var static const int POSIZIONE_PARTENZA_CONSOLE_Y */
    static const int ALTEZZA_FINESTRAsx; /*! \var static const int ALTEZZA_FINESTRAsx */
    static const int LARGHEZZA_FINESTRAsx; /*! \var static const int LARGHEZZA_FINESTRAsx */
    static const int POSIZIONE_PARTENZA_FINESTRAsx_X; /*! \var static const int POSIZIONE_PARTENZA_FINESTRAsx_X */
    static const int POSIZIONE_PARTENZA_FINESTRAsx_Y; /*! \var static const int POSIZIONE_PARTENZA_FINESTRAsx_Y */
    static const int ALTEZZA_FINESTRAdx; /*! \var static const int ALTEZZA_FINESTRAdx */
    static const int LARGHEZZA_FINESTRAdx; /*! \var static const int LARGHEZZA_FINESTRAdx */
    static const int POSIZIONE_PARTENZA_FINESTRAdx_X; /*! \var static const int POSIZIONE_PARTENZA_FINESTRAdx_X */
    static const int POSIZIONE_PARTENZA_FINESTRAdx_Y; /*! \var static const int POSIZIONE_PARTENZA_FINESTRAdx_Y */

    static int posizione_partenza_personaggio_x; /*! \var static int posizione_partenza_personaggio_x */
    static int posizione_partenza_personaggio_y; /*! \var static int posizione_partenza_personaggio_y */

    //metodi
    /*! \brief \fn bool controlloDuplicato(sf::Vector2<int> pos)
     * @details controlla se la posizione generata è unica
     */
    static bool controlloDuplicato(sf::Vector2<int> pos);
    /*! \brief \fn Vector2<int> generaPosizioneRandom();
     * @details crea una nuova posizione random.
     */

    /*! \brief \fn static void generaPosizioneRandom
     * @param array_posizioni_consentite
     * @param lunghezza_arr_pos
     * @param stanza
     * @param posizione_generata
     * @details genera una coppia di interi come posizione random e non duplicati
     */
    static void generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int stanza, Vector2<int> &posizione_generata);

    /*! \brief \fn static void generaPosizioneRandom
     * @param array_posizioni_consentite
     * @param lunghezza_arr_pos
     * @param eroe_x
     * @param eroe_y
     * @param stanza
     * @param posizione_generata
     * @details genera una coppia di interi come posizione random e non duplicati
     */
    static void generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int eroe_x, int eroe_y, int stanza, Vector2<int> &posizione_generata);

    /*! \brief \fn static bool controlloPOsizioneConsentita
     * @param array_posizioni_consentite
     * @param length
     * @param posizione_generata
     * @return
     * @details controlla che posizione_generata sia presente in array_posizioni_consentite
     */
    static bool controlloPosizioneConsentita(Vector2<int> array_posizioni_consentite[], int length, Vector2<int> posizione_generata);

    /*! \brief \fn static void arrezaPosizioni
     * @details Azzera tutti gli elementi dell' array_posizioni_consentite
     */
    static void azzeraPosizioni();
    void eliminaPosizione(int x, int y);
    static bool controllaElementoGrafico(ListaTorre &lista_torre, int stanza, int x, int y);

    /*! \brief \fn string convertINt
     * @param number
     * @return
     * @details funzione che converte un numero in una stringa
     */
    std::string convertInt(int number);


};


#endif //INC_777_UTILITIES_HPP
