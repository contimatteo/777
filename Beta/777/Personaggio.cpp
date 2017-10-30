#include "Personaggio.hpp"
#include "ListaNemici.hpp"


void Personaggio::impostaPosizionePartenzaPersonaggio(int x, int y)
{
    //std::cout<<"posizione partenza personaggio --> ["<<x<<", "<<y<<"] \n";
    // inizializzo variabili posizioni
    posX_iniziale=(util.POSIZIONE_PARTENZA_MAPPA_X)+(x*util.SPAZIO_CELLE)-util.SPAZIO_CELLE;
    posY_iniziale=(util.POSIZIONE_PARTENZA_MAPPA_Y)+(y*util.SPAZIO_CELLE)-util.SPAZIO_CELLE;
    posX=posX_iniziale; posY=posY_iniziale;
    pos_cella_x=x;  pos_cella_y=y;
    cella_di_patenza_asse_x=x; cella_di_patenza_asse_y=y;
    // imposto la sua posizione
    grafica.setPosition(posX, posY);
}

void Personaggio::resetPosizionePersonaggio(ListaTorre &lista_torre, int stanza)
{
    int x=0; bool trovato=false; int y=0;
    while ((x < 20)&&(!trovato))
    {
        while((y<20)&&(!trovato))
        {
            if(lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(x,y)==9)
            {
                trovato = true;
                impostaPosizionePartenzaPersonaggio(x+1, y+1);
                y=20; x=20;
            }
            else
                y++;
        }
        y=0;
        x++;
    }
}



Personaggio::Personaggio(int tipo_personaggio, ListaTorre &lista_torre, int stanza): ElementoGrafico(tipo_personaggio)
{
    int x=0; bool trovato=false; int y=0;
    while ((x < 20)&&(!trovato))
    {
        while((y<20)&&(!trovato))
        {
            if(lista_torre.torre->piano.arr_mappe[stanza-1].restituisci_valore(x,y)==9)
            {
                trovato = true;
                impostaPosizionePartenzaPersonaggio(x+1, y+1);
                y=20; x=20;
            }
            else
                y++;
        }
        y=0;
        x++;
    }
}

void Personaggio::eliminaNemico(ListaNemici &nemici, int posizione, bool &flag)
{
    //std::cout<<"nemico colpito in posizione "<<posizione<<"\n";
    nemici.array_nemici[posizione]->vita= nemici.array_nemici[posizione]->vita - potenza;
    //std::cout << "posizione eroe ==> "<<pos_cella_x<<" ~ "<<pos_cella_y<<"\n";
    //std::cout << "posizione nemico ==> "<<nemici.array_nemici[posizione]->pos_cella_x<<" ~ "<<nemici.array_nemici[posizione]->pos_cella_y<<"\n";
    nemici.eliminaNemicoInPosizione(posizione);
    esperienza = esperienza+1;
    if(esperienza==10)
    {
        livello = livello+1;
        potenza = (livello*2)+10;
        vitaAttuale= vitaAttuale+100;
        esperienza = 0;
    }
}

void Personaggio::personaggioAttaccaNemico(ListaNemici &nemici) {
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    //controllo la distanza
    int i = 0;
    int distanza = 0;
    bool flag = false;
    //std::cout <<nemici.numeroNemici<<" - "<<gittata<<"\n";
    for (distanza = 1; distanza<=gittata; distanza++)
    {
        for (int k = 0; k < nemici.numeroNemici; k++) {
            // controllo se c'è un nemico vicino rispetto all'asse x
            if ((!flag)&&(abs(nemici.array_nemici[k]->pos_cella_x - pos_cella_x) == distanza) && (nemici.array_nemici[k]->pos_cella_y == pos_cella_y))
            {
                eliminaNemico(nemici,k,flag);
                //std::cout << "trovato un nemico che va bene sull'asse x, a distanza = "<<distanza<<"\n";
                flag=true;
            }
            // controllo se c'è un nemico vicino rispetto all'asse y
            if ((!flag)&&(abs(nemici.array_nemici[k]->pos_cella_y - pos_cella_y) == distanza) && (nemici.array_nemici[k]->pos_cella_x == pos_cella_x))
            {
                eliminaNemico(nemici,k,flag);
                //std::cout << "trovato un nemico che va bene sull'asse y, a distanza = "<<distanza<<"\n";
                flag=true;
            }
            // controllo se c'è un nemico sulla diagonale 2 in basso a dx
            if ((!flag)&&(pos_cella_y-distanza == nemici.array_nemici[k]->pos_cella_y))
            {
                if (pos_cella_x+distanza == nemici.array_nemici[k]->pos_cella_x)
                {
                    eliminaNemico(nemici,k,flag);
                    //std::cout << "trovato un nemico che va bene sulla diagonale 2 in alto a dx, a distanza = "<<distanza<<"\n";
                    flag=true;
                }
            }
            // controllo se c'è un nemico sulla diagonale 2 in alto a sx
            if ((!flag)&&(pos_cella_y+distanza == nemici.array_nemici[k]->pos_cella_y))
            {
                if (pos_cella_x-distanza == nemici.array_nemici[k]->pos_cella_x)
                {
                    eliminaNemico(nemici,k,flag);
                    //std::cout << "trovato un nemico che va bene sulla diagonale 2 in basso a sx, a distanza = "<<distanza<<"\n";
                    flag=true;
                }
            }
            // controllo se c'è un nemico sulla diagonale 1 in alto a sx
            if ((!flag)&&(pos_cella_y-distanza == nemici.array_nemici[k]->pos_cella_y))
            {
                if (pos_cella_x-distanza == nemici.array_nemici[k]->pos_cella_x)
                {
                    eliminaNemico(nemici,k,flag);
                    //std::cout << "trovato un nemico che va bene sulla diagonale 1 in alto a sx, a distanza = "<<distanza<<"\n";
                    flag=true;
                }
            }
            // controllo se c'è un nemico sulla diagonale secondaria in basso a dx
            if ((!flag)&&(pos_cella_y+distanza == nemici.array_nemici[k]->pos_cella_y))
            {
                if (pos_cella_x+distanza == nemici.array_nemici[k]->pos_cella_x)
                {
                    eliminaNemico(nemici,k,flag);
                    //std::cout << "trovato un nemico che va bene sulla diagonale 1 in basso a dx, a distanza = "<<distanza<<"\n";
                    flag=true;
                }
            }
        }
    }
}

// fine del gioco
void Personaggio::fineGioco(RenderWindow &Gioco)
{
    if (vitaAttuale <= 0)
    {
        std::cout<<" ha vinto tony \n";
        Gioco.close();
    }
}


