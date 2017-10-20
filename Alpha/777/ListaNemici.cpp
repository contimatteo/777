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

// funzione per spostare i nemici
void ListaNemici::spostaNemici()
{
    Vector2<int> posizione={0,0};
    util.azzeraPosizioni();
    for(int i=0; i<numeroNemici; i++)
    {
        posizione=util.generaPosizioneRandom();
        if((posizione.x*util.SPAZIO_CELLE))
        std::cout<<i<<" -- posizione corrente  --> ["<<array_nemici[i]->pos_cella_x<<", "<<array_nemici[i]->pos_cella_y<<"] \n";
        std::cout<<i<<" -- nuova posizione  --> ["<<posizione.x<<", "<<posizione.y<<"] \n";
        std::cout<<i<<" -- lo sposto di  --> ["<<posizione.x-array_nemici[i]->pos_cella_x<<", "<<posizione.y-array_nemici[i]->pos_cella_y<<"] celle \n\n";
        // riazzero temporaneamento la loro posizione
        array_nemici[i]->spostamento_x = (util.SPAZIO_CELLE * (-array_nemici[i]->pos_cella_x));
        array_nemici[i]->spostamento_y = (util.SPAZIO_CELLE * (-array_nemici[i]->pos_cella_y));
        array_nemici[i]->muovi();
        // ridisegno i nemici nella loro posizione
        array_nemici[i]->spostamento_x = util.SPAZIO_CELLE * (posizione.x);
        array_nemici[i]->spostamento_y = util.SPAZIO_CELLE * (posizione.y);
        array_nemici[i]->muovi();
        array_nemici[i]->pos_cella_x = posizione.x;
        array_nemici[i]->pos_cella_y = posizione.y;
        array_nemici[i]->posX += (util.SPAZIO_CELLE * posizione.x) ;
        array_nemici[i]->posY += (util.SPAZIO_CELLE * posizione.y) ;
    }
}


//creare una funzione che generi i nemici
void ListaNemici::creaNemici(int pianoCorrente, int stanzaCorrente)
{
    //cancellaArray();
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
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    //controllo la distanza
    for( int i=0; i<numeroNemici; i++)
    {
        // controllo se c'è un nemico vicino rispetto all'asse x
        if ((abs(array_nemici[i]->posX - eroe.posX) == util.SPAZIO_CELLE)&&(array_nemici[i]->posY==eroe.posY))
        {
            eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
        }
        // controllo se c'è un nemico vicino rispetto all'asse y
        if((abs(array_nemici[i]->posY - eroe.posY) == util.SPAZIO_CELLE)&&(array_nemici[i]->posX==eroe.posX))
        {
            eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
        }
        // controllo se c'è un nemico vicino rispetto alla diagonale principale in alto a sinistra
        if((eroe.posY+util.SPAZIO_CELLE==array_nemici[i]->posY)&&(eroe.posX+util.SPAZIO_CELLE==array_nemici[i]->posX))
        {
            eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
        }
        // controllo se c'è un nemico vicino rispetto alla diagonale principale in basso a destra
        if((eroe.posY-util.SPAZIO_CELLE==array_nemici[i]->posY)&&(eroe.posX-util.SPAZIO_CELLE==array_nemici[i]->posX))
        {
            eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
        }
        // controllo se c'è un nemico vicono rispetto alla diagonale secondaria
        if(eroe.posX-util.SPAZIO_CELLE==array_nemici[i]->posX)
        {
            if(eroe.posY+util.SPAZIO_CELLE==array_nemici[i]->posY)
            {
                eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
            }
        }
        if(eroe.posX+util.SPAZIO_CELLE==array_nemici[i]->posX)
        {
            if(eroe.posY-util.SPAZIO_CELLE==array_nemici[i]->posY)
            {
                eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
            }
        }

    }
}

void ListaNemici::stampaArray(Nemico *array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; ++i)
    {
        std::cout<<"nemico ("<<i<<") nella cella --> ["<<array[i]->pos_cella_x<<", "<<array[i]->pos_cella_y<<"] \n";
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
    //stampaArray(array_nemici, numeroNemici);
}

// liberare l'array lista nemici
void ListaNemici::cancellaArray()
{
    // riazzero il numero di nemici
    numeroNemici=0;
    // cancello l'array
    delete *array_nemici;
}


void ListaNemici::disegnaNemici(RenderWindow &Gioco)
{
    //fare for per stampare nemici e stampare posizioni
    for (int i=0; i<numeroNemici; i++)
    {
        //nemici.array_nemici[i]->grafica.setPosition(nemici.array_nemici[i]->posX, nemici.array_nemici[i]->posY);
        Gioco.draw(array_nemici[i]->grafica);
    }
}

//costruttore
ListaNemici::ListaNemici(int stack)
{
    // posizioni random per istanza nemico
    Vector2<int> posizione_nemico_corrente(0,0);
    int randomX=0, randomY=0;
    // ...
    numeroNemici=calcolaLunghezza(10, 10);
    for(int i=0; i<numeroNemici; i++)
    {
        // genero una hasmap di interi per la posizione (casuale)
        posizione_nemico_corrente=util.generaPosizioneRandom();
        // creo un nemico
        array_nemici[i]= new Nemico(3, posizione_nemico_corrente.x, posizione_nemico_corrente.y, i, 10);
    }
}