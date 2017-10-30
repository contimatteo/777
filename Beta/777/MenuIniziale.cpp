//
// Created by Matteo Conti on 24/10/17.
//

#include <SFML/Audio/Music.hpp>
#include "MenuIniziale.hpp"

MenuIniziale::MenuIniziale(RenderWindow &Gioco)
{
// sfondo menu
    RectangleShape sfondoMenu(Vector2f(util.LARGHEZZA_DISPLAY, util.ALTEZZA_DISPLAY));
    Color colore_sfondo;
    colore_sfondo.r=250;    colore_sfondo.g=208;    colore_sfondo.b=196;
    sfondoMenu.setFillColor(colore_sfondo);
    sfondoMenu.setPosition(0,0);
    // grafica menù
    sf::Texture texture;
    texture.loadFromFile("../risorse/immagini/menu-iniziale.jpg");
    Sprite immagine_menu(texture);
    immagine_menu.setScale(1, 1);
    int pos_x = (util.LARGHEZZA_DISPLAY/2)-(texture.getSize().x/2);
    int pos_y = (util.ALTEZZA_DISPLAY/2)-(texture.getSize().y/2);;
    immagine_menu.setPosition(pos_x, pos_y);
    // musica
    Music music;
    music.openFromFile("../risorse/audio/menu-music.ogg");
    music.setVolume(50);
    music.setLoop(false);
    //music.play();

    bool scelta=true;
    menu.create(sf::VideoMode((unsigned int)util.LARGHEZZA_DISPLAY, (unsigned int)util.ALTEZZA_DISPLAY), "777 - Menu");
    menu.draw(sfondoMenu);
    menu.draw(immagine_menu);
    menu.display();

    // eseguo il gioco finchè la finestra rimane aperta
    while (menu.isOpen())
    {
        // sincronizzo il frame-rate del gioco con quello dello schermo
        menu.setVerticalSyncEnabled(true);
        // Process events
        sf::Event event;

        while (menu.pollEvent(event))
        {
            // controllo che la finestra del gioco non venga ridimensionata
            if (event.type == sf::Event::Resized)
            {
                const Vector2u dimensioni = Vector2u((unsigned int)util.LARGHEZZA_DISPLAY, (unsigned int)util.ALTEZZA_DISPLAY);
                menu.setSize(dimensioni);
            }
            // controllo quando la finestra viene chiusa --> chiudo il gioco
            if (event.type == sf::Event::Closed)
            {
                menu.close();
                Gioco.close();
            }
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && scelta)
        {
            scelta=false;
            menu.close();
            // apro il Gioco
            Gioco.setVisible(true);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C)) && scelta)
        {
            scelta=false;
            // chiudo il Gioco
            Gioco.close();
            menu.close();
        }

    }
}
