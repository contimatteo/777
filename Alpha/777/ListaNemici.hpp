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

    /*! \brief costruttore ListaNemici
     * @param stack
     */
    ListaNemici(ListaTorre &lista_torre, int stanza);

    /*! \brief \fn void creaNemici(int pianoCorrente, int stanzaCorrente)
     * @param pianoCorrente
     * @param stanzaCorrente
     * @details vengono generati i nemici in posizioni random all' interno della mappa
     */
    void creaNemici(int pianoCorrente, int stanzaCorrente);

    /*! \brief \fn void nemicoAttaccaPersonaggio(Personaggio &eroe)
     * @param eroe
     * @details funzione che controlla quando il personaggio si avvicina al nemico e in caso di scontro attacca il personaggio
     */
    void nemicoAttaccaPersonaggio(Personaggio &eroe);

    /*! \brief \fn void eliminaNemicoInPosizione(int posizione)
     * @param posizione
     * @details se il personaggio attacca il nemico e lo uccide viene cancellato il nemico
     */
    void eliminaNemicoInPosizione(int posizione);

    /*! \brief \fn void cancellaArray()
     * @details viene liberato l' array
     */
    void cancellaArray();

    /*! \brief \fn void disegnaNemici(RenderWindow &Gioco)
     * @param Gioco
     * @details funzione grafica che disegna i nemici sulla mappa
     */
    void disegnaNemici(RenderWindow &Gioco);
    void stampaArray(Nemico *array[], int lunghezza);

    /*! \brief \fn void spostaNemici(Personaggio &eroe, int piano, int stanza)
     * @param eroe
     * @param piano
     * @param stanza
     * @details ogni volta che viene riaggiornata la mappa sposta i nemici in posizioni random
     */
    void spostaNemici(Personaggio &eroe, ListaTorre &lista_torre, int piano, int stanza);

    /*! \brief \fn bool controlloPosizionePersonaggio(Personaggio &eroe)
     * @param eroe
     * @return
     * @details ritorna se ha torvato il personaggio nella stessa posizione del nemico
     */
    bool controlloPosizionePersonaggio(Personaggio &eroe);

};


#endif //INC_777_LISTANEMICI_HPP
