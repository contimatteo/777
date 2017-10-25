//
// Created by Matteo Conti on 21/08/17.
//

#include "GestoreGrafica.hpp"

// costruttore
GestoreGrafica::GestoreGrafica(int stack)
{
    dimensione_mappa=0;
    // aggiungo un elemento di prova
    Texture immagine1;
    immagine1.loadFromFile("../risorse/immagini/white.png");
    Sprite sprite1 = Sprite();
    sprite1.setTexture(immagine1);
    sprite1.setPosition(800, 200);
    mappa.push_back(sprite1);
    dimensione_mappa++;
    // aggiungo un elemento di prova
    Texture immagine2;
    immagine2.loadFromFile("../risorse/immagini/green.png");
    Sprite sprite2 = Sprite();
    sprite2.setTexture(immagine2);
    sprite2.setPosition(200, 800);
    mappa.push_back(sprite2);
    dimensione_mappa++;
}

void GestoreGrafica::aggiungiElemento(Sprite oggetto)
{
    mappa.push_back(oggetto);
    dimensione_mappa++;
}

std::vector<Sprite> GestoreGrafica::getMappa()
{
    return mappa;
}

void GestoreGrafica::disegnaMappa(RenderWindow &window)
{
    ////// draw  ///////
    window.clear();
    // disegno la mappa corrente aggiornata
    for (Sprite oggetto_grafico : mappa)
    {
        window.draw(oggetto_grafico);
    }
    window.display();
}