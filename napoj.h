#ifndef napoj_h
#define napoj_h

#include <string>
#include <cstdlib>
#include <iostream>
#include "automat.h"
#include "automat2.h"
#include "platnosc.h"

using namespace std;
class automat2;
class automat;
class platnosc;

class napoj {
    friend class automat;
    friend class automat2;
    friend class platnosc;
    public:
        int ID;
        string nazwa;
        float cena;

        napoj (int id, string n, float c){
            ID = id;
            nazwa = n;
            cena = c;
        }
};

#endif