//
// Created by Matteo Conti on 23/06/17.
//

#include <iostream>
#include "MenuIniziale.hpp"
#include "GestoreGioco.hpp"
using namespace sf;

//********************************************************************************************
//********************************************************************************************

// scelta menu

//********************************************************************************************
//********************************************************************************************
// METODI


void MenuIniziale::creaGraficaMenuIniziale()
{
    // contenitore menu scelta iniziale
    contenitore.setSize(Vector2f(1150, 1150));
    contenitore.setOutlineColor(Color::Yellow);
    contenitore.setOutlineThickness(5);
    contenitore.setPosition(25, 25);
    contenitore.setFillColor(Color(51, 51, 51));

    // contenitore rettangolo scelta 1
    rettangoloScelta1.setSize(Vector2f(400, 100));
    rettangoloScelta1.setPosition(400, 200);
    rettangoloScelta1.setFillColor(Color::Yellow);
    // contenitore rettangolo scelta 2
    rettangoloScelta2.setSize(Vector2f(400, 100));
    rettangoloScelta2.setPosition(400, 400);
    rettangoloScelta2.setFillColor(Color::Yellow);

    // contenitore rettangolo scelta 3
    rettangoloScelta3.setSize(Vector2f(400, 100));
    rettangoloScelta3.setPosition(400, 600);
    rettangoloScelta3.setFillColor(Color::Yellow);
    // contenitore rettangolo scelta 2
    rettangoloScelta4.setSize(Vector2f(400, 100));
    rettangoloScelta4.setPosition(400, 800);
    rettangoloScelta4.setFillColor(Color::Yellow);

    // 1: GIOCA
    rettangolo1Testo.setString("1: GIOCA");
    rettangolo1Testo.setFont(font);
    rettangolo1Testo.setCharacterSize(30);
    rettangolo1Testo.setFillColor(sf::Color::Black);
    rettangolo1Testo.setPosition(535, 232);

    // 2: TUTORIAL
    rettangolo2Testo.setString("2: TUTORIAL");
    rettangolo2Testo.setFont(font);
    rettangolo2Testo.setCharacterSize(30);
    rettangolo2Testo.setFillColor(sf::Color::Black);
    rettangolo2Testo.setPosition(515, 432);

    // 3: INFO
    rettangolo3Testo.setString("3: INFO");
    rettangolo3Testo.setFont(font);
    rettangolo3Testo.setCharacterSize(30);
    rettangolo3Testo.setFillColor(sf::Color::Black);
    rettangolo3Testo.setPosition(555, 632);

    // 4: ESCI
    rettangolo4Testo.setString("4: ESCI");
    rettangolo4Testo.setFont(font);
    rettangolo4Testo.setCharacterSize(30);
    rettangolo4Testo.setFillColor(sf::Color::Black);
    rettangolo4Testo.setPosition(555, 832);

}

//********************************************************************************************
//********************************************************************************************

int MenuIniziale::scegliOpzione()
{
    // GIOCA
    if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1))
        return 1;

    // TUTORIAL
    if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2))
        return 2;

    // INFO
    if (Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3))
        return 3;

    // INFO
    if (Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4))
        return 4;

    return 0;
}

//********************************************************************************************
//********************************************************************************************

void MenuIniziale::visualizzaMenu()
{
    creaGraficaMenuIniziale();

    if (!font.loadFromFile("../risorse/OpenSans.ttf"))
    {
        std::cout<<"font non trovato";
    }

    ContenitoreGioco.draw(contenitore);
    ContenitoreGioco.draw(rettangoloScelta1);
    ContenitoreGioco.draw(rettangoloScelta2);
    ContenitoreGioco.draw(rettangoloScelta3);
    ContenitoreGioco.draw(rettangoloScelta4);

    ContenitoreGioco.draw(rettangolo1Testo);
    ContenitoreGioco.draw(rettangolo2Testo);
    ContenitoreGioco.draw(rettangolo3Testo);
    ContenitoreGioco.draw(rettangolo4Testo);

    ContenitoreGioco.display();

    // eseguo il gioco finchè la finestra rimane aperta
    while (ContenitoreGioco.isOpen()) {
        // sincronizzo il frame-rate del gioco con quello dello schermo
        ContenitoreGioco.setVerticalSyncEnabled(true);
        // catturo tutti gli eventi verificatosi durante l'esecuzione del gioco fino all'ultimo loop
        Event evento;
        while (ContenitoreGioco.pollEvent(evento)) {
            // controllo che la finestra del gioco non venga ridimensionata
            if (evento.type == sf::Event::Resized) {
                const Vector2u dimensioni = Vector2u(1200, 1200);
                ContenitoreGioco.setSize(dimensioni);
            }
            // controllo quando la finestra viene chiusa --> chiudo il gioco
            if (Event::Closed == evento.type)
                ContenitoreGioco.close();

            try {
                // passo la scelta al gestore delegato
                if (evento.type == sf::Event::EventType::KeyPressed) {
                    scelta = (this->scegliOpzione());
                    // se la scelta è 4 chiudo il menu altrimenti delego al gestore del gioco
                    // le operazioni da fare in base alla scelta fatta
                    if (scelta == 4)
                        ContenitoreGioco.close();
                    else {
                        if (scelta == 0)
                            std::cout << "scelta non trovata \n";
                        else {
                            ContenitoreGioco.setVisible(false);
                            // instanzio il gestore del gioco
                            GestoreGioco gestore(scelta, ContenitoreGioco);
                        }
                    }
                }
            }
            catch(int ex)
            { throw; }
        }
    }
}

//********************************************************************************************
//********************************************************************************************

// costruttore
MenuIniziale::MenuIniziale(int thread)
{
    ContenitoreGioco.create(VideoMode(1200, 1200), "777");
    ContenitoreGioco.setKeyRepeatEnabled(true);

    visualizzaMenu();
}

//********************************************************************************************