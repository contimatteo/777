//
// Created by Mattia_Porcelli on 04/10/2017.
//

#ifndef INC_777_MAPPA_HPP
#define INC_777_MAPPA_HPP

class Mappa{

    public:
    //ATTRIBUTI
    int id; /*! \var int id*/
    int location[20][20]; /*! \var int location*/
    int porte[3] = {-1, -1 ,-1}; /*! \var int porte*/

    /*! \brief \struct coord
     * \typedef coord
     */
    struct {
        int x; /*! \var int x */
        int y; /*! \var int y */
    }typedef coord;
    coord portexy[3];

    //METODI
    /*! \brief \fn void crea_mappa
     * @param n
     * @details funzione che randomizza una mappa all' interno della finestra di gioco
     * @details ATTENZIONE: le mappe non sono mai uguali e cambiano ogni vola che si gioca
     */
    void crea_mappa(int n);

    /*! \brief \fn void riempi_mappa
     * @details funzone che stabilisce quali sono le zone di mappa giocabili
     */
    void riempi_mappa();

    /*! \brief \fn void inserisci_porta
     * @param n
     * @param k
     * @details crea una porta nella mappa
     */
    void inserisci_porta(int n, int k);

    /*! \brief \fn void inserisci_scala_salire
     * @details randomizza una scala in una stanza
     */
    void inserisci_scala_salire();

    /*! \brief \fn void inserisci_scala_scendere
     * @details randomizza una scala in una stanza
     */
    void inserisci_scala_scendere();

    /*! \brief \fn void restituisci_valore
     * @param x
     * @param y
     * @return
     * @details funzione che restituisce il valore di una determinata casella della mappa
     */
    int restituisci_valore(int x, int y);
    void setNull();

    /*! \brief \fn bool isAporta
     * @param x
     * @param y
     * @return
     * @details funzione che ritorna True quando trova una porta in una determinata cella
     */
    bool isAporta(int x , int y);

    /*! \brief \fn int idMappaPorta
     * @param x
     * @param y
     * @return
     * @details funzione che ritorna il valore identificativo della porta indicata
     */
    int idMappaPorta(int x, int y);

    private:
    int numero_di_nemici = 0;



};
#endif //INC_777_MAPPA_HPP
