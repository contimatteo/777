
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ElementoGrafico.hpp"
#include "Personaggio.hpp"
#include "Grafica.hpp"
#include "MenuIniziale.hpp"
#include "ListaTorre.hpp"
using namespace sf;

// ----------------------------
static Utilities util;
int piano=1;
int stanza=1;

// ----------------------------

void muoviEroe(RenderWindow &Gioco, Personaggio &eroe, int x, int y, bool &muovi_personaggio, ListaTorre &lista_torre)
{
    //controllo che la casella sia libera
    //if(lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(x,y)==9)
    //{
        eroe.setPosizione(x, y);
        eroe.muovi();
        muovi_personaggio = false;
    /*}
    else
        std::cout<<"merda \n";*/
}


void disegnaMappa(RenderWindow &Gioco, Grafica &grafica, ListaTorre &lista_torre)
{
    grafica.disegnaMappa(Gioco, lista_torre, stanza);
}

void disegnaFinestraSinistra(RenderWindow &Gioco, Grafica &grafica, Personaggio &eroe)
{
    // disegno finestra di sx
    sf::RectangleShape finestra(sf::Vector2f(util.LARGHEZZA_FINESTRAsx, util.ALTEZZA_FINESTRAsx));
    finestra.setPosition(util.POSIZIONE_PARTENZA_FINESTRAsx_X, util.POSIZIONE_PARTENZA_FINESTRAsx_Y);
    finestra.setFillColor(sf::Color::Green);
    finestra.setOutlineColor(sf::Color::White);
    finestra.setOutlineThickness(1.5);
    Gioco.draw(finestra);
    grafica.creaTestiFinestraSinistra(Gioco, eroe);
    Gioco.draw(grafica.status_eroe);
    Gioco.draw(grafica.attacco_eroe);
    Gioco.draw(grafica.vita_eroe);
    Gioco.draw(grafica.gittata_eroe);
}

void disegnaFinestraDestra(RenderWindow &Gioco, Grafica &grafica, Personaggio &eroe)
{
    // disegno finestra di dx
    sf::RectangleShape finestra(sf::Vector2f(util.LARGHEZZA_FINESTRAdx, util.ALTEZZA_FINESTRAdx));
    finestra.setPosition(util.POSIZIONE_PARTENZA_FINESTRAdx_X, util.POSIZIONE_PARTENZA_FINESTRAdx_Y);
    finestra.setFillColor(sf::Color::Magenta);
    finestra.setOutlineColor(sf::Color::White);
    finestra.setOutlineThickness(1.5);
    Gioco.draw(finestra);
}

void disegnaEroe(RenderWindow &Gioco, Personaggio &eroe)
{
    Gioco.draw(eroe.grafica);
}


void disegnaElementiGrafici(RenderWindow &Gioco, Personaggio &eroe, ListaNemici &nemici, Grafica &grafica)
{
    disegnaFinestraSinistra(Gioco, grafica, eroe);
    disegnaFinestraDestra(Gioco, grafica, eroe);
    disegnaEroe(Gioco, eroe);
    nemici.disegnaNemici(Gioco);
}

void azioni_nemico(RenderWindow &Gioco, Personaggio &eroe, ListaNemici &nemici, ListaTorre &lista_torre)
{
    // controllo se togliere vita al personaggio
    nemici.nemicoAttaccaPersonaggio(eroe);
    // muovo i nemici
    util.azzeraPosizioni();
    nemici.spostaNemici(eroe, lista_torre, piano, stanza);
}

// ----------------------------

int main()
{
    srand(static_cast <unsigned int> (time(0)));
    bool muovi_personaggio=false, eroe_attacca=false;
    sf::RenderWindow Gioco(sf::VideoMode((unsigned int)util.LARGHEZZA_DISPLAY, (unsigned int)util.ALTEZZA_DISPLAY), "777 - Game");
    Gioco.setKeyRepeatEnabled(false);
    Gioco.setVisible(false);

    // Instanzio la lista torre
    ListaTorre lista_torre;
    // Instanzio il Menu Iniziale
    MenuIniziale menu(Gioco);
    // Instanzio la mappa
    Grafica grafica(0);
    // Istanzio L' eroe
    Personaggio eroe(1, lista_torre, stanza);
    // Instanzio i nemici
    ListaNemici nemici(lista_torre, stanza);
    // Instazio la musica
    Music music;
    music.openFromFile("../risorse/audio/main-song.ogg");
    music.setVolume(50);
    music.setLoop(true);
    //music.play();

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
                const Vector2u dimensioni = Vector2u(util.LARGHEZZA_DISPLAY, util.ALTEZZA_DISPLAY);
                Gioco.setSize(dimensioni);
            }
            // controllo quando la finestra viene chiusa --> chiudo il gioco
            if (event.type == sf::Event::Closed)
            {
                Gioco.close();
            }
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))||(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)))
        {
            muovi_personaggio = true;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && muovi_personaggio)
        {
            // freccia Sinistra premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, -1, 0, muovi_personaggio, lista_torre);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && muovi_personaggio) {
            // freccia Destra premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, 1, 0, muovi_personaggio, lista_torre);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && muovi_personaggio) {
            // freccia SU premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, 0, -1, muovi_personaggio, lista_torre);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && muovi_personaggio) {
            // freccia GIU premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, 0, 1, muovi_personaggio, lista_torre);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre);
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
        disegnaMappa(Gioco, grafica, lista_torre);
        // disegno l'erore
        disegnaElementiGrafici(Gioco, eroe, nemici, grafica);
        // Aggiorno il Gioco con le modifiche
        Gioco.display();
    }

    // programma terminato correttamente
    return EXIT_SUCCESS;
}

//-----------------------------