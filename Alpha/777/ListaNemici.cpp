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
    if((piano+stanza)*2<=NUMERO_NEMICI_MASSIMO)
        return ((piano+stanza)*2);
    else
        return (NUMERO_NEMICI_MASSIMO);
}

// funzione per spostare i nemici
void ListaNemici::spostaNemici(Personaggio &eroe, int piano, int stanza)
{
    //std::cout<<"----------------------------------- \n";
    Vector2<int> posizione={0,0};
    util.azzeraPosizioni();
    bool finito=true;
    for(int i=0; i<numeroNemici; i++)
    {
        posizione = util.generaPosizioneRandom(eroe.pos_cella_x, eroe.pos_cella_y);
        while((posizione.x+1==eroe.pos_cella_x)&&(posizione.y+1==eroe.pos_cella_y))
            // rigenero la posizione in caso che sia uguale a quella dell'eroe
            posizione = util.generaPosizioneRandom(eroe.pos_cella_x, eroe.pos_cella_y);

        posizione.x+=1;
        posizione.y+=1;
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
        array_nemici[i]->posX += (util.SPAZIO_CELLE * posizione.x);
        array_nemici[i]->posY += (util.SPAZIO_CELLE * posizione.y);
    }
}

bool ListaNemici::controlloPosizionePersonaggio(Personaggio &eroe)
{
    for (int i=0; i<numeroNemici; i++)
    {
        if((array_nemici[i]->pos_cella_x==eroe.pos_cella_x)&&(array_nemici[i]->pos_cella_y==eroe.pos_cella_y))
        {
            // c'è un nemico che occupa la posizione del personaggio
            //std::cout<<numeroNemici<<" -- Trovato un nemico con la stessa posizione del personaggio \n";
            return true;
        }
    }
    return false;
}


//creare una funzione che generi i nemici
void ListaNemici::creaNemici(int pianoCorrente, int stanzaCorrente)
{
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


void ListaNemici::nemicoAttaccaPersonaggio(Personaggio &eroe)
{
    int i = 0;
    int distanza = 1;
    bool flag = false;
    int gittata_nemico=1;
    for (int k = 0; k < numeroNemici; k++)
    {
        //std::cout<<"posizione nemico --> ["<<array_nemici[k]->pos_cella_x<<" , "<<array_nemici[k]->pos_cella_y<<"] \n";
        // controllo se c'è un nemico vicino rispetto all'asse x
        if ((abs(array_nemici[k]->pos_cella_x - eroe.pos_cella_x) == distanza) && (array_nemici[k]->pos_cella_y == eroe.pos_cella_y))
        {
            eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
            //std::cout<<"nemico attacca personaggio rispetto all'asse x \n";
        }
        // controllo se c'è un nemico vicino rispetto all'asse y
        if ((abs(array_nemici[k]->pos_cella_y - eroe.pos_cella_y) == distanza) && (array_nemici[k]->pos_cella_x == eroe.pos_cella_x))
        {
            eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
            //std::cout<<"nemico attacca personaggio rispetto all'asse y \n";
        }
        // controllo se c'è un nemico sulla diagonale 2 in basso a sx
        if ((eroe.pos_cella_y-distanza == array_nemici[k]->pos_cella_y))
        {
            if (eroe.pos_cella_x+distanza == array_nemici[k]->pos_cella_x)
            {
                eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
                //std::cout<<"nemico attacca personaggio sulla diagonale 2 in basso a sx\n";
            }
        }
        // controllo se c'è un nemico sulla diagonale 2 in alto a dx
        if ((eroe.pos_cella_y+distanza == array_nemici[k]->pos_cella_y))
        {
            if (eroe.pos_cella_x-distanza == array_nemici[k]->pos_cella_x)
            {
                eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
                //std::cout<<"nemico attacca personaggio sulla diagonale 2 in alto a dx\n";
            }
        }
        // controllo se c'è un nemico sulla diagonale 1 in basso a dx
        if ((eroe.pos_cella_y-distanza == array_nemici[k]->pos_cella_y))
        {
            if (eroe.pos_cella_x-distanza == array_nemici[k]->pos_cella_x)
            {
                eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
                //std::cout<<"nemico attacca personaggio sulla diagonale 1 in basso a dx\n";
            }
        }
        // controllo se c'è un nemico sulla diagonale 2 in alto a sx
        if ((eroe.pos_cella_y+distanza == array_nemici[k]->pos_cella_y))
        {
            if (eroe.pos_cella_x+distanza == array_nemici[k]->pos_cella_x)
            {
                eroe.vitaAttuale=eroe.vitaAttuale - array_nemici[i]->attacco;
                //std::cout<<"nemico attacca personaggio sulla diagonale 1 in alto a sx \n";
            }
        }
    }
    std::cout<<"vita eroe --> "<<eroe.vitaAttuale<<"\n";
}

void ListaNemici::stampaArray(Nemico *array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; ++i)
    {
        std::cout<<"nemico ("<<i<<") nella cella --> ["<<array[i]->pos_cella_x<<", "<<array[i]->pos_cella_y<<"] \n";
    }
}

// in caso di scontro con un nemico creare una funzione che elimini il nemico
// funzione che richiamo quando il personaggio attacca
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
        posizione_nemico_corrente=util.generaPosizioneRandom();
        while((posizione_nemico_corrente.x==0)&&(posizione_nemico_corrente.y==0))
            // genero una hasmap di interi per la posizione (casuale)
            posizione_nemico_corrente=util.generaPosizioneRandom();
        // creo un nemico
        array_nemici[i]= new Nemico(3, posizione_nemico_corrente.x, posizione_nemico_corrente.y, i, 10);
    }
}