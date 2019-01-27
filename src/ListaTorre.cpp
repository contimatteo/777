//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Piano.hpp"
#include "ListaTorre.hpp"

int ListaTorre::getPianoAttuale (){return pianoAttuale;}

//SI DA PER ACCERTATO CHE QUESTA FUNZIONE VENGA RICHIAMATA SOLO QUANDO TORRE--> SUCCESSIVO è UGUALE A NULL
void ListaTorre::creaProssimoPiano ()
{
    pianoMassimoRaggiunto++;
    Lista tmp = new nodo;
    tmp->piano.crea(pianoMassimoRaggiunto, rand() % pianoMassimoRaggiunto);
    while (torre->successivo != NULL)
    {
        torre= torre-> successivo;
    }
    torre->successivo = tmp;
    tmp->precedente = torre;
    tmp->successivo = NULL;
    torre = torre-> successivo;
}

    void ListaTorre::prossimoPiano(){
        if (torre->successivo != NULL) {
            pianoAttuale++;
            torre = torre->successivo; //QUANDO NEL PIANO SUCCESSIVO C'è GIA STATO
        }
        else {
            pianoAttuale++;
            ListaTorre::creaProssimoPiano();
        } //ALTRIMENTI CREA IL PIANO SUCCESSIVO
    }

//SI DA PER ACCERTATO CHE NON VENGA RICHIAMATA QUANDO PRECEDENTE è UGUALE A NULL PERCHé NELLA PRIMA ED UNICA MAPPA DEL PRIMO
//LIVELLO NON SONO PRESENTI LE SCALE PER TORNARE INDIETRO.
void ListaTorre::pianoPrecedente (){
    if (torre->precedente != NULL) {
        torre = torre->precedente;
        pianoAttuale--;
    }
}
