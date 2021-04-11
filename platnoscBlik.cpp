#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "platnoscBlik.h"

using namespace std;

int platnoscBlik::blik(float cena, int BLIK){
            cout << "Podaj numer BLIK (6 cyfr): " << endl;
            pinpad();
            int k;
            if(BLIK==0){
                k = podajKod();
            }
            else{
                k = BLIK;
            }
            if(k>=a && k<=b){
                wynikTranzakcji(1, cena);
                return 1;
            }
            else{
                wynikTranzakcji(0, cena);
                return 0;
            }
        }    