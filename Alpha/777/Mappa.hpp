//
// Created by Mattia_Porcelli on 04/10/2017.
//

#ifndef INC_777_MAPPA_HPP
#define INC_777_MAPPA_HPP

class Mappa{

    public:
    int id;
    int location[20][20];
    void crea_mappa(int n);
    void riempi_mappa();
    void inserisci_porta(int n, int k);
    void inserisci_scala_salire();
    void inserisci_scala_scendere();
    int restituisci_valore(int x, int y);
    void setNull();
    bool isNull();
    int porte[3] = {0, 0 ,0};


    private:
    int numero_di_nemici = 0;



};
#endif //INC_777_MAPPA_HPP
