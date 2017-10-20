//
// Created by Mattia_Porcelli on 10/10/2017.
//
#include <time.h>
#include <c++/cstdlib>
#include <c++/iostream>
#include "Mappa.hpp"

/*LEGENDA:

 0 = sfondo nero.
 1 = angolo in alto a sinistra;
 2 = angolo in alto a destra;
 3 = angolo in basso a sinistra;
 4 = angolo in basso a destra;
 5 = muro orizzontale;
 6 = muro verticale;
 7 = porta;
 8 = scale scendere;
 9 = erba;
 11 = scale salire;
*/

void Mappa::crea_mappa(int n) {
        id = n;
        //srand(static_cast<unsigned int> (time(0)));
        // RIEMPO LA LOCATION DI BACKGROUND NERO
        for (int x = 0; x < 20; x++){
            for (int y = 0; y < 20; y++ ){
                location[x][y] = 0;
            }
        }
        // RANDOMIZZO GLI ANGOLI DELA MAPPA
        int e1x, e2x, e3x, e4x, e1y, e2y, e3y, e4y;
        e1x = rand() % 7;
        e1y = rand() % 7;                //edge1 = angolo in alto a sinistra

        e2x = rand() % 7;                //edge3 = angolo in basso a sinistra
        e2y = (rand() % 6) + 14;

        e3x = (rand() % 6) + 14;           //edge2 = angolo in alto a destra
        e3y = rand() % 7;

        e4x = (rand() % 6) + 14;           //egde4 = angolo in basso a destra
        e4y = (rand() % 6) + 14;

        location[e1x][e1y] = 1;
        location[e2x][e2y] = 2;
        location[e3x][e3y] = 3;
        location[e4x][e4y] = 4;
        // CONTROLLO LA POSIZIONE DEGLI ANGOLI DELLA MAPPA E CREO LE CONGIUNZIONI NECESSARIE.
        if (e1x == e2x){
            for (int i = e1y+1; i < e2y; i++){
                location[e1x][i] = 5;

            }
        } else {
            if (e1x > e2x){
                //----------------- PERNO DI COLLEGAMENTO-------------------------
                int t;
                t = (rand () % 4) + 2;
                t = e1y + t;

                for (int i = e1y+1; i < t; i++ ){
                    location[e1x][i] = 5;
                }

                location[e1x][t] = 4;
                //------------------------------------------------------------------------

                for (int i = e1x - 1; i > e2x ; i--){
                    location[i][t] = 6;
                }
                location[e2x][t] = 1;
                for (int i = t+1; i < e2y; i++){
                    location[e2x][i] = 5;
                }
            } else {
                // edge1x < edge2x
                //------------------------ PERNO DI COLLEGAMENTO 1 --------------------------
                int t, k;
                k = (e2y-e1y)/2;
                if (k > 2)
                    t = ( rand ()% (k-1) ) + k ;
                else t = 4;
                t = e1y + t;

                for (int i = e1y + 1; i < t; i++){
                    location[e1x][i] = 5;
                }
                location[e1x][t] = 2;
                //------------------------- PERNO DI COLLEGAMENTO 2 --------------------------

                for (int i = e1x + 1; i < e2x; i++){
                    location[i][t] = 6;
                }
                location[e2x][t] = 3;
                for (int i = t+1; i < e2y; i++){
                    location[e2x][i] = 5;
                }
            }
        }
        if (e1y == e3y){
            for (int i = e1x + 1; i< e3x; i++){
                location[i][e1y] = 6;
            }
        }else {
            if (e1y < e3y){

                int t, k;
                k = (e3x-e1x)/2;
                if (k > 2)
                    t = ( rand ()% (k-1) ) + k ;
                else t = 4;
                t = e1x + t;

                for (int i = e1x + 1; i < t; i++){
                    location[i][e1y] = 6;
                }
                location[t][e1y] = 3;
                //----------------------- PERNO DI COLLEGAMENTO 2 ------------------------------
                for (int i = e1y +1; i < e3y; i++){
                    location[t][i] = 5;
                }
                location[t][e3y] = 2;
                for (int i = t+1 ; i < e3x; i++){
                    location[i][e3y] = 6;
                }
            } else {
                //e1y> e3y
                //------------------- PERNO DI COLLEGAMENTO 1 ---------------------------------
                int  t , k;
                t = (rand() % 4) + 2;
                t = e1x + t;

                for (int i = e1x + 1; i < t; i++){
                    location[i][e1y] = 6;
                }
                location[t][e1y] = 4;
                //--------------------- PERNO DI COLLEGAMENTO 2 ------------------------------------
                for (int i = e1y - 1; i > e3y; i--){
                    location[t][i] = 5;
                }
                location [t][e3y] = 1;
                for (int i = t + 1; i < e3x; i++){
                    location[i][e3y]= 6;
                }
            }
        }

        if (e3x == e4x){
            for (int i = e3y +1 ; i< e4y; i++){
                location[e3x][i] = 5;
            }
        } else {
            if (e3x > e4x){

                int t, k;
                k = (e4y-e3y)/2;
                if (k > 2)
                    t = ( rand ()% (k-1) ) + k ;
                else t = 4;
                t = t+ e3y;

                for (int i = e3y + 1; i < t; i++){
                    location[e3x][i] = 5;
                }
                location[e3x][t] = 4;

                for (int i = e3x - 1; i > e4x; i--){
                    location[i][t] = 6;
                }
                location[e4x][t] = 1;

                for (int i = t + 1; i < e4y; i++){
                    location [e4x][i] = 5;

                }
            } else {
                //e3x < e4x
                int t;
                t = (rand () % 4) + 2;
                t = e3y + t;

                for (int i = e3y + 1; i < t; i++){
                    location [e3x][i] = 5;
                }
                location [e3x][t] = 2;

                for (int i = e3x + 1; i < e4x; i++){
                    location [i][t] = 6;
                }
                location [e4x][t] = 3;

                for (int i = t+1; i < e4y; i++){
                    location [e4x][i] = 5;
                }
            }
        }

        if (e2y == e4y ){
            for (int i = e2x + 1; i < e4x; i++){
                location[i][e2y] = 6;
            }
        }else {
            if (e2y > e4y){
                int t, k;
                k = (e4x-e2x)/2;
                if (k > 2)
                    t = ( rand ()% (k-1) ) + k ;
                else t = 4;
                t = t + e2x + 0;

                for (int i = e2x + 1; i < t; i++){
                    location [i][e2y] = 6;
                }
                location [t][e2y] = 4;

                for (int i = e2y -1; i > e4y; i--){
                    location[t][i] = 5;
                }
                location [t][e4y] = 1;

                for (int i = t + 1 ; i < e4x; i++){
                    location[i][e4y] = 6;
                }
            } else {
                //e2y < e4y
                int t;
                t = (rand ()% 4) + 2;
                t = e2x+t;

                for (int i = e2x +1; i < t; i++){
                    location [i][e2y] = 6;
                }

                location [t][e2y] = 3;

                for (int i = e2y + 1; i < e4y; i++){
                    location[t][i] = 5;
                }

                location [t][e4y] = 2;
                for (int i = t + 1; i < e4x; i++){
                    location [i][e4y] = 6;
                }
            }
        }
}

void Mappa::riempi_mappa(){

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){

            if (location[i][j] == 5 || (location[i][j]>= 1 && location[i][j] <= 4)){
                bool flag = false;
                for (int x = i + 1; x < 20; x++){
                    if (location[x][j] >= 1 && location[x][j] <= 6)
                        flag = true;
                }
                int x = i + 1;
                while (flag == true && x < 20){

                    if (location[x][j] == 0 || location[x][j] == 9) {
                        location[x][j] = 9;

                    }
                    else if (location [x][j] != 8 && location[x][j] != 11)
                        flag = false;
                    x++;
                }
            }


        }
    }

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if (location[i][j] == 6 ||(location[i][j]>= 1 && location[i][j] <= 4)){
                bool flag = false;
                for (int y = j + 1; y < 20; y++){
                    if (location[i][y] >= 1 && location[i][y] <= 6)
                        flag = true;
                }
                int y = j+1;

                while (flag == true && y <20){
                    if (location[i][y] == 0 || location[i][y] == 9)
                        location[i][y] = 9;
                    else if (location [i][y] != 8 && location[i][y] != 11)
                        flag = false;
                    y++;
                }
            }
        }
    }

}


void Mappa::inserisci_porta(int n , int k){ //N indica il numero di porta; k è l'identificativo della stanza da collegare.
        int px, py;
        do{
        px = rand() % 20;
        py = rand() % 20;
        } while (location[px][py] != 6 && location[px][py]!= 5 );
        location[px][py] = 7;
        porte[n] = k;

}

void Mappa::setNull(){
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            location[i][j] = 0;
        }
    }
}

bool Mappa::isNull(){
    bool flag = true;
    for (int i = 0; i < 20; i++){
        for (int j = 0 ; j < 20; j++){
            if (location[i][j] != 0)
                flag = false;
        }
    }
    return flag;
}

void Mappa::inserisci_scala_salire(){
    int px, py;
    //srand(time(0));
    do{
        px = rand() % 20;
        py = rand() % 20;
    } while (location[px][py] < 9);
    location[px][py] = 11;
}

void Mappa::inserisci_scala_scendere(){
    int px, py;
    //srand(time(0));
    do{
        px = rand() % 20;
        py = rand() % 20;

    } while (location[px][py] < 9);
    location[px][py] = 8;
}

int Mappa::restituisci_valore(int x, int y){
    return (location[x][y]);
}