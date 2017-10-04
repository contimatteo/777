//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include "Piano.hpp"
#include "ListaTorre.hpp"




     //PUNTATORE AL PIANO ATTUALE



    int ListaTorre::getPianoMassimoRaggiunto(){ return pianoMassimoRaggiunto; }
    int ListaTorre::getPianoAttuale (){return pianoAttuale;}
    void ListaTorre::setPianoMassimoRaggiunto( int piano ) {this->pianoMassimoRaggiunto = piano;}
    void ListaTorre::setPianoAttuale (int piano){this->pianoAttuale = piano;}

    //SI DA PER ACCERTATO CHE QUESTA FUNZIONE VENGA RICHIAMATA SOLO QUANDO TORRE--> SUCCESSIVO è UGUALE A NULL
    void ListaTorre::creaProssimoPiano (){
        lista tmp = new nodo;
        torre->successivo = tmp;
        tmp->precedente = torre;
        tmp = torre;
        torre = torre->successivo;
        torre->piano.crea(pianoMassimoRaggiunto+1, tmp->piano.getPos_Scale_Salire);
        delete(tmp);
        //
    }


    void ListaTorre::prossimoPiano (){
        if (torre->successivo != nullptr)
            torre = torre->successivo; //QUANDO NEL PIANO SUCCESSIVO C'è GIA STATO
        else creaProssimoPiano; //ALTRIMENTI CREA IL PIANO SUCCESSIVO
    }

    //SI DA PER ACCERTATO CHE NON VENGA RICHIAMATA QUANDO PRECEDENTE è UGUALE A NULL PERCHé NELLA PRIMA ED UNICA MAPPA DEL PRIMO
    //LIVELLO NON SONO PRESENTI LE SCALE PER TORNARE INDIETRO.
    void ListaTorre::pianoPrecedente (){ torre = torre->precedente;}
};