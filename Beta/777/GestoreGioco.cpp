//
// Created by Matteo Conti on 25/06/17.
//

#include<iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include "GestoreGioco.hpp"
#include "GestoreGrafica.hpp"
#include "Pet.hpp"
#include "ElementoGrafico.hpp"

//********************************************************************************************
//********************************************************************************************

RectangleShape rettangoloSceltaa;
int size=10;
int W = 150;
int H = 150;

//********************************************************************************************
//********************************************************************************************

void GestoreGioco::creaGioco()
{
    GestoreGrafica Grafica = GestoreGrafica(0);

    //creo un pet di prova
    /*Pet pet1("white");
    //pet.setX(25); pet.setY(25);
    pet1.setImmagine("../risorse/immagini/white.png");
    //pet.disegnaElemento(Gioco, pet.grafica);

    for (int i=0; i<W; i+=2)
        for (int j=0; j<H; j+=2)
        {
            pet1.grafica.setPosition(i*size,j*size);
            //pet.disegnaElemento(Gioco, pet.grafica);
            Grafica.aggiungiElemento(pet1.grafica);
        }
    Grafica.disegnaMappa(Gioco);*/
    Pet pet2("red");
    // adds
    //pet2.prova1(Gioco);
    // --
    pet2.setX(50); pet2.setY(50);
    pet2.setImmagine("../risorse/immagini/red.png");
    pet2.disegnaElemento(Gioco, pet2.grafica);
    //Grafica.disegnaMappa(Gioco);
    Pet pet3("green");
    pet3.setImmagine("../risorse/immagini/green.png");
    pet3.setX(200); pet3.setY(300);
    pet3.disegnaElemento(Gioco, pet3.grafica);

    int contatoreSpostamentoDiProva = 25;
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
            try
            {
                // passo la scelta al gestore delegato
                if (evento.type == sf::Event::EventType::KeyPressed)
                {
                    if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Right))
                    {
                        // FUNZIONE MUOVITI
                        contatoreSpostamentoDiProva+=25;
                        pet2.setX(contatoreSpostamentoDiProva);
                        pet2.setY(contatoreSpostamentoDiProva);
                        //std::cout<<"new position --> [" << pet.getX() << ", " << pet.getY() << "] \n";
                        //pet2.disegnaElemento(Gioco, Grafica.getMappa(), pet2.grafica);
                        //pet2.prova1(Gioco);
                        Gioco.clear();
                        Gioco.display();
                        Pet pet1("white");
                        //pet.setX(25); pet.setY(25);
                        pet1.setImmagine("../risorse/immagini/white.png");
                        //pet.disegnaElemento(Gioco, pet.grafica);

                        for (int i=0; i<W; i+=2)
                            for (int j=0; j<H; j+=2)
                            {
                                pet1.grafica.setPosition(i*size,j*size);
                                //pet1.prova2(Gioco, pet1.grafica);
                                Gioco.display();
                                ////// draw  ///////
                                Gioco.draw(pet1.grafica);
                                Gioco.display();
                                //Grafica.aggiungiElemento(pet1.grafica);
                            }
                        //pet3.prova2(Gioco, pet3.grafica);
                        pet2.prova2(Gioco, pet2.grafica);
                    }
                }

            }
            catch(int ex)
            {
                std::cout<<ex;
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
