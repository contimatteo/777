//
// Created by Mattia_Porcelli on 21/06/2017.
//
#include "Mappa.hpp"



#ifndef INC_777_PIANO_H
#define INC_777_PIANO_H
class Piano {
        private:
            int pos_scale_salire = 0;
            int pos_scale_scendere = 0;

            void collega_mappe();
        public:

            /*struct {
                int idNodo;
                int config;
                int collegamenti[3];
            } typedef grafo;*/
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



            Mappa arr_mappe[50];
            int numero_mappe;
            void setPos_Scale_Salire (int scale);
            void setPos_Scale_Scendere (int scale);
            int getPos_Scale_Salire ();
            int getPos_Scale_Scendere ();
            void crea(int n, int scale2);


};



#endif //INC_777_PIANO_H
