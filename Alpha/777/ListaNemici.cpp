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


//creare una funzione che generi i nemici
void ListaNemici::creaNemici(int pianoCorrente, int stanzaCorrente)
{
    //Vector2<int> posizione_nemico_corrente(,0);
    numeroNemici=calcolaLunghezza(pianoCorrente, stanzaCorrente);
    for(int i=0; i<numeroNemici; i++)
    {
        Vector2<int> posizione_nemico_corrente(array_nemici[i]->posX,array_nemici[i]->posY);
        // genero una hasmap di interi per la posizione (casuale)
        posizione_nemico_corrente=util.generaPosizioneRandom();
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
        if (abs(array_nemici[i]->posX - eroe.posX) <= util.DIMENSIONE_CELLE)
        {
            eroe.setVitaAttuale(vita - 10);
        } else if(abs(array_nemici[i]->posY - eroe.posY) <= util.DIMENSIONE_CELLE)
            {
                eroe.setVitaAttuale(vita - 10);
            }
    }
}

// in caso di scontro con un nemico creare una funzione che elimini il nemico
// funzione che richiamo quanod il personaggio attacca
void ListaNemici::eliminaNemico(Personaggio eroe1)
{
    for (int i=0; i<numeroNemici; i++)
    {
        if(abs(eroe1.posX-array_nemici[i]->posX)<=20)
        {
            array_nemici[i]->vita=array_nemici[i]->vita-eroe1.getPotenza();
        }else if(abs(eroe1.posY-array_nemici[i]->posY)<=20)
            {
                array_nemici[i]->vita=array_nemici[i]->vita-eroe1.getPotenza();
            }
        // sposto il nemico fuori dalla mappa
        if (array_nemici[i]->vita<=0)
        {
            array_nemici[i]->posX=9999;
            array_nemici[i]->posY=9999;
        }

    }
}

// liberare l'array lista nemici
void ListaNemici::cancellaArray()
{
    // riazzero il numero di nemici
    numeroNemici=0;
    // cancello l'array
    delete *array_nemici;
}


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
        posizione_nemico_corrente=util.generaPosizioneRandom();
        // creo un nemico
        array_nemici[i]= new Nemico(3, posizione_nemico_corrente.x, posizione_nemico_corrente.y, i, 10);
    }
}