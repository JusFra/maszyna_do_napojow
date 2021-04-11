#ifndef platnosc_h
#define platnosc_h

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class platnosc{
    protected:
        void pinpad();
        int podajKod();
        void wynikTranzakcji(bool, float);
};

#endif