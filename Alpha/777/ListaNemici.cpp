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
void ListaNemici::nemicoAttaccaPersonaggio(Personaggio &eroe)
{
    int vita=eroe.getVitaAttuale();
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    //controllo la distanza
    for( int i=0; i<numeroNemici; i++)
    {
        std::cout<<"\n posizione eroe --> ["<< eroe.pos_cella_x<< ", "<< eroe.pos_cella_y <<"] ------ ";
        std::cout<<"posizione nemico --> ["<< array_nemici[i]->pos_cella_x<< ", "<< array_nemici[i]->pos_cella_y <<"] \n";
        // controllo se c'è un nemico vicino rispetto all'asse x
        if ((abs(array_nemici[i]->posX - eroe.posX) <= util.SPAZIO_CELLE)&&(array_nemici[i]->posY==eroe.posY))
        {
            std::cout<<"trovato un nemico vicino lungo l'asse x -->  \n";
            eroe.setVitaAttuale(vita - array_nemici[i]->attacco);
        }
        // controllo se c'è un nemico vicino rispetto all'asse y
        else if((abs(array_nemici[i]->posY - eroe.posY) <= util.SPAZIO_CELLE)&&(array_nemici[i]->posX==eroe.posX))
        {
            std::cout<<"trovato un nemico vicino lungo l'asse y \n";
            eroe.setVitaAttuale(vita - array_nemici[i]->attacco);
        }
    }
}

// in caso di scontro con un nemico creare una funzione che elimini il nemico
// funzione che richiamo quanod il personaggio attacca
void ListaNemici::eliminaNemicoInPosizione(int posizione)
{
    for (int i=posizione; i<numeroNemici-1; i++)
    {
        array_nemici[i] = array_nemici[i+1];
    }
    // decremento di uno l'array di nemici
    numeroNemici=numeroNemici-1;
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