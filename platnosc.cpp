#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "platnosc.h"

using namespace std;

void platnosc::pinpad(){
    cout << "_______" << endl;
    cout << "|1|2|3|" << endl;
    cout << "|4|5|6|" << endl;
    cout << "|7|8|9|" << endl;
    cout << "#######" << endl;
}
int platnosc::podajKod(){
    int k;
    cin >> k;
    return k;
}
void platnosc::wynikTranzakcji(bool w, float cena){
    if(w==1)
        cout << "Tranzakcja zaakceptowana. Zaplacono: " << cena << endl;
    else
        cout << "Tranzakcja nie powiodla sie... Sproboj ponownie. " << endl; 
}
