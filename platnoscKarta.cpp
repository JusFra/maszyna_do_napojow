#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "platnoscKarta.h"

using namespace std;

int platnoscKarta::karta(float cena, int PIN){
            cout << "Wloz karte i podaj kod PIN (4 cyfry): " << endl;
            pinpad();
            int k;
            if(PIN == 0){
                k = podajKod();
            }
            else{
                k = PIN;
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