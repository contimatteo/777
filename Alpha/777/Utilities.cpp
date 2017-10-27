//
// Created by Matteo Conti on 10/10/17.
//

#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include "Utilities.hpp"
using namespace sf;

const int Utilities::NUMERO_NEMICI_MASSIMO = 20;

const int Utilities::NUMERO_CASELLE_ASSE_X = 20;
const int Utilities::NUMERO_CASELLE_ASSE_Y = 20;

sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
const int Utilities::SPAZIO_CELLE = 41;
const int Utilities::DIMENSIONE_CELLE = 40;

const int Utilities::ALTEZZA_DISPLAY = desktop.height;
const int Utilities::LARGHEZZA_DISPLAY = desktop.width;

const int Utilities::ALTEZZA_MAPPA = SPAZIO_CELLE*NUMERO_CASELLE_ASSE_Y;
const int Utilities::LARGHEZZA_MAPPA = SPAZIO_CELLE*NUMERO_CASELLE_ASSE_X;
//const int Utilities::POSIZIONE_PARTENZA_MAPPA_X = (((desktop.width/(SPAZIO_CELLE+1)-NUMERO_CASELLE_ASSE_X)/2))*SPAZIO_CELLE;
//const int Utilities::POSIZIONE_PARTENZA_MAPPA_Y = (((desktop.height/(SPAZIO_CELLE+1))-NUMERO_CASELLE_ASSE_Y)/2)*SPAZIO_CELLE;
const int Utilities::POSIZIONE_PARTENZA_MAPPA_X = (((desktop.width/(SPAZIO_CELLE+1)-NUMERO_CASELLE_ASSE_X)/2))*SPAZIO_CELLE + MARGINE_MAPPA;
const int Utilities::POSIZIONE_PARTENZA_MAPPA_Y = (((desktop.height/(SPAZIO_CELLE+1))-NUMERO_CASELLE_ASSE_Y)/2)*SPAZIO_CELLE;


const int Utilities::MARGINE_MAPPA = 40;
const sf::Color Utilities::COLORE_SFONDO = Color::Black;

// l' altezza di entrambe le finestre va bene e anche la loro posizione rispetto a y
const int Utilities::ALTEZZA_FINESTRAsx = ALTEZZA_MAPPA + (2*MARGINE_MAPPA);
// l'8 finale è aggiunto perchè c'è un bug nel posizionamento sull'asse x della finestra sinistra
const int Utilities::LARGHEZZA_FINESTRAsx = ((LARGHEZZA_DISPLAY/2) - (LARGHEZZA_MAPPA/2) - (2* MARGINE_MAPPA));
const int Utilities::POSIZIONE_PARTENZA_FINESTRAsx_X = MARGINE_MAPPA;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAsx_Y = POSIZIONE_PARTENZA_MAPPA_Y-MARGINE_MAPPA;

const int Utilities::ALTEZZA_FINESTRAdx = ALTEZZA_MAPPA + (2*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_FINESTRAdx = ((LARGHEZZA_DISPLAY/2) - (LARGHEZZA_MAPPA/2) - (2* MARGINE_MAPPA));
const int Utilities::POSIZIONE_PARTENZA_FINESTRAdx_X = POSIZIONE_PARTENZA_MAPPA_X+LARGHEZZA_MAPPA+ MARGINE_MAPPA;
const int Utilities::POSIZIONE_PARTENZA_FINESTRAdx_Y = POSIZIONE_PARTENZA_MAPPA_Y-MARGINE_MAPPA;

const int Utilities::ALTEZZA_CONSOLE = (ALTEZZA_DISPLAY)-(ALTEZZA_MAPPA+POSIZIONE_PARTENZA_MAPPA_Y)-(6*MARGINE_MAPPA);
const int Utilities::LARGHEZZA_CONSOLE = (LARGHEZZA_MAPPA + (4*MARGINE_MAPPA))+(LARGHEZZA_FINESTRAsx)+(LARGHEZZA_FINESTRAdx);
const int Utilities::POSIZIONE_PARTENZA_CONSOLE_X = POSIZIONE_PARTENZA_MAPPA_X-LARGHEZZA_FINESTRAsx-(2*MARGINE_MAPPA);
const int Utilities::POSIZIONE_PARTENZA_CONSOLE_Y = POSIZIONE_PARTENZA_MAPPA_Y+ALTEZZA_MAPPA+(2*MARGINE_MAPPA);


static int posizione_partenza_personaggio_x=0;
static int posizione_partenza_personaggio_y=0;
// --------------------------------------------

Vector2<int> lista_posizioni[20];
int lunghezza_array_posizioni = -1;
const int min_value = 0;
const int max_value = Utilities::NUMERO_CASELLE_ASSE_X-1;
int cont=0;

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
    //std::cout<<"nessun duplicato trovato \n";
    return false;
}


void Utilities::azzeraPosizioni()
{
    for(int i=0; i<lunghezza_array_posizioni; i++)
    {
        lista_posizioni[i]={0,0};
    }
    lunghezza_array_posizioni= (-1);
    cont=0;
}

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

bool Utilities::controllaElementoGrafico(ListaTorre &lista_torre, int stanza, int x, int y)
{
    if(lista_torre.torre->piano.arr_mappe[stanza - 1].restituisci_valore(y, x) == 9)
    {
        //std::cout << "nella cella [" << x << ", " << y << "] ci sta un "
                  //<< lista_torre.torre->piano.arr_mappe[stanza - 1].restituisci_valore(y - 1, x - 1) << "\n";
        return true;
    }
    return false;
}


Vector2<int> Utilities::generaPosizioneRandom(ListaTorre &lista_torre, int stanza, int eroe_x, int eroe_y)
{
    int rand_x = rand()%(max_value-min_value + 1) + min_value;
    int rand_y = rand()%(max_value-min_value + 1) + min_value;
    //std::cout<<"posizione casuale generata: ("<<rand_x<<", "<<rand_y<<") \n";
    Vector2<int> posizione_corrente = {rand_x, rand_y};
    // controllo che non sia già stata creata una posizione uguale
    if(controlloDuplicato(posizione_corrente))
        generaPosizioneRandom(lista_torre, stanza, eroe_x, eroe_y);
    else
    {
        // controllo che in questa posizione non ci sia un muro, una porta o un personaggio
        if(controllaElementoGrafico(lista_torre, stanza, rand_x, rand_y))
        {
            if ((rand_x > 0) && (rand_y > 0) && (rand_x+1!=eroe_x) && (rand_y+1!=eroe_y))
            {
                cont++;
                // incremento la lunghezza dell'array
                lunghezza_array_posizioni += 1;
                // aggiungo la nuova posizione all'array di posizioni create
                lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
                //std::cout <<"["<<cont<<"] - "<< "sposto il nemico nella cella [" << posizione_corrente.x << ", " << posizione_corrente.y << "] \n";
                //std::cout<<"ok \n";
                return posizione_corrente;
            }
            else
                generaPosizioneRandom(lista_torre, stanza, eroe_x, eroe_y);
        }
        else
            generaPosizioneRandom(lista_torre, stanza, eroe_x, eroe_y);
    }
    return {0,0};
}

Vector2<int> Utilities::generaPosizioneRandom()
{
    azzeraPosizioni();
    int rand_x = rand()%(max_value-min_value + 1) + min_value;
    int rand_y = rand()%(max_value-min_value + 1) + min_value;
    Vector2<int> posizione_corrente = {rand_x, rand_y};
    // controllo che non sia già stata creata una posizione uguale
    if(controlloDuplicato(posizione_corrente))
        generaPosizioneRandom();
    else
    {
        if ((rand_x != 0) && (rand_y != 0))
        {
            // incremento la lunghezza dell'array
            lunghezza_array_posizioni += 1;
            // aggiungo la nuova posizione all'array di posizioni create
            lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
            //std::cout<<"["<<lunghezza_array_posizioni<<"] - "<<"posizione casuale generata: ("<<posizione_corrente.x<<", "<<posizione_corrente.y<<") \n";
            return posizione_corrente;
        } else
            generaPosizioneRandom();
    }
    return {0,0};
}

Vector2<int> Utilities::generaPosizioneRandom(int eroe_x, int eroe_y)
{
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
    return {0,0};
}

bool Utilities::controlloPosizioneConsentita(Vector2<int> array_posizioni_consentite[], int length, Vector2<int> posizione_generata)
{
    for(int i=0; i<length; i++)
    {
        //std::cout<<i<<"\t controllo che la posizione corrente --> ["<<array_posizioni_consentite[i].x<<", "<<array_posizioni_consentite[i].y<<"] \n";
        //std::cout<<i<<"\t sia uguale a  --> ["<<posizione_generata.x+1<<", "<<posizione_generata.y+1<<"] \n";
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

void Utilities::generaPosizioneRandom(Vector2<int> array_posizioni_consentite[], int lunghezza_arr_pos, int stanza, Vector2<int> &posizione_generata)
{
    rand_x = rand()%(max_value-min_value + 1) + min_value;
    rand_y = rand()%(max_value-min_value + 1) + min_value;
    posizione_corrente.x =rand_x;   posizione_corrente.y=rand_y;
    // controllo che non sia già stata creata una posizione uguale
    //std::cout<<"--- genero una nuova posizione e controllo se va bene --> ["<<rand_x+1<<", "<<rand_y+1<<"] \n";
    if(!controlloDuplicato(posizione_corrente) /*&& (rand_x<=NUMERO_CASELLE_ASSE_X) && (rand_y<=NUMERO_CASELLE_ASSE_X)*/)
    {
        if(controlloPosizioneConsentita(array_posizioni_consentite, lunghezza_arr_pos, posizione_corrente)) {
            //std::cout << "la posizione va bene \n";
            // incremento la lunghezza dell'array
            lunghezza_array_posizioni += 1;
            // aggiungo la nuova posizione all'array di posizioni create
            lista_posizioni[lunghezza_array_posizioni] = posizione_corrente;
            //std::cout<<"1 - posizione casuale generata: ("<<posizione_corrente.x+1<<", "<<posizione_corrente.y+1<<") \n";
            posizione_generata=posizione_corrente;
            //return posizione_corrente;
        }
        else
        {
            //std::cout << "la posizione non è nell'array di posizioni consentite \n";
            generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, stanza, posizione_generata);
        }
    }
    else
    {
        //std::cout<<"la posizione è duplicata \n";
        // controllo che in questa posizione non ci sia un muro, una porta o un personaggio
        // if(funzione_porc_mi_dà_ok)
        generaPosizioneRandom(array_posizioni_consentite, lunghezza_arr_pos, stanza, posizione_generata);
    }
    //return {0,0};
}

std::string Utilities::convertInt(int number)
{
    return std::to_string(number);
}