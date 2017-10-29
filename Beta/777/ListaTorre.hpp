//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include "Piano.hpp"
#include "Mappa.hpp"

#ifndef INC_777_LISTATORRE_H
#define INC_777_LISTATORRE_H


/*! \brief \class ListaTorre
 * @details classe che gestisce piani e stanze
 */
class ListaTorre{

    public:
    /*! \brief \struct nodo
     * @details struttura che permette di muoversi tra piani
     */
    struct nodo
    {
        nodo *precedente; /*! \typedef nodo precedente*/
        Piano piano; /*! \typedef Piano piano*/ // UN OGGETTO CONTENTENTE UN ARRAY DI N ELEMENTI PARI AL NUMERO DI MAPPE DEL PIANO.
        nodo *successivo; /*! \typedef nodo successivo*/
    };
        typedef nodo *Lista;

        Lista torre = new nodo; /*! \typedef torre = new nodo*/

        /*! \brief \fn ListaTorre
         * @details costruttore ListaTorre
         */
        ListaTorre (){
        torre->precedente = NULL;
        torre ->successivo = NULL;
        torre->piano.crea(pianoMassimoRaggiunto , -1); //fare funzione che crea un piano di X mappe (1 in questo caso)
        }

        int getPianoAttuale ();
        int getPianoMassimoRaggiunto();
        void setPianoMassimoRaggiunto( int piano );
        void setPianoAttuale (int piano);

        /*! \brief \fn creaProssimoPiano
         * @details genera un nuovo nodo per crearci il piano
         */
        void creaProssimoPiano ();

        /*! \brief \fn prossimoPiano
         * @details si muove nel piano successivo
         */
        void prossimoPiano ();

        /*! \brief \fn pinorecedente
        * @details si muove nel piano precedente
         */
        void pianoPrecedente ();

    private:
        int pianoMassimoRaggiunto = 1; /*! \var int pianoMassimoRaggiunto */
        int pianoAttuale = 1; /*! \var int pianoAttuale */

};

#endif //INC_777_LISTATORRE_H
