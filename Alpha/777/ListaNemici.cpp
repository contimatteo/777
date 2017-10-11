//
// Created by enrico on 11/10/2017.
//
#include <iostream>
#include "ListaNemici.hpp"

using namespace sf;

int calcolaLunghezza(int piano , int stanza)
{
    //lughezza dell array (numero nemici nella stanza)
    return ((piano+stanza)*2);
}


Vector2<int> generoPosizioneRandom()
{
    // genero una coppia di numeri random
    // se non appartengono già all'array delle posizioni usate e non è na casella grafica della mappa --> ritorna il valore
    // altrimenti genero un'altra coppia ...
    return {0,0};
}


ListaNemici::ListaNemici(int stack)
{
    // posizioni random per istanza nemico
    Vector2<int> posizione_nemico_corrente(0,0);
    int randomX=0, randomY=0;
    // ...
    numeroNemici=calcolaLunghezza(1, 1);
    for(int i=0; i<numeroNemici; i++)
    {
        // genero una hasmap di interi per la posizione (casuale)
        posizione_nemico_corrente=generoPosizioneRandom();
        // creo un nemico
        array_nemici[i]= new Nemico(3, posizione_nemico_corrente.x, posizione_nemico_corrente.y, i, 10);
    }
}