//
// Created by Matteo Conti on 18/10/17.
//

#include "Grafica.hpp"

Grafica::Grafica(int stack)
{
    posizione_partenza_testo_x=util.POSIZIONE_PARTENZA_FINESTRAsx_X+util.MARGINE_MAPPA;
    posizione_partenza_testo_y=util.POSIZIONE_PARTENZA_FINESTRAsx_Y+util.MARGINE_MAPPA;
    font.loadFromFile("../risorse/OpenSans.ttf");
    // status
    status_eroe.setFont(font);
    status_eroe.setFillColor(Color::Red);
    status_eroe.setCharacterSize(50);
    status_eroe.setPosition(posizione_partenza_testo_x, posizione_partenza_testo_y);
    // piano
    piano_attuale.setFont(font);
    piano_attuale.setFillColor(Color::White);
    piano_attuale.setCharacterSize(30);
    piano_attuale.setPosition(posizione_partenza_testo_x, status_eroe.getPosition().y+(2*util.MARGINE_MAPPA));
    // stanza
    stanza_attuale.setFont(font);
    stanza_attuale.setFillColor(Color::White);
    stanza_attuale.setCharacterSize(30);
    stanza_attuale.setPosition(posizione_partenza_testo_x, piano_attuale.getPosition().y+(1*util.MARGINE_MAPPA));
    // attacco eroe
    attacco_eroe.setFont(font);
    attacco_eroe.setFillColor(Color::White);
    attacco_eroe.setCharacterSize(30);
    attacco_eroe.setPosition(posizione_partenza_testo_x, stanza_attuale.getPosition().y+(2*util.MARGINE_MAPPA));
    // status
    vita_eroe.setFont(font);
    vita_eroe.setFillColor(Color::White);
    vita_eroe.setCharacterSize(30);
    vita_eroe.setPosition(posizione_partenza_testo_x, attacco_eroe.getPosition().y+(1*util.MARGINE_MAPPA));
    // attacco
    gittata_eroe.setFont(font);
    gittata_eroe.setFillColor(Color::White);
    gittata_eroe.setCharacterSize(30);
    gittata_eroe.setPosition(posizione_partenza_testo_x, vita_eroe.getPosition().y+(1*util.MARGINE_MAPPA));
    // esperienza eroe
    esperienza_eroe.setFont(font);
    esperienza_eroe.setFillColor(Color::White);
    esperienza_eroe.setCharacterSize(30);
    esperienza_eroe.setPosition(posizione_partenza_testo_x, gittata_eroe.getPosition().y+(1*util.MARGINE_MAPPA));
    // livello eroe
    livello_eroe.setFont(font);
    livello_eroe.setFillColor(Color::White);
    livello_eroe.setCharacterSize(30);
    livello_eroe.setPosition(posizione_partenza_testo_x, esperienza_eroe.getPosition().y+(1*util.MARGINE_MAPPA));
    // attacco nemico
    attacco_nemico.setFont(font);
    attacco_nemico.setFillColor(Color::White);
    attacco_nemico.setCharacterSize(30);
    attacco_nemico.setPosition(posizione_partenza_testo_x, livello_eroe.getPosition().y+(2*util.MARGINE_MAPPA));
    // istruzioni gioco
    titolo_istruzioni_gioco.setFont(font);
    titolo_istruzioni_gioco.setFillColor(Color::Red);
    titolo_istruzioni_gioco.setCharacterSize(50);
    titolo_istruzioni_gioco.setPosition(util.POSIZIONE_PARTENZA_FINESTRAdx_X+util.MARGINE_MAPPA, util.POSIZIONE_PARTENZA_FINESTRAdx_Y+util.MARGINE_MAPPA);
    istruzioni_gioco.setFont(font);
    istruzioni_gioco.setFillColor(Color::White);
    istruzioni_gioco.setCharacterSize(20);
    istruzioni_gioco.setPosition(util.POSIZIONE_PARTENZA_FINESTRAdx_X+util.MARGINE_MAPPA, util.POSIZIONE_PARTENZA_FINESTRAdx_Y+(4*util.MARGINE_MAPPA));
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
    texture_mappa0.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa1.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa2.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa3.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa4.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa5.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa6.loadFromFile("../risorse/immagini/muro-orizzontale.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa7.loadFromFile("../risorse/immagini/porta.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa8.loadFromFile("../risorse/immagini/freccia-giu.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa9.loadFromFile("../risorse/immagini/grass.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa11.loadFromFile("../risorse/immagini/freccia-su.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));
    texture_mappa99.loadFromFile("../risorse/immagini/red.png", sf::IntRect(0, 0, util.DIMENSIONE_CELLE, util.DIMENSIONE_CELLE));

    sf::Sprite immagine_mappa(texture_mappa99);
    for (int i=0; i<util.NUMERO_CASELLE_ASSE_X; i++)
        for (int j=0; j<util.NUMERO_CASELLE_ASSE_Y; j++)
        {
            switch(lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(i,j))
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


// ------------

void Grafica::creaTestiFinestraSinistra(Personaggio &eroe, int piano, int stanza, ListaNemici &nemici)
{
    // dettagli
    status_eroe.setString("Status Eroe");
    attacco_eroe.setString("Attacco Eroe = " + util.convertInt(eroe.potenza));
    vita_eroe.setString("Vita Eroe = " + util.convertInt(eroe.vitaAttuale));
    gittata_eroe.setString("Gittata Eroe = " + util.convertInt(eroe.gittata) + " celle");
    esperienza_eroe.setString("Esperienza Eroe = " + util.convertInt(eroe.esperienza) + "/10");
    livello_eroe.setString("Livello Eroe = " + util.convertInt(eroe.livello));
    piano_attuale.setString("Piano Attuale = " + util.convertInt(piano));
    stanza_attuale.setString("Stanza Attuale = " + util.convertInt(stanza));
    attacco_nemico.setString("Attacco Nemico = " + util.convertInt(nemici.array_nemici[0]->attacco));
}

// aggiorno i piani
void Grafica::aggiornaPiano(int piano)
{
    piano_attuale.setString("Piano Attuale = " + util.convertInt(piano));
}

// aggiorno le stanze
void Grafica::aggiornaStanza(int stanza)
{
    stanza_attuale.setString("Stanza Attuale = " + util.convertInt(stanza));
}


// istruzione del gioco
void Grafica::istruzioniGioco()
{
    titolo_istruzioni_gioco.setString("Istruzioni Gioco");
    istruzioni_gioco.setString( "1) Premi uno e poi le frecce per muoverti\n\n2) Premi due e poi spazio perattaccare\n\n"
                                        "3) Ogni nemico equivale ad un punto\n esperienza ogni 10 pt esperienza\n sali di livello\n\n"
                                        "4) Ogni volta che sali di livello aumenta\n l'attacco e ti rigeneri di 100 punti vita");


}



void Grafica::creoArrayPosizioni(ListaTorre &lista_torre, int stanza, int eroe_x, int eroe_y)
{
    lunghezza_array=0;
    //array_posizioni_consentite[0]={eroe_x, eroe_y};
    for (int i=0; i<=util.NUMERO_CASELLE_ASSE_X; i++)
    {
        for (int j = 0; j <=util.NUMERO_CASELLE_ASSE_Y; j++)
        {
            if(lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(i,j)==9)
            {
                lunghezza_array++;
                array_posizioni_consentite[lunghezza_array]={i+1,j+1};
                //std::cout<<lunghezza_array<<" - ["<<i+1<<", "<<j+1<<"] ==> "<<lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(j,i)<<" \n";
            }

        }
    }
}