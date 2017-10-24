//
// Created by Matteo Conti on 10/10/17.
//

#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include "Utilities.hpp"
using namespace sf;

const int Utilities::NUMERO_NEMICI_MASSIMO = 200;

const int Utilities::NUMERO_CASELLE_ASSE_X = 20;
const int Utilities::NUMERO_CASELLE_ASSE_Y = 20;

sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
const int Utilities::SPAZIO_CELLE = 25;
const int Utilities::DIMENSIONE_CELLE = 24;

const int Utilities::ALTEZZA_DISPLAY = desktop.height;
const int Utilities::LARGHEZZA_DISPLAY = desktop.width;

const int Utilities::ALTEZZA_MAPPA = SPAZIO_CELLE*NUMERO_CASELLE_ASSE_Y;
const int Utilities::LARGHEZZA_MAPPA = SPAZIO_CELLE*NUMERO_CASELLE_ASSE_X;
//const int Utilities::POSIZIONE_PARTENZA_MAPPA_X = (((desktop.width/(SPAZIO_CELLE+1)-NUMERO_CASELLE_ASSE_X)/2))*SPAZIO_CELLE;
//const int Utilities::POSIZIONE_PARTENZA_MAPPA_Y = (((desktop.height/(SPAZIO_CELLE+1))-NUMERO_CASELLE_ASSE_Y)/2)*SPAZIO_CELLE;
const int Utilities::POSIZIONE_PARTENZA_MAPPA_X = (((desktop.width/(SPAZIO_CELLE+1)-NUMERO_CASELLE_ASSE_X)/2))*SPAZIO_CELLE;
const int Utilities::POSIZIONE_PARTENZA_MAPPA_Y = (((desktop.height/(SPAZIO_CELLE+1))-NUMERO_CASELLE_ASSE_Y)/2)*SPAZIO_CELLE;

const int Utilities::MARGINE_MAPPA = 40;
const sf::Color Utilities::COLORE_SFONDO = Color::Black;

const int Utilities::ALTEZZA_FINESTRAsx = ALTEZZA_MAPPA + (2*MARGINE_MAPPA);
// l'8 finale è aggiunto perchè c'è un bug nel posizionamento sull'asse x della finestra sinistra
const int Utilities::LARGHEZZA_FINESTRAsx = ((LARGHEZZA_DISPLAY)-(LARGHEZZA_MAPPA+POSIZIONE_PARTENZA_MAPPA_X)-(6*MARGINE_MAPPA))/2 /*+ 8*/;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAsx_X = MARGINE_MAPPA+LARGHEZZA_FINESTRAsx;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAsx_Y = POSIZIONE_PARTENZA_MAPPA_Y-MARGINE_MAPPA;

const int Utilities::ALTEZZA_FINESTRAdx = ALTEZZA_MAPPA + (2*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_FINESTRAdx = ((LARGHEZZA_DISPLAY)-(LARGHEZZA_MAPPA+POSIZIONE_PARTENZA_MAPPA_X)-(6*MARGINE_MAPPA))/2;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAdx_X = POSIZIONE_PARTENZA_MAPPA_X+LARGHEZZA_MAPPA+(4*MARGINE_MAPPA);
const int Utilities::POSIZIONE_PARTENZA_FINESTRAdx_Y = POSIZIONE_PARTENZA_MAPPA_Y-MARGINE_MAPPA;

const int Utilities::ALTEZZA_CONSOLE = (ALTEZZA_DISPLAY)-(ALTEZZA_MAPPA+POSIZIONE_PARTENZA_MAPPA_Y)-(6*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_CONSOLE = (LARGHEZZA_MAPPA + (4*MARGINE_MAPPA))+(LARGHEZZA_FINESTRAsx)+(LARGHEZZA_FINESTRAdx);
const int Utilities::POSIZIONE_PARTENZA_CONSOLE_X = POSIZIONE_PARTENZA_MAPPA_X-LARGHEZZA_FINESTRAsx-(2*MARGINE_MAPPA);
const int Utilities::POSIZIONE_PARTENZA_CONSOLE_Y = POSIZIONE_PARTENZA_MAPPA_Y+ALTEZZA_MAPPA+(2*MARGINE_MAPPA);

// --------------------------------------------

Vector2<int> lista_posizioni[100];
int lunghezza_array_posizioni = -1;
const int min_value = 0;
const int max_value = Utilities::NUMERO_CASELLE_ASSE_X-1;

// funzioni
bool Utilities::controlloDuplicato(Vector2<int> pos)
{
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        if(lista_posizioni[i]==pos)
        {
            return true;
        }
    }
    return false;
}


void Utilities::azzeraPosizioni()
{
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        lista_posizioni[i]={1,1};
    }
    lunghezza_array_posizioni=-1;
}

Vector2<int> Utilities::generaPosizioneRandom()
{
    azzeraPosizioni();
    int rand_x = rand()%(max_value-min_value + 1) + min_value;
    int rand_y = rand()%(max_value-min_value + 1) + min_value;
    Vector2<int> posizione_corrente = {rand_x, rand_y};
    // controllo che non sia già stata creata una posizione uguale
    if(controlloDuplicato(posizione_corrente))
        // controllo che in questa posizione non ci sia un muro, una porta o un personaggio
        // if(funzione_porc_mi_dà_ok)
        generaPosizioneRandom();
    else
    {
        if((rand_x!=0)&&(rand_y!=0)) {
            // incremento la lunghezza dell'array
            lunghezza_array_posizioni += 1;
            // aggiungo la nuova posizione all'array di posizioni create
            lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
            //std::cout<<"["<<lunghezza_array_posizioni<<"] - "<<"posizione casuale generata: ("<<posizione_corrente.x<<", "<<posizione_corrente.y<<") \n";
            return posizione_corrente;
        }
        else
            generaPosizioneRandom();
    }
}

Vector2<int> Utilities::generaPosizioneRandom(int eroe_x, int eroe_y)
{
    std::cout<<SPAZIO_CELLE<<" ~ "<<DIMENSIONE_CELLE<<"\n";
    int rand_x = rand()%(max_value-min_value + 1) + min_value;
    int rand_y = rand()%(max_value-min_value + 1) + min_value;
    Vector2<int> posizione_corrente = {rand_x, rand_y};
    // controllo che non sia già stata creata una posizione uguale
    if(controlloDuplicato(posizione_corrente))
        // controllo che in questa posizione non ci sia un muro, una porta o un personaggio
        // if(funzione_porc_mi_dà_ok)
        generaPosizioneRandom(eroe_x, eroe_y);
    else
    {
        // incremento la lunghezza dell'array
        lunghezza_array_posizioni += 1;
        // aggiungo la nuova posizione all'array di posizioni create
        lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
        //std::cout<<"["<<lunghezza_array_posizioni<<"] - "<<"posizione casuale generata: ("<<posizione_corrente.x<<", "<<posizione_corrente.y<<") \n";
        return posizione_corrente;
    }
}
