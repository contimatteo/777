//
// Created by Matteo Conti on 10/10/17.
//

#ifndef INC_777_ELEMENTOGRAFICO_HPP
#define INC_777_ELEMENTOGRAFICO_HPP

#include <SFML/Graphics.hpp>
#include "Utilities.hpp"
using namespace sf;

/*! definizione della classe Utilities */
class Utilities;

/*! \brief \class ElementoGrafico
 * @details questa classe disegna tutti gli elementi del gioco
 */
class ElementoGrafico
{
    private:

    public:
        // ATTRIBUTI
        Sprite grafica; /*! \typedef Sprite grafica*/
        Texture texture; /*! \typedef Texture texture*/
        Utilities util; /*! \typedef Utilities util*/
        RenderWindow Gioco; /*! \typedef RenderWindow gioco*/
        int posX; /*! \var int posX */
        int posY; /*! \var int posY */
        int posX_iniziale, posY_iniziale; /*! \var int posX_iniziale \var int posY_iniziale  */
        int spostamento_x, spostamento_y; /*! \var int sopstamento_x \var int Spostamento_y */
        int pos_cella_x, pos_cella_y; /*! \var int pos_cella_x \var int pos_cella_y*/


        //METODI
        /*! \brief \fn muovi
         * @details questa funzione sposta un elemento nella mappa
         */
        void muovi();

        /*! \brief \fn setPosizione(int x, int y)
         * @param x
         * @param y
         * @details aggiorna la posizione dell' elemento grafico
         */
        void setPosizione(int x, int y);
        //------------------------------------------
        /*
         * 1: erore
         * 2: pet
         * 3: nemico
         * 4: altri
         * 5: ..
         * --------------
         * 10: mura mappa
         * 11: pavimento mappa
         * 12: ..
         */
        ElementoGrafico();

        /*! \brief ElementoGrafico costruttore
         * @param tipo_personaggio
         */
        ElementoGrafico(int tipo_personaggio);
        //------------------------------------------

};


#endif //INC_777_ELEMENTOGRAFICO_HPP
