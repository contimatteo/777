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
    /*! \brief */
    void crea_mappa(int n);
    void riempi_mappa();
    void inserisci_porta(int n, int k);
    void inserisci_scala_salire();
    void inserisci_scala_scendere();
    int restituisci_valore(int x, int y);
    void setNull();
    bool isNull();
    bool isAporta(int x , int y);
    int idMappaPorta(int x, int y);

    private:
    int numero_di_nemici = 0;



};
#endif //INC_777_MAPPA_HPP
