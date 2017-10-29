//
// Created by enrico on 11/10/2017.
//

#ifndef INC_777_LISTANEMICI_HPP
#define INC_777_LISTANEMICI_HPP

#include "Nemico.hpp"
#include "Personaggio.hpp"
#include "Utilities.hpp"

const int NUMERO_NEMICI_MASSIMO=20; /*! \var const int NUEMRO_NEMICI_MASSIMO */

/*! definisco una classe*/
class Personaggio;

/*! \class Lista nemici
 * @define contine un array di oggetti, dove ogni elemento rappresenta un nemico
 */
class ListaNemici
{
public:
    Utilities util; /*! \typedef Utilities util*/
    int numeroNemici; /*! \var int numeroNemici */
    // array nemici
    Nemico *array_nemici[NUMERO_NEMICI_MASSIMO]; /*! \typedef Nemico array_nemici[NUMERO_NEMICI_MASSIMO] */
    // array delle posizioni random generate
    sf::Vector2<int> lista_posizioni[NUMERO_NEMICI_MASSIMO]; /*! \typedef Vector2<int> lista_posizioni[NUMERO_NEMICI_MASSIMO] */
    // costruttori

    /*! \brief \fn ListaNemici
     * @param lista_torre
     * @param eroe
     * @param array_posizioni_consentite
     * @param lunghezza_arr_pos
     * @param stanza
     * @details costruttore ListaNemici
     */
    ListaNemici(ListaTorre &lista_torre, Personaggio &eroe, Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int piano, int stanza);

    /*! \brief \fn void creaNemici
     * @param pianoCorrente
     * @param stanzaCorrente
     * @details vengono generati i nemici in posizioni random all' interno della mappa
     */
    void creaNemici(int pianoCorrente, int stanzaCorrente);

    /*! \brief \fn void nemicoAttaccaPersonaggio
     * @param eroe
     * @details funzione che controlla quando il personaggio si avvicina al nemico e in caso di scontro attacca il personaggio
     */
    void nemicoAttaccaPersonaggio(Personaggio &eroe);

    /*! \brief \fn void eliminaNemicoInPosizione
     * @param posizione
     * @details se il personaggio attacca il nemico e lo uccide viene cancellato il nemico
     */
    void eliminaNemicoInPosizione(int posizione);

    /*! \brief \fn void cancellaArray
     * @details viene liberato l' array
     */
    void cancellaArray();

    /*! \brief \fn void disegnaNemici
     * @param Gioco
     * @details funzione grafica che disegna i nemici sulla mappa
     */
    void disegnaNemici(RenderWindow &Gioco);

    void stampaArray(Nemico *array[], int lunghezza);

    /*! \brief \fn void spostaNemici
     * @param eroe
     * @param lista_torre
     * @param array_posizioni_consentite
     * @param lunghezza_arr_pos
     * @param piano
     * @param eroe_x
     * @param eroe_y
     * @param stanza
     * @details ogni volta che viene riaggiornata la mappa sposta i nemici in posizioni random
     */
    void spostaNemici(Personaggio &eroe, ListaTorre &lista_torre, Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int eroe_x, int eroe_y, int piano, int stanza);

    /*! \brief \fn bool controlloPosizionePersonaggio
     * @param eroe
     * @return
     * @details ritorna se ha torvato il personaggio nella stessa posizione del nemico
     */
    bool controlloPosizionePersonaggio(Personaggio &eroe);

    /*! \brief \fn void aggiornaAttaccoNemici
     * @param valore
     * @details aumenta o diminuisce l'attacco del nemico
     */
    void aggiornaAttaccoNemici(int valore);

    /*! \brief \fn void ricreaNemici
     * @param lista_torre
     * @param eroe
     * @param array_posizioni_consentite
     * @param lunghezza_arr_pos
     * @param piano
     * @param stanza
     * @details funzione che con l aumentare delle stanze e piani ricrea i nemici
     */
    void ricreaNemici(ListaTorre &lista_torre, Personaggio &eroe, Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int piano, int stanza);

};


#endif //INC_777_LISTANEMICI_HPP
