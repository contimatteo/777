//
// Created by Matteo Conti on 23/06/17.
//

#ifndef INC_777_MENUINIZIALE_HPP
#define INC_777_MENUINIZIALE_HPP
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

class MenuIniziale
{
    private:
        // attributi
        int                 scelta;
        RenderWindow        ContenitoreGioco;
        RectangleShape      contenitore;
        RectangleShape      titoloGioco;
        RectangleShape      rettangoloScelta1;
        RectangleShape      rettangoloScelta2;
        RectangleShape      rettangoloScelta3;
        RectangleShape      rettangoloScelta4;
        Font                font;
        Text                rettangolo1Testo;
        Text                rettangolo2Testo;
        Text                rettangolo3Testo;
        Text                rettangolo4Testo;
        // metodi
        int scegliOpzione();
        void creaGraficaMenuIniziale();
        //void inizioSceltaMenuIniziale();

    public:
        void visualizzaMenu();
        // costruttori
        MenuIniziale(int thread);

};
#endif //INC_777_MENUINIZIALE_HPP
