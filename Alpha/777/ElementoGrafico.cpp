//
// Created by Matteo Conti on 10/10/17.
//

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "ElementoGrafico.hpp"
using namespace sf;

void ElementoGrafico::muovi(int x, int y)
{
    if(abs(x)<util.LARGHEZZA_FINESTRA_GIOCO)
    {
        posX = x;
        if (abs(y) < util.ALTEZZA_FINESTRA_GIOCO) {
            posY = y;
            grafica.move(x, y);
        }
    }
}

void ElementoGrafico::muovi()
{
    grafica.move(posX, posY);
}

void ElementoGrafico::setPosizione(int x, int y)
{
    if(abs(x)<util.LARGHEZZA_FINESTRA_GIOCO)
    posX=x;
    if(abs(y)<util.ALTEZZA_FINESTRA_GIOCO)
    posY=y;
}


ElementoGrafico::ElementoGrafico(int tipo_personaggio)
{
    // inizializzo variabili posizioni
    posX=0; posY=0;

    //Texture texture;
    switch(tipo_personaggio)
    {
        // eroe
        case 1:
        {
            texture.loadFromFile("../risorse/immagini/red.png");
            break;
        }
        // pet
        case 2:
        {
            texture.loadFromFile("../risorse/immagini/red.png");
            break;
        }
        // nemico
        case 3:
        {
            texture.loadFromFile("../risorse/immagini/red.png");
            break;
        }
        // altri
        case 4:
        {
            texture.loadFromFile("../risorse/immagini/red.png");
            break;
        }
        // mura mappa
        case 10:
        {
            texture.loadFromFile("../risorse/immagini/white.png");
            break;
        }
        // pavimento mappa
        case 11:
        {
            texture.loadFromFile("../risorse/immagini/white.png");
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
}