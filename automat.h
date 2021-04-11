#ifndef automat_h
#define automat_h

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "napoj.h"

using namespace std;

class napoj;

class automat{
    private:
        int iloscNapojow[4] = {3, 3, 3, 3};
    public:
        void bladAutomat(int);
        template<typename T>
        T czytaj(T);
        void wypiszNapoje(const vector <napoj>&);
        int wybierzNapoj(int);
        bool ilosc(int);
        void sposobPlatnosci(const vector <napoj>&, int, int);
        bool wrzuc_monete(float, float);
        void czyZaplacono(float, int);   
};

#endif