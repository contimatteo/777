//
// Created by enrico on 11/10/2017.
//
#include <iostream>
#include "ListaNemici.hpp"

int calcolaLunghezza(int piano , int stanza)
{
    //lughezza dell array (numero nemici nella stanza)
    return ((piano+stanza)*2);
}
/*
vector2i generoPosizioneRandom()
{
    return {0,0};
}
 */

ListaNemici::ListaNemici(int stack)
{
    // posizioni random per istanza nemico
    //vector2i mappa_posizione_nemico_corrente;
    int randomX=0, randomY=0;
    // ...
    numeroNemici=calcolaLunghezza(1, 1);
    for(int i=0; i<numeroNemici; i++)
    {
        //mappa_posizione_nemico_corrente=generoPosizioneRandom();
        // genero una hasmap di interi per la posizione (casuale)
        //Nemico nemicoCorrente(3, randomX, randomY, i, 10);
        array_nemici[i]= new Nemico(3, randomX, randomY, i, 10);
        //array_nemici[i]=nemicoCorrente;
        //array_nemici[i]=Nemico(0);
    }
}