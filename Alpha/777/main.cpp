
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ElementoGrafico.hpp"
#include "Personaggio.hpp"
#include "Grafica.hpp"
using namespace sf;

// ----------------------------
static Utilities util;
int piano=1;
int stanza=1;

// ----------------------------

void muoviEroe(RenderWindow &Gioco, Personaggio &eroe, int x, int y, bool &muovi_personaggio)
{
    //controllo che la casella sia libera
    // if(funzione porc da ok)
    // {
         eroe.setPosizione(x, y);
         eroe.muovi();
         muovi_personaggio = false;
    // }
}


void disegnaMappa(RenderWindow &Gioco, Grafica &grafica)
{
    grafica.disegnaMappa(Gioco);
}

void disegnaFinestraSinistra(RenderWindow &Gioco)
{
    // disegno finestra di sx
    sf::RectangleShape finestra(sf::Vector2f(util.LARGHEZZA_FINESTRAsx, util.ALTEZZA_FINESTRAsx));
    finestra.setPosition(util.POSIZIONE_PARTENZA_FINESTRAsx_X, util.POSIZIONE_PARTENZA_FINESTRAsx_Y);
    finestra.setFillColor(util.COLORE_SFONDO);
    finestra.setOutlineColor(sf::Color::White);
    finestra.setOutlineThickness(1.5);
    Gioco.draw(finestra);

}

void disegnaFinestraDestra(RenderWindow &Gioco)
{
    // disegno finestra di dx
    sf::RectangleShape finestra(sf::Vector2f(util.LARGHEZZA_FINESTRAdx, util.ALTEZZA_FINESTRAdx));
    finestra.setPosition(util.POSIZIONE_PARTENZA_FINESTRAdx_X, util.POSIZIONE_PARTENZA_FINESTRAdx_Y);
    finestra.setFillColor(util.COLORE_SFONDO);
    finestra.setOutlineColor(sf::Color::White);
    finestra.setOutlineThickness(1.5);
    Gioco.draw(finestra);
}

void disegnaConsole(RenderWindow &Gioco)
{
    // disegno la console
    sf::RectangleShape console(sf::Vector2f(util.LARGHEZZA_CONSOLE, util.ALTEZZA_CONSOLE));
    console.setPosition(util.POSIZIONE_PARTENZA_CONSOLE_X, util.POSIZIONE_PARTENZA_CONSOLE_Y);
    console.setFillColor(util.COLORE_SFONDO);
    console.setOutlineColor(sf::Color::White);
    console.setOutlineThickness(1.5);
    //Gioco.draw(console);
}

void disegnaEroe(RenderWindow &Gioco, Personaggio &eroe)
{
    Gioco.draw(eroe.grafica);
}



void disegnaElementiExtra(RenderWindow &Gioco)
{
}

void disegnaElementiGrafici(RenderWindow &Gioco, Personaggio &eroe, ListaNemici &nemici)
{
    disegnaFinestraSinistra(Gioco);
    disegnaFinestraDestra(Gioco);
    disegnaConsole(Gioco);
    disegnaEroe(Gioco, eroe);
    nemici.disegnaNemici(Gioco);
    //disegnaElementiExtra(Gioco);
}

void azioni_nemico(RenderWindow &Gioco, Personaggio &eroe, ListaNemici &nemici)
{
    // controllo se togliere vita al personaggio
    nemici.nemicoAttaccaPersonaggio(eroe);
    // muovo i nemici
    nemici.spostaNemici(eroe, piano, stanza);
}

// ----------------------------

int main()
{
    srand(static_cast <unsigned int> (time(0)));
    bool muovi_personaggio=false, eroe_attacca=false;
    sf::RenderWindow Gioco(sf::VideoMode(util.LARGHEZZA_DISPLAY, util.ALTEZZA_DISPLAY), "777 - Game");
    Gioco.setKeyRepeatEnabled(true);

    // Instanzio la mappa
    Grafica grafica(0);
    // Istanzio L' eroe
    Personaggio eroe(1);
    // Instanzio i nemici
    ListaNemici nemici(2);

    // eseguo il gioco finchè la finestra rimane aperta
    while (Gioco.isOpen())
    {
        // sincronizzo il frame-rate del gioco con quello dello schermo
        Gioco.setVerticalSyncEnabled(true);
        // Process events
        sf::Event event;
        /*
        sf::Music music;
        if (!music.openFromFile("../risorse/audio/main-song.ogg"))
            return -1; // error
        music.play();
         */
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
            muoviEroe(Gioco, eroe, -1, 0, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && muovi_personaggio) {
            // freccia Destra premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, 1, 0, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && muovi_personaggio) {
            // freccia SU premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, 0, -1, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && muovi_personaggio) {
            // freccia GIU premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, 0, 1, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici);
        }
        // attacco eroe
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))||(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)))
        {
            eroe_attacca=true;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))&&(eroe_attacca))
        {
            eroe.personaggioAttaccaNemico(nemici);
            eroe_attacca=false;
        }
        // Clear screen
        Gioco.clear(util.COLORE_SFONDO);
        // disegno la mappa
        disegnaMappa(Gioco, grafica);
        // disegno l'erore
        disegnaElementiGrafici(Gioco, eroe, nemici);
        // Aggiorno il Gioco con le modifiche
        Gioco.display();

    }

    // programma terminato correttamente
    return EXIT_SUCCESS;
}

//-----------------------------