//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include "Piano.hpp"
#include "Mappa.hpp"

#ifndef INC_777_LISTATORRE_H
#define INC_777_LISTATORRE_H



class ListaTorre{

    public:
    struct nodo {
        nodo *precedente;
        Piano piano; // UN OGGETTO CONTENTENTE UN ARRAY DI N ELEMENTI PARI AL NUMERO DI MAPPE DEL PIANO.
        nodo *successivo;
    };
        typedef nodo *Lista;

        Lista torre = new nodo;

        ListaTorre (){
        torre->precedente = NULL;
        torre ->successivo = NULL;
        torre->piano.crea(pianoMassimoRaggiunto , -1); //fare funzione che crea un piano di X mappe (1 in questo caso)
        }

        int getPianoAttuale ();
        int getPianoMassimoRaggiunto();
        void setPianoMassimoRaggiunto( int piano );
        void setPianoAttuale (int piano);
        void creaProssimoPiano ();
        void prossimoPiano ();
        void pianoPrecedente ();

    private:
        int pianoMassimoRaggiunto = 1;
        int pianoAttuale = 1;

};

#endif //INC_777_LISTATORRE_H
