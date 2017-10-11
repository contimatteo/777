#include "ListaNemici.hpp"//
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
    // 1)genero una coppia di numeri random
    // 2)se non appartengono già all'array delle posizioni usate e non è na casella grafica della mappa --> ritorna il valore
    // 3)altrimenti genero un'altra coppia ...
    // 4)controllo che la posizione generata non sia occupata da un muro,porta,personaggio
    return {0,0};
}


//creare una funzione che generi i nemici

void creaNemici(int pianoCorrente, int stanzaCorrente)//da passare anche l array
{
    Vector2<int> posizione_nemico_corrente(0,0);

    int numeroNemici=calcolaLunghezza(pianoCorrente, stanzaCorrente);
    for(int i=0; i<numeroNemici; i++)
    {
        // genero una hasmap di interi per la posizione (casuale)
        posizione_nemico_corrente=generoPosizioneRandom();
        // creo un nemico
        //array_nemici[i]= new Nemico(3, posizione_nemico_corrente.x, posizione_nemico_corrente.y, i, 10);
    }

}


//creare una funzione che controlli se il nemico si trova a DIST=5 dal personaggio e togliere vita al personaggio

int attaccoNemico(int pianoAttuale, int stanzaAttuale)
{
    //dichiaro la variabile che sara poi la nuova vita del personaggio in caso di scontro con nemico
    int  nuovaVita;
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    int lunghezzaArray=calcolaLunghezza(pianoAttuale,stanzaAttuale);
    //controllo la distanza
    for( int i=0; i<lunghezzaArray; i++)
    {
        //if(valore assluto di posizione personaggio-posizione nemico == distanza minima ) allora attacca senno i++
    }

    return (nuovaVita);
}

//in caso di scontro con un nemico creare una funzione che elimini il nemico

void eliminaNemico(){

    //entrare dentro l array nella posizione del nemico da cancellare e rimuoverlo dall array
}

//liberare l'array lista nemici
//...




//costruttore
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