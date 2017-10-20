//
// Created by Mattia_Porcelli on 21/06/2017.
//

#include <c++/cstdlib>
#include "Piano.hpp"


void Piano::setPos_Scale_Salire (int scale){ this->pos_scale_salire = scale;}
    void Piano::setPos_Scale_Scendere (int scale) { this->pos_scale_scendere = scale;}
    int Piano::getPos_Scale_Salire (){ return this->pos_scale_salire;}
    int Piano::getPos_Scale_Scendere (){ return this->pos_scale_scendere;}
    //CHIAMARE CREA CON SCALE2 < 0 QUANDO SI CREA IL PRIMO PIANO!
    void Piano::crea(int n, int scale2){
        //srand(time(0));
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
        for (int i = n; i < 50; i++){
            arr_mappe[i].setNull();
        }
        collega_mappe();
    }

void Piano::collega_mappe(){
    if (numero_mappe != 1)
        if (numero_mappe == 2) {
            arr_mappe[0].inserisci_porta(arr_mappe[0].id, 1);
            arr_mappe[1].inserisci_porta(arr_mappe[1].id, 0);
        } else {
            int mappeRestanti = numero_mappe;
            int portePerMappa[numero_mappe];
            int porteAperte = 0;

            int k = (rand() % 2 ) + 2;
            portePerMappa[0] = k;
            porteAperte = k;
            //TODO DA FARE
            for (int i = 1 ; i < numero_mappe; i++){  //SCORRO TUTTE LE MAPPE.
                k = (rand()% 3)+1;
                portePerMappa[i] = k;
                porteAperte = porteAperte + k;
                for (int t = 0; t < i ; t++){ //PER OGNI PORTA APERTA K NELLA MAPPA I
                        if (portePerMappa[t] > 0){    //SE
                            for (int j = 0; j < portePerMappa[i]; j++) {
                                if (arr_mappe[i].porte[j] = 0) {
                                    arr_mappe[i].porte[j] = arr_mappe[k].id;

                                }
                            }
                        }
                }
            }
            //TODO DA CANCELLARE PROBABILMENTE
            for (int i = 0; i < numero_mappe; i++) {
                //TODO SE CI SONO PIU DI 3 MAPPE. COLLEGARLE
                int k = (rand() % 3) + 1;
                portePerMappa[i] = k;
                porteAperte = k;
                if (i != 0)
                    porteAperte--;


            }
        }
}


