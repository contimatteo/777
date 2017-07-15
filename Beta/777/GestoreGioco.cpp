//
// Created by Matteo Conti on 25/06/17.
//

#include<iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "GestoreGioco.hpp"
#include "Pet.hpp"
#include "ElementoGrafico.hpp"

//********************************************************************************************
//********************************************************************************************

RectangleShape rettangoloSceltaa;
int size=10;
int W = 50;
int H = 50;

//********************************************************************************************
//********************************************************************************************

void GestoreGioco::creaGioco()
{
    // elemento di prova
    /*rettangoloSceltaa.setSize(Vector2f(400, 100));
    rettangoloSceltaa.setPosition(10, 10);
    rettangoloSceltaa.setFillColor(Color::Red);
    ElementoGrafico::disegnaElemento(Gioco, rettangoloSceltaa);*/

    //creo un pet di prova
    Pet pet("red");
    pet.setX(25); pet.setY(25);
    Texture t1;
    t1.loadFromFile("../risorse/immagini/green.png");
    Texture t2;
    t2.loadFromFile("../risorse/immagini/red.png");
    pet.grafica.setTexture(t1);
    pet.disegnaElemento(Gioco, pet.grafica);

    for (int i=0; i<W; i+=2)
        for (int j=0; j<H; j+=2)
        { pet.grafica.setPosition(i*size,j*size);  pet.disegnaElemento(Gioco, pet.grafica); }

    pet.grafica.setTexture(t2);
    pet.grafica.setPosition(20, 20);
    pet.disegnaElemento(Gioco, pet.grafica);

    // eseguo il gioco finchè la finestra rimane aperta
    while (Gioco.isOpen()) {
        // sincronizzo il frame-rate del gioco con quello dello schermo
        Gioco.setVerticalSyncEnabled(true);
        // catturo tutti gli eventi verificatosi durante l'esecuzione del gioco fino all'ultimo loop
        Event evento;
        while (Gioco.pollEvent(evento)) {
            // controllo che la finestra del gioco non venga ridimensionata
            if (evento.type == sf::Event::Resized) {
                const Vector2u dimensioni = Vector2u(1200, 1200);
                Gioco.setSize(dimensioni);
            }
            // controllo quando la finestra viene chiusa --> chiudo il gioco
            if (Event::Closed == evento.type) {
                Gioco.close();
                MenuInizialeGioco->setVisible(true);
            }
        }
    }
}

// cosruttore
GestoreGioco::GestoreGioco(int scelta, RenderWindow &menu)
{
    // copio l'istanza del menu iniziale nella variabile globale Menu
    MenuInizialeGioco=&menu;

    switch(scelta)
    {
        // GIOCA
        case 1:
            Gioco.create(VideoMode(1200, 1200), "777 - GIOCA");
            Gioco.setKeyRepeatEnabled(true);
            rettangoloSceltaa.setPosition(10, 10);
            creaGioco();
            std::cout<<"GIOCA \n";
            break;

        // TUTORIAL
        case 2:
            std::cout<<"TUTORIAL \n";
            Tutorial.create(VideoMode(1200, 1200), "777 - TUTORIAL");
            Tutorial.setKeyRepeatEnabled(true);
            Tutorial.close();
            break;

        // GIOCA
        case 3:
            std::cout<<"INFO \n";
            Info.create(VideoMode(1200, 1200), "777 - INFO");
            Info.setKeyRepeatEnabled(true);
            Info.close();
            break;


        // scelta non inesistente
        default:
            break;
    }
}

//********************************************************************************************
