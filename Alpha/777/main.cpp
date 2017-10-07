
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

//---------------------------------

int N=60,M=60;
int dimensione_celle=20;
int w = dimensione_celle*N;
int h = dimensione_celle*M;

void muovi(RenderWindow &w, Sprite &s, int x, int y)
{
    s.move(x, y);
}

int main()
{
    bool muovi_personaggio=false;
    sf::RenderWindow Gioco(sf::VideoMode(1200, 1200), "777 - Game");
    Gioco.setKeyRepeatEnabled(true);
    sf::Texture texture;
    if (!texture.loadFromFile("../risorse/immagini/red.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

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
            //sprite.move(-0.5, 0);
            muovi(Gioco, sprite, -dimensione_celle, 0);
            muovi_personaggio = false;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && muovi_personaggio) {
            // freccia Destra premuta: muovi il personaggio
            muovi(Gioco, sprite, dimensione_celle, 0);
            muovi_personaggio = false;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && muovi_personaggio) {
            // freccia SU premuta: muovi il personaggio
            muovi(Gioco, sprite, 0, -dimensione_celle);
            muovi_personaggio = false;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && muovi_personaggio) {
            // freccia GIU premuta: muovi il personaggio
            muovi(Gioco, sprite, 0, dimensione_celle);
            muovi_personaggio = false;
        }

        // Clear screen
        Gioco.clear();
        // disegno la mappa
        sf::Texture texture2;
        texture2.loadFromFile("../risorse/immagini/white.png");
        sf::Sprite sprite2(texture2);
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
            { sprite2.setPosition(i*dimensione_celle,j*dimensione_celle);  Gioco.draw(sprite2); }
        // Draw the sprite
        Gioco.draw(sprite);
        // Update the window
        Gioco.display();
    }

    // programma terminato correttamente
    return EXIT_SUCCESS;
}