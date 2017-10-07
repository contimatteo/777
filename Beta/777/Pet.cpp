//
// Created by Matteo Conti on 26/06/17.
//

#include "Pet.hpp"

#include <SFML/Graphics.hpp>
using namespace sf;

void Pet::setImmagine(String percorso)
{
    this->immagine.~Texture();
    this->immagine.loadFromFile(percorso);
    this->grafica.setTexture(this->immagine);
}

/*********************************************************
 *
 * PET
 */

//GETTER E SETTER POSIZIONE______________________
void Pet::setX(int posizionex)
{
    this->x = posizionex;
    this->grafica.setPosition(posizionex, this->grafica.getPosition().y);
}
void Pet::setY(int posizioney)
{
    this->y = posizioney;
    this->grafica.setPosition(this->grafica.getPosition().x, posizioney);
}
int Pet::getX() { return this->x;}
int Pet::getY() {return this->y;}
//_______________________________________________

int Pet::getPet()
{
    return this->vitaMax;
}

void Pet::setPet(int vitaNuova) {
    if ((vitaNuova + vitaAttuale) > this->vitaMax) {
        vitaAttuale = vitaMax;
    } else {
        this->vitaAttuale = vitaNuova + vitaAttuale;
    }
}

// costruttore
Pet::Pet(std::string nomeFile)
{
    std::string percorso = "../risorse/immagini/";
    percorso.append(nomeFile);
    percorso.append(".png");
    Texture immagine;
    immagine.loadFromFile(percorso);
    grafica.setTexture(immagine);
}

// distruttore
Pet::~Pet()
{
    //this->grafica.~Drawable();
}

//*********************************************************
/*********************************************************
 *
 * PET PER LA VITA MASSIMA
 */

char PetVita::getInfo()
{
    return info;
}
void PetVita::setInfo()
{
    info='V';
}

//*********************************************************
/*********************************************************
 *
 *      PET PER IL MANA MASSIMO
 */

char PetMana::getInfo()
{
    return info;
}
void PetMana::setInfo()
{
    info='M';
}

//*********************************************************
/*********************************************************
 *
 *      PET PER ARMATURA
 */

char PetArmatura::getInfo()
{
    return info;
}
void PetArmatura::setInfo()
{
    info='A';
}

//*********************************************************
/*********************************************************
 *
 *      PET PER POTENZA
 */

char PetPotenza::getInfo()
{
    return info;
}
void PetPotenza::setInfo()
{
    info='P';
}

//*********************************************************
/*********************************************************
 *
 *      PET PER SAGGEZZA
 */

char PetSaggezza::getInfo()
{
    return this->info;
}
void PetSaggezza::setInfo()
{
    info='S';
}

//*********************************************************
/*********************************************************
 *
 *      PET PER CRITICO
 */

char PetCritico::getInfo()
{
    return this->info;
}
void PetCritico::setInfo()
{
    info='C';
}

//*********************************************************

