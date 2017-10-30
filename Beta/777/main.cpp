/*
 * @author          Conti Matteo
 * @date            30/01/2017
 * @project         777 Game
 * @github_repo     'https://github.com/contimatteo/777-Game'
 */

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

int prossima_posizione_eroe_x=0; int prossima_posizione_eroe_y=0;
void muoviEroe(RenderWindow &Gioco, Personaggio &eroe, ListaTorre &lista_torre, Grafica &grafica, ListaNemici &nemici, int x, int y, bool &muovi_personaggio)
{
    prossima_posizione_eroe_x=(eroe.pos_cella_x)-1;
    prossima_posizione_eroe_y=(eroe.pos_cella_y)-1;
    prossima_posizione_eroe_x+=x;   prossima_posizione_eroe_y+=y;
    //controllo che la casella sia libera
    int valore_casella=lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(prossima_posizione_eroe_x, prossima_posizione_eroe_y);
    // siamo sull'erba
    if(valore_casella==9)
    {
        eroe.setPosizione(x, y);
        eroe.muovi();
        muovi_personaggio = false;
    }
    // siamo su porte o scale
    if((valore_casella==7) || (valore_casella==8) || (valore_casella==11))
    {
        eroe.setPosizione(x, y);
        eroe.muovi();
        muovi_personaggio = false;
        switch(valore_casella)
        {
            // porta
            case 7:
            {
                for(int k=0; k<lista_torre.getPianoAttuale(); k++)
                {
                    if(lista_torre.torre->piano.arr_mappe[k].isAporta(prossima_posizione_eroe_x, prossima_posizione_eroe_y))
                    {
                        // se entra vuol dire che in posizione [x,y] c'è una porta
                        // k è l'indice che devo usare per l'array porte che sta dentro Mappa
                        stanza=lista_torre.torre->piano.arr_mappe[k].idMappaPorta(prossima_posizione_eroe_x, prossima_posizione_eroe_y)+1;
                        //std::cout<<" prossima stanza --> "<<stanza<<" \n";
                    }
                }
                eroe.resetPosizionePersonaggio(lista_torre, stanza);
                nemici.ricreaNemici(lista_torre, eroe, grafica.array_posizioni_consentite, grafica.lunghezza_array, piano, stanza);
                break;
            }
            // scala a scendere
            case 8:
            {
                piano--;
                stanza=1;
                lista_torre.pianoPrecedente();
                eroe.resetPosizionePersonaggio(lista_torre, stanza);
                nemici.ricreaNemici(lista_torre, eroe, grafica.array_posizioni_consentite, grafica.lunghezza_array, piano, stanza);
                nemici.aggiornaAttaccoNemici(-80);
                break;
            }
            // scala a salire
            case 11:
            {
                piano++;
                stanza=1;
                lista_torre.prossimoPiano();
                eroe.resetPosizionePersonaggio(lista_torre, stanza);
                nemici.ricreaNemici(lista_torre, eroe, grafica.array_posizioni_consentite, grafica.lunghezza_array, piano, stanza);
                nemici.aggiornaAttaccoNemici(80);
                break;
            }
            default:
            {
                // unreachable code
            }
        }
        // aggiorno nel menu il piano
        grafica.aggiornaPiano(piano);
        // aggiorno nel menu la stanza
        grafica.aggiornaStanza(stanza);
        // disegno la nuova stanza
        grafica.disegnaMappa(Gioco, lista_torre, stanza);
        // ricreo l'array delle posizioni consentite
        grafica.creoArrayPosizioni(lista_torre, stanza, eroe.pos_cella_x, eroe.pos_cella_y);
    }
}


void disegnaMappa(RenderWindow &Gioco, Grafica &grafica, ListaTorre &lista_torre)
{
    grafica.disegnaMappa(Gioco, lista_torre, stanza);
}

void disegnaFinestraSinistra(RenderWindow &Gioco, Grafica &grafica, Personaggio &eroe, ListaNemici &nemici)
{
    // disegno finestra di sx
    sf::RectangleShape finestra(sf::Vector2f(util.LARGHEZZA_FINESTRAsx, util.ALTEZZA_FINESTRAsx));
    finestra.setPosition(util.POSIZIONE_PARTENZA_FINESTRAsx_X, util.POSIZIONE_PARTENZA_FINESTRAsx_Y);
    finestra.setFillColor(sf::Color::Black);
    finestra.setOutlineColor(sf::Color::White);
    finestra.setOutlineThickness(1.5);
    Gioco.draw(finestra);
    grafica.creaTestiFinestraSinistra(eroe, piano, stanza, nemici);
    Gioco.draw(grafica.piano_attuale);
    Gioco.draw(grafica.stanza_attuale);
    Gioco.draw(grafica.status_eroe);
    Gioco.draw(grafica.attacco_eroe);
    Gioco.draw(grafica.vita_eroe);
    Gioco.draw(grafica.gittata_eroe);
    Gioco.draw(grafica.esperienza_eroe);
    Gioco.draw(grafica.livello_eroe);
    Gioco.draw(grafica.attacco_nemico);
}

void disegnaFinestraDestra(RenderWindow &Gioco, Grafica &grafica, Personaggio &eroe)
{
    // disegno finestra di dx
    sf::RectangleShape finestra(sf::Vector2f(util.LARGHEZZA_FINESTRAdx, util.ALTEZZA_FINESTRAdx));
    finestra.setPosition(util.POSIZIONE_PARTENZA_FINESTRAdx_X, util.POSIZIONE_PARTENZA_FINESTRAdx_Y);
    finestra.setFillColor(sf::Color::Black);
    finestra.setOutlineColor(sf::Color::White);
    finestra.setOutlineThickness(1.5);
    Gioco.draw(finestra);
    grafica.istruzioniGioco();
    Gioco.draw(grafica.titolo_istruzioni_gioco);
    Gioco.draw(grafica.istruzioni_gioco);

}

void disegnaEroe(RenderWindow &Gioco, Personaggio &eroe)
{
    Gioco.draw(eroe.grafica);
}


void disegnaElementiGrafici(RenderWindow &Gioco, Personaggio &eroe, ListaNemici &nemici, Grafica &grafica)
{
    disegnaFinestraSinistra(Gioco, grafica, eroe, nemici);
    disegnaFinestraDestra(Gioco, grafica, eroe);
    disegnaEroe(Gioco, eroe);
    nemici.disegnaNemici(Gioco);
}

void azioni_nemico(RenderWindow &Gioco, Personaggio &eroe, ListaNemici &nemici, ListaTorre &lista_torre, Grafica &grafica)
{
    // controllo se togliere vita al personaggio
    nemici.nemicoAttaccaPersonaggio(eroe);
    // muovo i nemici
    util.azzeraPosizioni();
    nemici.spostaNemici(eroe, lista_torre, grafica.array_posizioni_consentite, grafica.lunghezza_array, eroe.pos_cella_x, eroe.pos_cella_y, piano, stanza);
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
    // Istanzio L' eroe
    Personaggio eroe(1, lista_torre, stanza);
    // Instanzio la mappa
    Grafica grafica(0);
    grafica.creoArrayPosizioni(lista_torre, stanza, eroe.cella_di_patenza_asse_x, eroe.cella_di_patenza_asse_y);
    // Instanzio i nemici
    ListaNemici nemici(lista_torre, eroe, grafica.array_posizioni_consentite, grafica.lunghezza_array, piano, stanza);
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
            muoviEroe(Gioco, eroe, lista_torre, grafica, nemici, -1, 0, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre, grafica);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && muovi_personaggio) {
            // freccia Destra premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, lista_torre, grafica, nemici, 1, 0, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre, grafica);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && muovi_personaggio) {
            // freccia SU premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, lista_torre, grafica, nemici, 0, -1, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre, grafica);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && muovi_personaggio) {
            // freccia GIU premuta: muovi il personaggio
            muoviEroe(Gioco, eroe, lista_torre, grafica, nemici, 0, 1, muovi_personaggio);
            // test
            azioni_nemico(Gioco, eroe, nemici, lista_torre, grafica);
        }
        // attacco eroe
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))||(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)))
        {
            eroe_attacca=true;
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))&&(eroe_attacca))
        {
            eroe.personaggioAttaccaNemico(nemici);
            //azioni_nemico(Gioco, eroe, nemici, lista_torre, grafica);
            eroe_attacca=false;
        }
        // Clear screen
        Gioco.clear(util.COLORE_SFONDO);
        // disegno la mappa
        disegnaMappa(Gioco, grafica, lista_torre);
        // disegno l'erore
        disegnaElementiGrafici(Gioco, eroe, nemici, grafica);
        // controllo se ha perso
        eroe.fineGiocoHaPerso(Gioco);
        // controllo se ha vinto
        eroe.fineGiocoHaVinto(Gioco, piano, stanza);
        // display
        Gioco.display();
    }
    // programma terminato correttamente
    return EXIT_SUCCESS;
}

//-----------------------------