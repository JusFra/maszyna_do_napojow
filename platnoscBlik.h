#ifndef platnoscBlik_h
#define platnoscBlik_h

#include <string>
#include <cstdlib>
#include <iostream>

#include "platnosc.h"

using namespace std;

class platnoscBlik : public platnosc{
    private:
        int a = 100000;
        int b = 999999;
    public:
        int blik(float, int);  
};

#endif