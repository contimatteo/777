//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include <c++/cstdlib>
#include <c++/ctime>
#include <c++/iostream>
#include "Piano.hpp"
#include "ListaTorre.hpp"

/*
struct nodo {
    nodo *precedente;
    Piano piano; // UN OGGETTO CONTENTENTE UN ARRAY DI N ELEMENTI PARI AL NUMERO DI MAPPE DEL PIANO.
    nodo *successivo;
};
typedef nodo *Lista;*/


     //PUNTATORE AL PIANO ATTUALE



    int ListaTorre::getPianoMassimoRaggiunto(){ return pianoMassimoRaggiunto; }
    int ListaTorre::getPianoAttuale (){return pianoAttuale;}
    void ListaTorre::setPianoMassimoRaggiunto( int piano ) {this->pianoMassimoRaggiunto = piano;}
    void ListaTorre::setPianoAttuale (int piano){this->pianoAttuale = piano;}

    //SI DA PER ACCERTATO CHE QUESTA FUNZIONE VENGA RICHIAMATA SOLO QUANDO TORRE--> SUCCESSIVO è UGUALE A NULL
    void ListaTorre::creaProssimoPiano () {
        //srand(time(0));
        pianoMassimoRaggiunto++;
        Lista tmp = new nodo;
        tmp->piano.crea(pianoMassimoRaggiunto, rand() % pianoMassimoRaggiunto);

        while (torre->successivo != NULL){
            torre= torre-> successivo;
        }
        torre->successivo = tmp;
        tmp->precedente = torre;
        //tmp = tmp2;

        //tmp2 = tmp2->successivo;
        tmp->successivo = NULL;
        torre = torre-> successivo;
        //delete (tmp);
        //
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
