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
            int numero_mappe =  0;
        public:
            Mappa arr_mappe[50];
            void setPos_Scale_Salire (int scale);
            void setPos_Scale_Scendere (int scale);
            int getPos_Scale_Salire ();
            int getPos_Scale_Scendere ();
            void crea(int n, int scale2);

};



#endif //INC_777_PIANO_H
