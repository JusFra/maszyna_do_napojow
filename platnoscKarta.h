#ifndef platnoscKarta_h
#define platnoscKarta_h

#include <string>
#include <cstdlib>
#include <iostream>
#include "platnosc.h"

using namespace std;

class platnoscKarta : public platnosc{
    private:
        int a = 1000;
        int b = 9999;
    public:
        int karta(float, int);
};

#endif