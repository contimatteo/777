#include "Personaggio.hpp"
#include "ListaNemici.hpp"

//_____SETTER___________________
void Personaggio::setVitaAttuale(int vita){ vitaAttuale = vita; }
void Personaggio::setManaAttuale (int mana){ manaAttuale = mana; }
void Personaggio::setLivello (int liv) { livello = liv; }
void Personaggio::setArmatura (int arm) { armatura = arm; }
void Personaggio::setPotenza (int pot) { potenza = pot; }
void Personaggio::setSaggezza (int sag) { saggezza = sag;}
void Personaggio::setLv_skill1 (int lv) { lv_skill1 = lv; }
void Personaggio::setLv_skill2 (int lv) { lv_skill2 = lv; }
void Personaggio::setLv_skill3 (int lv) { lv_skill3 = lv; }
void Personaggio::setLv_skill4 (int lv) { lv_skill4 = lv; }
void Personaggio::setCritico (int crit) { critico = crit; }
//SETTIAMO LA POISIZIONE X
void Personaggio::setX(int posizionex){ posX = posizionex;}
//SETTIAMO LA POSIZIONE Y
void Personaggio::setY(int posizioney){posY = posizioney;}
//SETTIAMO LA NUOVA ESPERIENZA OTTENUTA
void Personaggio::setEsperienzaAttuale(int esperienzanuova){ esperienza=esperienza+esperienzanuova;}
void Personaggio::setContatoreSkill1(int contatore){contatoreSkill1 = contatore;}
void Personaggio::setContatoreSkill2(int contatore){contatoreSkill2 = contatore;}
void Personaggio::setContatoreSkill3(int contatore){contatoreSkill3 = contatore;}
void Personaggio::setContatoreSkill4(int contatore){contatoreSkill4 = contatore;}

//_____GETTER____________________
int Personaggio::getVitaAttuale(){return vitaAttuale;}
int Personaggio::getVitaMassima(){return vitaMassima;}
int Personaggio::getManaAttuale(){return manaAttuale;}
int Personaggio::getManaMassimo(){return manaMassimo;}
int Personaggio::getLivello(){return livello;}
int Personaggio::getArmatura(){return armatura;}
int Personaggio::getPotenza(){return potenza;}
int Personaggio::getSaggezza(){return saggezza;}
int Personaggio::getLv_skill1(){ return lv_skill1;}
int Personaggio::getLv_skill2(){ return lv_skill2;}
int Personaggio::getLv_skill3(){ return lv_skill3;}
int Personaggio::getLv_skill4(){ return lv_skill4;}
int Personaggio::getCritico(){ return critico;}
int Personaggio::getEsperienza(){ return esperienza;}
int Personaggio::getX(){return posX;}
int Personaggio::getY(){return posY;}
int Personaggio::getContatoreSkill1(){return contatoreSkill1;}
int Personaggio::getContatoreSkill2(){return contatoreSkill2;}
int Personaggio::getContatoreSkill3(){return contatoreSkill3;}
int Personaggio::getContatoreSkill4(){return contatoreSkill4;}


Personaggio::Personaggio(int tipo_personaggio): ElementoGrafico(tipo_personaggio)
{


}

void Personaggio::eliminaNemico(ListaNemici &nemici, int posizione, bool &flag)
{
    std::cout<<"nemico colpito in posizione "<<posizione<<"\n";
    nemici.array_nemici[posizione]->vita= nemici.array_nemici[posizione]->vita - potenza;
    if(potenza-nemici.array_nemici[posizione]->vita<=0)
    {
        // richiamiamo una funzione che elimina il nemico in posizione i
        //nemici.eliminaNemicoInPosizione(posizione);
        flag=true;
    }
}

void Personaggio::personaggioAttaccaNemico(ListaNemici &nemici)
{
    int vita=getVitaAttuale();
    //mi ricavo la lunghezza dell array per sapere quanti nemici ci sono nella stanza
    //controllo la distanza
    int i=0;
    bool flag=false;
    while ((i<nemici.numeroNemici) && (flag!=true))
    {
        // controllo se c'è un nemico vicino rispetto all'asse x
        if ((abs(nemici.array_nemici[i]->posX -posX) == gittata)&&(nemici.array_nemici[i]->posY==posY) && (flag!=false))
        {
            eliminaNemico(nemici,i,flag);
        }
        // controllo se c'è un nemico vicino rispetto all'asse y
        if((abs(nemici.array_nemici[i]->posY -posY) == gittata)&&(nemici.array_nemici[i]->posX==posX) && (flag!=false))
        {
            eliminaNemico(nemici,i,flag);
        }
        // controllo se c'è un nemico vicino rispetto alla diagonale principale in alto a sinistra
        if((posY+gittata==nemici.array_nemici[i]->posY)&&(posX+gittata==nemici.array_nemici[i]->posX) && (flag!=false))
        {
            eliminaNemico(nemici,i,flag);
        }
        // controllo se c'è un nemico vicino rispetto alla diagonale principale in basso a destra
        if((posY-gittata==nemici.array_nemici[i]->posY)&&(posX-gittata==nemici.array_nemici[i]->posX) && (flag!=false))
        {
            eliminaNemico(nemici,i,flag);
        }
        // controllo se c'è un nemico vicono rispetto alla diagonale secondaria
        if(posX-gittata==nemici.array_nemici[i]->posX)
        {
            if((posY+gittata==nemici.array_nemici[i]->posY) && (flag!=false))
            {
                eliminaNemico(nemici,i,flag);
            }
        }
        if(posX+gittata==nemici.array_nemici[i]->posX)
        {
            if((posY-gittata==nemici.array_nemici[i]->posY) && (flag!=false))
            {
                eliminaNemico(nemici,i,flag);
            }
        }
        i++;
    }
    if(!flag)
        std::cout<<"nessun nemico colpito \n";
    flag=false;
}