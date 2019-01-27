//
// Created by Matteo Conti on 18/10/17.
//

#ifndef INC_777_GRAFICA_HPP
#define INC_777_GRAFICA_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
#include "ListaTorre.hpp"
#include "Personaggio.hpp"
using namespace sf;

/*! \class \brief Grafica
 *  @details la classe che disegna graficamente la mappa
 */
class Grafica
{
 public:
    // attributi
    Vector2<int> array_posizioni_consentite[1000]; /*! \typedef Vector2<int> array_posizioni_consentite */
    int lunghezza_array; /*! \var int lunghezza_array*/
    Utilities util; /*! \typedef util */
    int posizione_partenza_testo_x; /*! \var int posizione_partenza_testo_x*/
    int posizione_partenza_testo_y; /*! \var int posizione_partenza_testo_y*/
    Font font; /*! \typedef util */
    Text status_eroe; /*! \typedef Text status_eroe */
    Text vita_eroe; /*! \typedef Text vita_eroe */
    Text attacco_eroe; /*! \typedef Text attacco_eroe */
    Text gittata_eroe; /*! \typedef  Text gittata_eroe */
    Text esperienza_eroe; /*! \typedef Text esperienza_eroe */
    Text livello_eroe; /*! \typedef Text livello_eroe */
    Text istruzioni_gioco; /*! \typedef Text istruzioni_gioco */
    Text titolo_istruzioni_gioco; /*! \typedef Text titolo_istruzioni_gioco */
    Text stanza_attuale; /*! \typedef Text stanza_attuale */
    Text piano_attuale; /*! \typedef Text piano_attuale */
    Text attacco_nemico;

    // metodi
    /*! \brief \fn Grafica
     * @param stack
     * @details costruttore della classe Grafica
     */
    Grafica(int stack);

    /*! \brief \fn void disegnaMappa
     * @param Gioco
     * @param lista_torre
     * @param stanza
     * @details questa funzione si occupa di disegnare correttamente la mappa all' interno della finestra di gioco
     */
    void disegnaMappa(RenderWindow &Gioco, ListaTorre &lista_torre, int &stanza);

    // disegno i testi nella finestra sinistra
    /*! \brief \fn void creaTestiFinestraSinistra
     * @param eroe
     * @param piano
     * @param stanza
     * @param nemici
     * @details funzione che prepare la finestra sx laterale dove vengono inseriti i dati del gioco agiornati
     */
    void creaTestiFinestraSinistra(Personaggio &eroe, int piano, int stanza, ListaNemici &nemici);

    /*! \brief \fn void istrizioniGioco
     * @details funzione che si occupa di scrivere le istruzioni del gioco nella finestra dx
     */
    void istruzioniGioco();

    /*! \brief \fn void creoArrayPosizioni
     * @param lista_torre
     * @param stanza
     * @param eroe_x
     * @param eroe_y
     * @details una funzione che ricerca all' interno della mappa tutte le posizioni possibili su cui spostarsi e ne tiene traccia
     */
    void creoArrayPosizioni(ListaTorre &lista_torre, int stanza, int eroe_x, int eroe_y);

    /*! \brief \fn void aggiornaPiano
     * @param piano
     * @details aggiorna il piano a display
     */
    void aggiornaPiano(int piano);

    /*! \brief \fn void aggiornaStanza
    * @param stanza
    * @details aggiorna la stanza a display
    */
    void aggiornaStanza(int stanza);
    //------------------------------------------

};


#endif //INC_777_GRAFICA_HPP
