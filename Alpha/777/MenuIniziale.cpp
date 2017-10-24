//
// Created by Matteo Conti on 24/10/17.
//

#include "MenuIniziale.hpp"

MenuIniziale::MenuIniziale(RenderWindow &Gioco)
{
    // grafica menù
    sf::Texture texture;
    texture.loadFromFile("../risorse/immagini/menu-iniziale.jpg");
    Sprite immagine_menu(texture);
    immagine_menu.setScale(2, 2);

    bool scelta=false;
    menu.create(sf::VideoMode(util.LARGHEZZA_DISPLAY, util.ALTEZZA_DISPLAY), "My window");

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
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))||(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)))
        {
            scelta = true;
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
            menu.close();
            //Gioco.close();
        }

    }
}