#include "Personaggio.hpp"
#include "ListaNemici.hpp"


Personaggio::Personaggio(int tipo_personaggio): ElementoGrafico(tipo_personaggio)
{


}

void Personaggio::eliminaNemico(ListaNemici &nemici, int posizione, bool &flag)
{
    std::cout<<"nemico colpito in posizione "<<posizione<<"\n";
    nemici.array_nemici[posizione]->vita= nemici.array_nemici[posizione]->vita - potenza;
    nemici.eliminaNemicoInPosizione(posizione);
   /*if(potenza-nemici.array_nemici[posizione]->vita<=0)
    {
        // richiamiamo una funzione che elimina il nemico in posizione i
        //nemici.eliminaNemicoInPosizione(posizione);
        flag=true;
    }*/
}

void Personaggio::personaggioAttaccaNemico(ListaNemici &nemici) {
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    //controllo la distanza
    int i = 0;
    bool flag = false;

    for (int distanza = 1; distanza <= gittata; distanza++)
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