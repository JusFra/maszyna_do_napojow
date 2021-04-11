#ifndef automat2_h
#define automat2_h

#include <string>
#include <cstdlib>
#include <iostream>

#include "napoj.h"

using namespace std;

class napoj;

class automat2{
    private:
        int iloscNapojow[4] = {3, 3, 3, 3};
    public:
        int readInt(int);
        void wypiszNapoje(napoj, napoj, napoj, napoj);
        int wybierzNapoj();
        bool ilosc(int);
        void sposobPlatnosci(napoj, napoj, napoj, napoj, int);
        bool wrzuc_monete(float, float);
        void czyZaplacono(float);   
};

#endif