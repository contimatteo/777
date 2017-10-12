//
// Created by enrico on 21-Jun-17.
//

#ifndef INC_777_PET_H
#define INC_777_PET_H

    //CREAZIONE DELLA CLASSE PET

    class Pet {
    private:

        int vitaMax;
        int vitaAttuale;
        //INIZIALIZZATA NEL MAIN
        int x;
        int y;

    public:

    //GETTER E SETTER POSIZIONE______________________
    void setX(int posizionex);

    void setY(int posizioney);

    int getX();

    int getY();
    //_______________________________________________


    int getPet();

    void setPet(int vitaNuova);


};
//PET PER LA VITA MASSIMA
class PetVita: public Pet
{
private:

    char info='V';

public:

    char getInfo();
};

//PET PER IL MANA MASSIMO
class PetMana: public Pet
{
private:

    char info='M';

public:

    char getInfo()
    {
        return info;
    }
};

//PET PER ARMATURA
class PetArmatura: public Pet
{
private:

    char info='A';

public:

    char getInfo()
    {
        return info;
    }
};

//PET PER POTENZA
class PetPotenza: public Pet
{
private:

    char info='P';

public:

    char getInfo()
    {
        return info;
    }
};

//PET PER SAGGEZZA
class PetSaggezza: public Pet
{
private:

    char info='S';

public:

    char getInfo()
    {
        return info;
    }
};

//PET PER CRITICO
class PetCritico: public Pet
{
private:

    char info='C';

public:

    char getInfo()
    {
        return info;
    }
};


#endif //INC_777_PET_H
