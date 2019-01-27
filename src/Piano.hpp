//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include "Mappa.hpp"



#ifndef INC_777_PIANO_H
#define INC_777_PIANO_H

/*! \brief \class Piano
 * @details classe che gestisce i piani e li collega tra loro
 */
class Piano {
        private:
            int pos_scale_salire = 0; /*! \var int pos_scale_salire */
            int pos_scale_scendere = 0; /*! \var pos_scale_scendere */

            /*! \brief \fn void collega_mappe
             * @details funzione che collega le mappe tra loro
             */
            void collega_mappe();
        public:

#if 0
    class grafo
    {
        protected:
            int **nodi;
        public:
            grafo(int n)
            {
                nodi = new int*[n];
                for(int i = 0; i < n; i++)
                    nodi[i] = new int[3];
            }
            ~grafo()
            {
            for(int i = 0; i < n; i++)
                    delete nodi[i];
             delete nodi;
                         }


    };
    int cc(int []components,grafo& g)
    {
        componente = 0
        visitato = bool[0..g.n]
        for i in [0,n-10]
            visitato[i] = false
        foreach node in g:
            if !visited[node]:
                ccdfs(node,g,visitato,components,componente)
                componente++
        return componente + 1
    }
#endif

    Mappa arr_mappe[50]; /*! \typedef Mappa arr_mappe*/
    int numero_mappe; /*! \var int numero_mappe */

    /*! \brief \fn void crea
     * @param n
     * @param scale2
     * @details crea le scale a salire e scendere all' interno della stanza
     */
    void crea(int n, int scale2);
};



#endif //INC_777_PIANO_H
