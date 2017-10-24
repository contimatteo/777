//
// Created by Mattia_Porcelli on 04/10/2017.
//

#ifndef INC_777_MAPPA_HPP
#define INC_777_MAPPA_HPP
/*! \brief \class Mappa
 * @details in questa classe viene creata la mappa
 */
class Mappa{

    public:
    int id; /*! \var int id */
    int location[20][20]; /*! \var int location */

    /*! \brief \fn void crea_mappa(int n)
     * @param n
     * @details vengono creati i bordi della mappa
     */
    void crea_mappa(int n);

    /*! \brief \fn void riempi_mappa()
     * @details determina la mappa giocabile
     */
    void riempi_mappa();

    /*! \brief \fn void inserisci_porta(int n, int k)
     * @param n
     * @param k
     * @details randomizza una porta per passare da una stanza all' altra
     */
    void inserisci_porta(int n, int k);

    /*! \brief \fn void inserisci_scala_salire()
     * @details crea scala per salire di piano
     */
    void inserisci_scala_salire();

    /*! \brief \fn void inserisci_scala_scendere()
     * @details crea scala per scendere di piano
     */
    void inserisci_scala_scendere();

    /*! \brief \fn int restituisci_valore(int x, int y)
     * @param x
     * @param y
     * @return
     * @details funzione che ritorna quale oggetto è in posizione x,y
     */
    int restituisci_valore(int x, int y);

    /*! \brief \fn void setNull()
     * @details setta tutta la mappa a null
     */
    void setNull();

    /*! \brief \fn bool isNull()
     * @return
     * @details controlla se la mappa è settata tutta a null
     */
    bool isNull();
    int porte[3] = {0, 0 ,0}; /*! \var int porte */


    private:
    int numero_di_nemici = 0; /*! \var int numer_di_nemici */
};
#endif //INC_777_MAPPA_HPP
