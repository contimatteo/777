//
// Created by enrico on 21-Jun-17.
//

#ifndef INC_777_NEMICO_H
#define INC_777_NEMICO_H

#include "ElementoGrafico.hpp"


/*! \brief \class Nemico
 * @details la classe nemico crea un nemico
 */
class Nemico: public ElementoGrafico
{

public:
    int attacco; /*! \var int attacco*/
    int vita=30; /*! \var int vita*/
    //identificativo nemico
    int id; /*! \var int id*/
    bool cancellato; /*! \var bool cancellato*/

    /*! \brief \fn Nemico(int tipo_nemico, int x, int y, int identificatore, int attacco_nemico )
     * @param tipo_nemico
     * @param x
     * @param y
     * @param identificatore
     * @param attacco_nemico
     * @details costruttore della classe Nemico
     */
    Nemico(int tipo_nemico, int x, int y, int identificatore, int attacco_nemico );

};

#endif //INC_777_NEMICO_H
