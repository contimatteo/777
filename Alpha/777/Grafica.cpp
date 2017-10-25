//
// Created by Matteo Conti on 18/10/17.
//

#include "Grafica.hpp"


Grafica::Grafica(int stack)
{
    // nothing to do
}

void Grafica::disegnaMappa(RenderWindow &Gioco, ListaTorre &lista_torre, int &stanza)
{
    // disegno bordi gioco
    sf::RectangleShape bordo_mappa(sf::Vector2f(util.LARGHEZZA_MAPPA+(2*util.MARGINE_MAPPA), util.ALTEZZA_MAPPA+(2*util.MARGINE_MAPPA)));
    bordo_mappa.setPosition(util.POSIZIONE_PARTENZA_MAPPA_X-util.MARGINE_MAPPA, util.POSIZIONE_PARTENZA_MAPPA_Y-util.MARGINE_MAPPA);
    bordo_mappa.setFillColor(util.COLORE_SFONDO);
    bordo_mappa.setOutlineColor(sf::Color::White);
    bordo_mappa.setOutlineThickness(1.5);
    Gioco.draw(bordo_mappa);

    Texture texture_mappa1, texture_mappa2, texture_mappa3, texture_mappa4, texture_mappa5, texture_mappa6, texture_mappa7,
            texture_mappa8, texture_mappa9, texture_mappa11, texture_mappa99, texture_mappa0;
    texture_mappa0.loadFromFile("../risorse/immagini/Nero.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa1.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa2.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa3.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa4.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa5.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa6.loadFromFile("../risorse/immagini/Marrone.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa7.loadFromFile("../risorse/immagini/rosa.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa8.loadFromFile("../risorse/immagini/freccia-giu.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa9.loadFromFile("../risorse/immagini/grass.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa11.loadFromFile("../risorse/immagini/freccia-su.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa99.loadFromFile("../risorse/immagini/red.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));

    sf::Sprite immagine_mappa(texture_mappa99);
    for (int i=0; i<util.NUMERO_CASELLE_ASSE_X; i++)
        for (int j=0; j<util.NUMERO_CASELLE_ASSE_Y; j++)
        {
            switch(lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(j,i))
            {
                case 0:
                {
                    immagine_mappa.setTexture(texture_mappa0, true);
                    break;
                }
                case 1:
                {
                    immagine_mappa.setTexture(texture_mappa1, true);
                    break;
                }
                case 2:
                {
                    immagine_mappa.setTexture(texture_mappa2, true);
                    break;
                }
                case 3:
                {
                    immagine_mappa.setTexture(texture_mappa3, true);
                    break;
                }
                case 4:
                {
                    immagine_mappa.setTexture(texture_mappa4, true);
                    break;
                }
                case 5:
                {
                    immagine_mappa.setTexture(texture_mappa5, true);
                    break;
                }
                case 6:
                {
                    immagine_mappa.setTexture(texture_mappa6, true);
                    break;
                }
                case 7:
                {
                    immagine_mappa.setTexture(texture_mappa7, true);
                    break;
                }
                case 8:
                {
                    immagine_mappa.setTexture(texture_mappa8, true);
                    break;
                }
                case 9:
                {
                    immagine_mappa.setTexture(texture_mappa9, true);
                    break;
                }
                case 11:
                {
                    immagine_mappa.setTexture(texture_mappa11, true);
                    break;
                }
                default:
                {
                    immagine_mappa.setTexture(texture_mappa99, true);
                    break;
                }
            }
            immagine_mappa.setPosition((util.POSIZIONE_PARTENZA_MAPPA_X)+(util.SPAZIO_CELLE*i),(util.POSIZIONE_PARTENZA_MAPPA_Y)+(util.SPAZIO_CELLE*j));
            Gioco.draw(immagine_mappa);
        }
}


