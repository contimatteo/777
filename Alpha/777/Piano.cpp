//
// Created by Mattia_Porcelli on 21/06/2017.
//

#include "Piano.hpp"
#include "Mappa.hpp"


    void Piano::setPos_Scale_Salire (int scale){ this->pos_scale_salire = scale;}
    void Piano::setPos_Scale_Scendere (int scale) { this->pos_scale_scendere = scale;}
    int Piano::getPos_Scale_Salire (){ return this->pos_scale_salire;}
    int Piano::getPos_Scale_Scendere (){ return this->pos_scale_scendere;}

    void Piano::crea(int n, int scale2){
        for (int i = 0; i < n; i++){
            Mappa map;
            //TODO ALGORITMO CHE CREA MAPPA
            arr_mappe[i] = map; // = funzione che mi passa il matte.
            //TODO ALGORITMO PER SELEZIONARE IN CHE MAPPA METTERE LE SCALE. VERRANNO MESSE DA UNA FUNZIONE CHE FARA IL MATTE

            int scale_salire = -1;// LE SCALE PER SALIRE E SCENDERE NON SARANNO MAI NELLO STESSO PIANO
            while (scale_salire == scale2){
                //RANDOM DA 0 A N NON COMPRESO
            }
            pos_scale_salire =  scale_salire;
            int scale_scendere = scale2; //LA POSIZIONE DELLE SCALE PER SCENDERE VIENE PASSATA DALLA LISTA TORRE E DAL PIANO PRECEDENTE
            //TODO ALGORITMO PER COLLEGARE MAPPE

        }
        for (int i = n; i < 50; i++){
            arr_mappe[i] = 0; // 0 SIGNIFICA CHE LA MAPPA NON ESISTE.
        }
    }

};
