
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Audio.hpp>
#include "ElementoGrafico.hpp"
#include "Utilities.hpp"
#include "Personaggio.hpp"
using namespace sf;

// ----------------------------
static Utilities util;

// ----------------------------

void disegnaMappa(RenderWindow &Gioco)
{
    sf::Texture texture_mappa;
    texture_mappa.loadFromFile("../risorse/immagini/white.png");
    sf::Sprite immagine_mappa(texture_mappa);
    for (int i=0; i<util.NUMERO_CASELLE_ASSE_X; i++)
        for (int j=0; j<util.NUMERO_CASELLE_ASSE_Y; j++)
        { immagine_mappa.setPosition(i*util.DIMENSIONE_CELLE,j*util.DIMENSIONE_CELLE);  Gioco.draw(immagine_mappa); }
}


void disegnaNemici()
{
   // ListaNemici nemici(0);
}

void disegnaElementiExtra()
{
}

void disegnaElementiGrafici()
{
    disegnaNemici();
    disegnaElementiExtra();

}

// ----------------------------

int main()
{
    bool muovi_personaggio=false;
    sf::RenderWindow Gioco(sf::VideoMode(util.LARGHEZZA_FINESTRA_GIOCO, util.ALTEZZA_FINESTRA_GIOCO), "777 - Game");
    Gioco.setKeyRepeatEnabled(true);

    // Istanzio L' eroe
    Personaggio eroe(1);

    // eseguo il gioco finchè la finestra rimane aperta
    while (Gioco.isOpen())
    {
        // sincronizzo il frame-rate del gioco con quello dello schermo
        Gioco.setVerticalSyncEnabled(true);
        // Process events
        sf::Event event;
        while (Gioco.pollEvent(event))
        {
            // controllo che la finestra del gioco non venga ridimensionata
            if (event.type == sf::Event::Resized) {
                const Vector2u dimensioni = Vector2u(1200, 1200);
                Gioco.setSize(dimensioni);
            }
            // controllo quando la finestra viene chiusa --> chiudo il gioco
            if (event.type == sf::Event::Closed)
                Gioco.close();
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))||(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)))
        {
            muovi_personaggio = true;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && muovi_personaggio)
        {
            // freccia Sinistra premuta: muovi il personaggio
            eroe.setPosizione(-util.DIMENSIONE_CELLE, 0);
            eroe.muovi();
            muovi_personaggio = false;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && muovi_personaggio) {
            // freccia Destra premuta: muovi il personaggio
            eroe.setPosizione(util.DIMENSIONE_CELLE, 0);
            eroe.muovi();
            muovi_personaggio = false;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && muovi_personaggio) {
            // freccia SU premuta: muovi il personaggio
            eroe.setPosizione(0, -util.DIMENSIONE_CELLE);
            eroe.muovi();
            muovi_personaggio = false;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && muovi_personaggio) {
            // freccia GIU premuta: muovi il personaggio
            eroe.setPosizione(0, util.DIMENSIONE_CELLE);
            eroe.muovi();
            muovi_personaggio = false;
        }

        // Clear screen
        Gioco.clear();
        // disegno la mappa
        disegnaMappa(Gioco);
        // disegno l'erore
        Gioco.draw(eroe.grafica);
        // Aggiorno il Gioco con le modifiche
        Gioco.display();
    }

    // programma terminato correttamente
    return EXIT_SUCCESS;
}

//-----------------------------