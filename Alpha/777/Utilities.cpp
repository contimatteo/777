//
// Created by Matteo Conti on 10/10/17.
//

#include <iostream>
#include "Utilities.hpp"
#include <SFML/System/Vector2.hpp>
using namespace sf;

 const int Utilities::DIMENSIONE_CELLE = 20;
 const int Utilities::ALTEZZA_FINESTRA_GIOCO = 600;
 const int Utilities::LARGHEZZA_FINESTRA_GIOCO = 600;
 const int Utilities::NUMERO_CASELLE_ASSE_X=60;
 const int Utilities::NUMERO_CASELLE_ASSE_Y=60;
 const int Utilities::NUMERO_NEMICI_MASSIMO=100;

// --------------------------------------------

Vector2<int> lista_posizioni[100];
int lunghezza_array_posizioni = -1;
const int max_value = 30;
const int min_value = 1;

// funzioni
bool controlloDuplicato(Vector2<int> pos)
{
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        if(lista_posizioni[i]==pos)
        {
            //std::cout<<"posizione gia presente: ("<<lista_posizioni[i].x<<", "<<lista_posizioni[i].y<<") \n";
            //std::cout<<"in posizione --> "<<i<<"\n";
            return true;
        }
    }
    return false;
}

Vector2<int> generaPosizioneRandom()
{
    int rand_x = rand()%(max_value-min_value + 1) + min_value;
    int rand_y = rand()%(max_value-min_value + 1) + min_value;
    Vector2<int> posizione_corrente = {rand_x, rand_y};
    // controllo che non sia già stata creata una posizione uguale
    if(controlloDuplicato(posizione_corrente))
        generaPosizioneRandom();
    else
    {
        // incremento la lunghezza dell'array
        lunghezza_array_posizioni+=1;
        // aggiungo la nuova posizione all'array di posizioni create
        lista_posizioni[lunghezza_array_posizioni]=posizione_corrente;
        //std::cout<<"["<<lunghezza_array_posizioni<<"] - "<<"posizione casuale generata: ("<<posizione_corrente.x<<", "<<posizione_corrente.y<<") \n";
        return posizione_corrente;
    }
}
