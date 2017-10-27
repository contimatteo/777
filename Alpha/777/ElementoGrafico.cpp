//
// Created by Matteo Conti on 10/10/17.
//

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "ElementoGrafico.hpp"
using namespace sf;

void ElementoGrafico::muovi()
{
    grafica.move(spostamento_x, spostamento_y);
}

void ElementoGrafico::setPosizione(int x, int y)
{
    int mossa_asse_x=util.SPAZIO_CELLE * x;
    int mossa_asse_y=util.SPAZIO_CELLE * y;
    if((posX+mossa_asse_x<util.POSIZIONE_PARTENZA_MAPPA_X+util.LARGHEZZA_MAPPA)&&(posX+mossa_asse_x>=util.POSIZIONE_PARTENZA_MAPPA_X))
    {
        pos_cella_x+=x;
        posX += util.SPAZIO_CELLE * x;
        spostamento_x = util.SPAZIO_CELLE * x;
    }
    else
    {
        // spostamento fuori mappa non consentito
        spostamento_x=0;
    }
    if((posY+mossa_asse_y<util.POSIZIONE_PARTENZA_MAPPA_Y+util.ALTEZZA_MAPPA)&&(posY+mossa_asse_y>=util.POSIZIONE_PARTENZA_MAPPA_Y))
    {
        pos_cella_y+=y;
        posY += util.SPAZIO_CELLE * y;
        spostamento_y = util.SPAZIO_CELLE * y;
    }
    else
    {
        // spostamento fuori mappa non consentito
        spostamento_y=0;
    }
}


ElementoGrafico::ElementoGrafico(int tipo_personaggio)
{
    // inizializzo variabili posizioni
    posX_iniziale=(util.POSIZIONE_PARTENZA_MAPPA_X);
    posY_iniziale=(util.POSIZIONE_PARTENZA_MAPPA_Y);
    posX=posX_iniziale; posY=posY_iniziale;
    pos_cella_x=1;  pos_cella_y=1;

    //Texture texture;
    switch(tipo_personaggio)
    {
        // eroe
        case 1:
        {
            texture.loadFromFile("../risorse/immagini/Personaggio-1.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
            break;
        }
        // pet
        case 2:
        {
            texture.loadFromFile("../risorse/immagini/red.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
            break;
        }
        // nemico
        case 3:
        {
            texture.loadFromFile("../risorse/immagini/Nemico-1.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
            break;
        }
        // altri
        case 4:
        {
            texture.loadFromFile("../risorse/immagini/angolo-alto-destra.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
            break;
        }
        // mura mappa
        case 10:
        {
            texture.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
            break;
        }
        // pavimento mappa
        case 11:
        {
            texture.loadFromFile("../risorse/immagini/grass.png", sf::IntRect(util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
            break;
        }
        // default
        default:
        {
            // mura mappa (caso di default)
            ElementoGrafico(11);
        }

    }
    // imposto la sprite selezionata
    grafica.setTexture(texture);
    // imposto la sua posizione
    grafica.setPosition(posX, posY);
}