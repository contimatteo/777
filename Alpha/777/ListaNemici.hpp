//
// Created by enrico on 11/10/2017.
//

#ifndef INC_777_LISTANEMICI_HPP
#define INC_777_LISTANEMICI_HPP

#include "Nemico.hpp"
#include "Personaggio.hpp"
#include "Utilities.hpp"

const int NUMERO_NEMICI_MASSIMO=200; /*! \var const int NUEMRO_NEMICI_MASSIMO */

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
    ListaNemici(int stack);

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

    
    void cancellaArray();
    void disegnaNemici(RenderWindow &Gioco);
    void stampaArray(Nemico *array[], int lunghezza);
    void spostaNemici(Personaggio &eroe, int piano, int stanza);
    bool controlloPosizionePersonaggio(Personaggio &eroe);

};


#endif //INC_777_LISTANEMICI_HPP
