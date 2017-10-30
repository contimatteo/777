//
// Created by Mattia_Porcelli on 21/06/2017.
//

#include <cstdlib>
#include "Piano.hpp"


//CHIAMARE CREA CON SCALE2 < 0 QUANDO SI CREA IL PRIMO PIANO!
void Piano::crea(int n, int scale2)
{
    numero_mappe = n;
    for (int i = 0; i < n; i++) {
        Mappa map;
        map.crea_mappa(i); //LE MAPPE VENGONO CREATE SENZA PORTE DI COLLEGAMENTO
        map.riempi_mappa();
        arr_mappe[i] = map;
    }
    int y = 0;
    if (n > 1)
        y = rand() % n;
    int k = 0;

    if (n > 1)
        k = rand() % n;

    if (scale2 >= 0)
        arr_mappe[k].inserisci_scala_scendere();

    arr_mappe[y].inserisci_scala_salire();
    this->pos_scale_salire = y;
    this->pos_scale_scendere = scale2;
    for (int i = n; i < 50; i++)
    {
        arr_mappe[i].setNull();
    }
    collega_mappe();
}

    int count(int arr[]){
        int t = 0;
        for (int i = 0; i < 3; i ++){
            if (arr[i] < 0)
                t++;
        }
        return t;
    }

    void Piano::collega_mappe(){
    if (numero_mappe != 1){


        if (numero_mappe == 2){
            arr_mappe[0].inserisci_porta(0,1);
            arr_mappe[1].inserisci_porta(0,0);
        } else if (numero_mappe == 3){

            arr_mappe[0].inserisci_porta(0,1);
            arr_mappe[0].inserisci_porta(1,2);
            arr_mappe[1].inserisci_porta(0,0);
            arr_mappe[1].inserisci_porta(1,2);
            arr_mappe[2].inserisci_porta(0,0);
            arr_mappe[2].inserisci_porta(1,1);

        } else {
            int k = 0;
            for (int i = 0; i < numero_mappe - 2; i ++) {
                if (k == 0){

                    arr_mappe[i].inserisci_porta(0, i + 1);
                    arr_mappe[i].inserisci_porta(1, i + 2);
                    arr_mappe[i + 1].inserisci_porta(2, i);
                    arr_mappe[i + 2].inserisci_porta(2, i);


                    k++;
                } else if (k == 1 ){

                    arr_mappe[i].inserisci_porta(0, i + 1);
                    arr_mappe[i].inserisci_porta(1, i + 2);
                    arr_mappe[i+1].inserisci_porta(1, i);
                    arr_mappe[i+2].inserisci_porta(2, i);


                    k++;
                } else {

                    arr_mappe[i].inserisci_porta(0, i+1);
                    arr_mappe[i+1].inserisci_porta(1, i);
                    arr_mappe[i+1].inserisci_porta(0,i+2);
                    arr_mappe[i+2].inserisci_porta(2, i +1);
                    k--;
                }
            }
        }
    }
}


#if 0




#endif