//
// Created by Matteo Conti on 26/06/17.
//

#ifndef INC_777_PET_HPP
#define INC_777_PET_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include "ElementoGrafico.hpp"
using namespace sf;

//****************************************************************
//****************************************************************

// PET
class Pet : public ElementoGrafico
{
    private:
        int vitaMax;
        int vitaAttuale;
        //INIZIALIZZATA NEL MAIN
        int x;
        int y;

    public:
        //GETTER E SETTER POSIZIONE-----------------------
        void setX(int posizionex);
        void setY(int posizioney);
        int getX();
        int getY();
        //------------------------------------------------
        int getPet();
        void setPet(int vitaNuova);
        Sprite grafica;

        // costruttore
        Pet(std::string nomeFile);

        // distruttore
        ~Pet();
};

//****************************************************************
//****************************************************************

// PET PER LA VITA MASSIMA
class PetVita: public Pet
{
private:
    char info;

public:
    char getInfo();
    void setInfo();
};

//****************************************************************
//****************************************************************

// PET PER MANA MASSIMO
class PetMana: public Pet
{
private:
    char info;

public:
    char getInfo();
    void setInfo();
};

//****************************************************************
//****************************************************************

// PET PER ARMATURA
class PetArmatura: public Pet
{
private:
    char info;

public:
    char getInfo();
    void setInfo();
};

//****************************************************************
//****************************************************************

// PET PER POTENZA
class PetPotenza: public Pet
{
private:
    char info;

public:
    char getInfo();
    void setInfo();
};

//****************************************************************
//****************************************************************

// PET PER SAGGEZZA
class PetSaggezza: public Pet
{
private:
    char info;

public:
    char getInfo();
    void setInfo();
};

//****************************************************************
//****************************************************************

// PET PER CRITICO
class PetCritico: public Pet
{
private:
    char info;

public:
    char getInfo();
    void setInfo();
};


#endif //INC_777_PET_HPP
