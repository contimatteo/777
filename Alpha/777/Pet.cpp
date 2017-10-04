#include "Pet.hpp"


//PET--------

void Pet::setX(int posizionex){x=posizionex;}
void Pet::setY(int posizioney){y=posizioney;}
int Pet::getX() {return x;}
int Pet::getY() {return y;}
int Pet::getPet() { return vitaMax;}
void Pet::setPet(int vitaNuova)
{
    if ((vitaNuova+vitaAttuale) > vitaMax)
    {
        vitaAttuale=vitaMax;
    }
    else
    {
        vitaAttuale = vitaNuova+vitaAttuale;
    }
}
//-------------

//*********************************************************
/*********************************************************
 *
 * PET PER LA VITA MASSIMA
 */

char PetVita::getInfo()
{
    return info;
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

//*********************************************************
/*********************************************************
 *
 *      PET PER ARMATURA
 */

char PetArmatura::getInfo()
{
    return info;
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

//*********************************************************
/*********************************************************
 *
 *      PET PER SAGGEZZA
 */

char PetSaggezza::getInfo()
{
    return info;
}
//*********************************************************
/*********************************************************
 *
 *      PET PER CRITICO
 */

char PetCritico::getInfo()
{
    return info;
}
//*********************************************************

//--------------


