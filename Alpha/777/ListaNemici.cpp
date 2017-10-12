#include "ListaNemici.hpp"
// Created by enrico on 11/10/2017.
//
#include <iostream>
#include <math.h>
#include "Personaggio.hpp"
#include "Utilities.hpp"


using namespace sf;



int calcolaLunghezza(int piano , int stanza)
{
    //lughezza dell array (numero nemici nella stanza)
    return ((piano+stanza)*2);
}


Vector2<int> generoPosizioneRandom()
{
    /*
    //for (int i=0; i)
    Vector2 <int> posizione;
    posizione.x= rand()%60;
    posizione.y=rand ()%60;
    // 1)genero una coppia di numeri random
    // 2)se non appartengono già all'array delle posizioni usate e non è na casella grafica della mappa --> ritorna il valore
    // 3)altrimenti genero un'altra coppia ...
    // 4)controllo che la posizione generata non sia occupata da un muro,porta,personaggio

     */
     return {0,0};
}

//creare una funzione che generi i nemici

void ListaNemici::creaNemici(int pianoCorrente, int stanzaCorrente)
{
    //Vector2<int> posizione_nemico_corrente(,0);

    numeroNemici=calcolaLunghezza(pianoCorrente, stanzaCorrente);
    for(int i=0; i<numeroNemici; i++)
    {
        Vector2<int> posizione_nemico_corrente(array_nemici[i]->posX,array_nemici[i]->posY);
        // genero una hasmap di interi per la posizione (casuale)
        posizione_nemico_corrente=generoPosizioneRandom();

        // creo un nemico
        array_nemici[i]= new Nemico(3, posizione_nemico_corrente.x, posizione_nemico_corrente.y, i, 10);
    }

}


//creare una funzione che controlli se il nemico si trova a DIST=5 dal personaggio e togliere vita al personaggio

void ListaNemici::attaccoNemico(Personaggio &eroe)
{
    int vita=eroe.getVitaAttuale();
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    //controllo la distanza
    for( int i=0; i<numeroNemici; i++)
    {
        //if(valore assluto di posizione personaggio-posizione nemico == distanza minima ) allora attacca senno i++
        if (fabs(array_nemici[i]->posX - eroe.posX) <= util.DIMENSIONE_CELLE)
        {
            eroe.setVitaAttuale(vita - 10);
        } else if(fabs(array_nemici[i]->posY - eroe.posY) <= util.DIMENSIONE_CELLE)
            {
                eroe.setVitaAttuale(vita - 10);
            }
    }
    return ;
}

// in caso di scontro con un nemico creare una funzione che elimini il nemico
// funzione che richiamo quanod il personaggio attacca
void ListaNemici::eliminaNemico(Personaggio eroe1)
{

    for (int i=0; i<numeroNemici; i++)
    {
       // if(eroe1.posX)
        if (array_nemici[i]->vita<0)
        {
            array_nemici[i]->posX=30000;
            array_nemici[i]->posY=30000;
        }
    }


    //entrare dentro l array nella posizione del nemico da cancellare e rimuoverlo dall array

    return;
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