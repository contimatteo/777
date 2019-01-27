//
// Created by Matteo Conti on 10/10/17.
//

#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include "Utilities.hpp"
using namespace sf;

const int Utilities::NUMERO_NEMICI_MASSIMO = 20;
// IMPOSTO LA STANZA NELLA QUALE IL GIOCO TERMINA E IL PLAYER VINCE
const int Utilities::GIOCO_FINITO_PIANO = 15;
const int Utilities::GIOCO_FINITO_STANZA = 15;
// NUMERO CASELLE
const int Utilities::NUMERO_CASELLE_ASSE_X = 20;
const int Utilities::NUMERO_CASELLE_ASSE_Y = 20;
// DIMESIONE_CELLE + MARGINE(=1)
const int Utilities::SPAZIO_CELLE = 41;
// DIMENSIONE DELLE CELLE
const int Utilities::DIMENSIONE_CELLE = 40;
// ALTEZZA E LARGHEZZA DELLA FINESTRA PRINCIPALE (full screen)
sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
const int Utilities::ALTEZZA_DISPLAY = desktop.height;
const int Utilities::LARGHEZZA_DISPLAY = desktop.width;
// DIMENSIONI MAPPA
const int Utilities::ALTEZZA_MAPPA = SPAZIO_CELLE*NUMERO_CASELLE_ASSE_Y;
const int Utilities::LARGHEZZA_MAPPA = SPAZIO_CELLE*NUMERO_CASELLE_ASSE_X;
// POSIZIONE DI PARTENZA DELLA MAPPA
const int Utilities::POSIZIONE_PARTENZA_MAPPA_X = (((desktop.width/(SPAZIO_CELLE+1)-NUMERO_CASELLE_ASSE_X)/2))*SPAZIO_CELLE + MARGINE_MAPPA;
const int Utilities::POSIZIONE_PARTENZA_MAPPA_Y = (((desktop.height/(SPAZIO_CELLE+1))-NUMERO_CASELLE_ASSE_Y)/2)*SPAZIO_CELLE;
// MARGINE MAPPA
const int Utilities::MARGINE_MAPPA = 40;
// COLORE DI SFONDO
const sf::Color Utilities::COLORE_SFONDO = Color::Black;
// DIMENSIONI FINESTRA SX
const int Utilities::ALTEZZA_FINESTRAsx = ALTEZZA_MAPPA + (2*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_FINESTRAsx = ((LARGHEZZA_DISPLAY/2) - (LARGHEZZA_MAPPA/2) - (2* MARGINE_MAPPA));
// POSIZIONE DI PARTENZA DELLA FINESTRA SX
const int Utilities::POSIZIONE_PARTENZA_FINESTRAsx_X = MARGINE_MAPPA;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAsx_Y = POSIZIONE_PARTENZA_MAPPA_Y-MARGINE_MAPPA;
// DIMENSIONI FINESTRA DX
const int Utilities::ALTEZZA_FINESTRAdx = ALTEZZA_MAPPA + (2*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_FINESTRAdx = ((LARGHEZZA_DISPLAY/2) - (LARGHEZZA_MAPPA/2) - (2* MARGINE_MAPPA));
// POSIZIONE DI PARTENZA DELLA FINESTRA DX
const int Utilities::POSIZIONE_PARTENZA_FINESTRAdx_X = POSIZIONE_PARTENZA_MAPPA_X+LARGHEZZA_MAPPA+ MARGINE_MAPPA;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAdx_Y = POSIZIONE_PARTENZA_MAPPA_Y-MARGINE_MAPPA;

/* CONSOLE NON IMPLEMENTATA
const int Utilities::ALTEZZA_CONSOLE = (ALTEZZA_DISPLAY)-(ALTEZZA_MAPPA+POSIZIONE_PARTENZA_MAPPA_Y)-(6*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_CONSOLE = (LARGHEZZA_MAPPA + (4*MARGINE_MAPPA))+(LARGHEZZA_FINESTRAsx)+(LARGHEZZA_FINESTRAdx);
const int Utilities::POSIZIONE_PARTENZA_CONSOLE_X = POSIZIONE_PARTENZA_MAPPA_X-LARGHEZZA_FINESTRAsx-(2*MARGINE_MAPPA);
const int Utilities::POSIZIONE_PARTENZA_CONSOLE_Y = POSIZIONE_PARTENZA_MAPPA_Y+ALTEZZA_MAPPA+(2*MARGINE_MAPPA);*/

// --------------------------------------------

// array posizioni
Vector2<int> lista_posizioni[100];
int lunghezza_array_posizioni = -1;
const int min_value = 0;
const int max_value = Utilities::NUMERO_CASELLE_ASSE_X-1;
int cont=0;

// controllo se nel mio array di posizioni c'è una posizione duplicata
bool Utilities::controlloDuplicato(Vector2<int> pos)
{
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        if(lista_posizioni[i]==pos)
        {
            return true;
        }
    }
    //std::cout<<"nessun duplicato trovato \n";
    return false;
}

// azzero l'array delle posizioni
void Utilities::azzeraPosizioni()
{
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        lista_posizioni[i]={0,0};
    }
    lunghezza_array_posizioni= (-1);
    cont=0;
}

// funzione NON USATA per eliminare una posizione dal mio array di posizioni
void Utilities::eliminaPosizione(int x, int y)
{
    int start=0;
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        if((lista_posizioni[i].x==x)&&(lista_posizioni[i].y==y))
        {
            lista_posizioni[i] = {0, 0};
            start=i;
        }
    }
    for(int k=start; k<lunghezza_array_posizioni-1; k++)
        lista_posizioni[k]=lista_posizioni[k+1];

    lunghezza_array_posizioni -= 1;
}

// funzione per controllare se la casella è percorribile
bool Utilities::controllaElementoGrafico(ListaTorre &lista_torre, int stanza, int x, int y)
{
    return (lista_torre.torre->piano.arr_mappe[stanza - 1].restituisci_valore(x, y) == 9);
}

// controllo se la posizione in input è già presente nell'array
bool Utilities::controlloPosizioneConsentita(Vector2<int> array_posizioni_consentite[], int length, Vector2<int> posizione_generata)
{
    for(int i=0; i<length; i++)
    {
        if(array_posizioni_consentite[i].x==posizione_generata.x+1)
            if(array_posizioni_consentite[i].y==posizione_generata.y+1)
            {
                //std::cout << "la posizione è nell'array di posizioni consentite \n";
                return true;
            }
    }
    return false;
}

Vector2<int> posizione_corrente={0,0};
int rand_x=0; int rand_y=0;

// genero una nuova posizione random per i nemici
void Utilities::generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int stanza, Vector2<int> &posizione_generata)
{
    // genero una coppia di numeri random
    rand_x = rand()%(max_value-min_value + 1) + min_value;
    rand_y = rand()%(max_value-min_value + 1) + min_value;
    posizione_corrente.x =rand_x;   posizione_corrente.y=rand_y;
    // controllo che non sia già stata creata una posizione uguale
    if(!controlloDuplicato(posizione_corrente) /*&& (rand_x<=NUMERO_CASELLE_ASSE_X) && (rand_y<=NUMERO_CASELLE_ASSE_X)*/)
    {
        // controllo che la mia posizione sia consentita
        if(controlloPosizioneConsentita(array_posizioni_consentite, lunghezza_arr_pos, posizione_corrente)) {
            // incremento la lunghezza dell'array
            lunghezza_array_posizioni += 1;
            // aggiungo la nuova posizione all'array di posizioni create
            lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
            // assegno la posizione generata alla variabile posizione passata per riferimento ==> return
            posizione_generata=posizione_corrente;
        }
        else
        {
            // la posizione non è consentita (è un muro o una casella percorribile)
            generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, stanza, posizione_generata);
        }
    }
    else
    {
        // ho già generato questa posizione
        generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, stanza, posizione_generata);
    }
    //return {0,0};
}

// genero una nuova posizione random per i nemici
void Utilities::generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int eroe_x, int eroe_y, int stanza, Vector2<int> &posizione_generata)
{
    // genero una coppia di numeri random
    rand_x = rand()%(max_value-min_value + 1) + min_value;
    rand_y = rand()%(max_value-min_value + 1) + min_value;
    posizione_corrente.x =rand_x;   posizione_corrente.y=rand_y;
    // controllo che la posizione corrente appena generata non sia uguale a quella dell'eroe
    if((posizione_corrente.x+1!=eroe_x) || (posizione_corrente.y+1!=eroe_y))
    {
        // controllo che non sia già stata creata una posizione uguale
        if (!controlloDuplicato(posizione_corrente) /*&& (rand_x<=NUMERO_CASELLE_ASSE_X) && (rand_y<=NUMERO_CASELLE_ASSE_X)*/)
        {
            // controllo che la mia posizione sia consentita
            if (controlloPosizioneConsentita(array_posizioni_consentite, lunghezza_arr_pos, posizione_corrente))
            {
                // incremento la lunghezza dell'array
                lunghezza_array_posizioni += 1;
                // aggiungo la nuova posizione all'array di posizioni create
                lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
                // assegno la posizione generata alla variabile posizione passata per riferimento ==> return
                posizione_generata = posizione_corrente;
            }
            else
            {
                generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, eroe_x, eroe_y, stanza, posizione_generata);
            }
        }
        else
        {

            generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, eroe_x, eroe_y, stanza, posizione_generata);
        }
    }
    else
        generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, eroe_x, eroe_y, stanza, posizione_generata);
}

// converto un intero in una stringa
std::string Utilities::convertInt(int number)
{
    return std::to_string(number);
}