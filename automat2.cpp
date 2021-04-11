#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>

#include "napoj.h"
#include "automat.h"
#include "platnosc.h"
#include "platnoscKarta.h"
#include "platnoscBlik.h"

using namespace std;

int automat2::readInt(int a){
    std::ifstream plik;
    plik.open("stdin.txt");
    int zmienna[5];
    for(int i = 0;i<5;i++){
        plik >> zmienna[i];
    }
    
    return zmienna[a];
}

void automat2::wypiszNapoje(napoj n0, napoj n1, napoj n2, napoj n3){
            cout << fixed;
            cout << setprecision(2);
            cout << "Dostepne napoje: " << endl;
            cout << n0.ID << ". " << n0.nazwa << ", cena: " << n0.cena << " zl, ilosc: " << iloscNapojow[0] << endl;
            cout << n1.ID << ". " << n1.nazwa << ", cena: " << n1.cena << " zl, ilosc: " << iloscNapojow[1] << endl;
            cout << n2.ID << ". " << n2.nazwa << ", cena: " << n2.cena << " zl, ilosc: " << iloscNapojow[2] << endl;
            cout << n3.ID << ". " << n3.nazwa << ", cena: " << n3.cena << " zl, ilosc: " << iloscNapojow[3] << endl;
        }
int automat2::wybierzNapoj() {
            int b = 0;
            int stop = 0;
            while(stop != 1){
                cout << "Wybierz napoj(1-4): " << endl;
                b = readInt(0);
                stop = ilosc(b);    //jeżeli ilośćNapojów = 0 lub wybrany zostanie napój którego nie ma na liście, napój nie zostanie wybrany
            }
            return b;
        }
bool automat2::ilosc(int b){
            if(iloscNapojow[b-1] == 0){
                cout << "Tego napoju juz nie ma. " << endl;
                return 0;
            }
            if(b>0 && b<=4){
                iloscNapojow[b-1] = iloscNapojow[b-1] - 1;
                return 1;
            }   
            else{
                cout << "Nie ma napoju o takim numerze. " << endl;
                return 0;
            }      
        }
void automat2::sposobPlatnosci(napoj n0, napoj n1, napoj n2, napoj n3, int i){
    int s = 0;
    while(s == 0){
        cout << "Wybierz rodzaj platnosci:\n1. gotowka\n2. BLIK\n3. Karta" << endl;
        s = readInt(1);
        int n;

        float ceny[4] = {n0.cena, n1.cena, n2.cena, n3.cena};
        float cena = ceny[i-1];

        switch(s){
            case 1:
            {
                cout << "Wybrano platnosc gotowka. " << endl;
                czyZaplacono(cena); 
                break;
            }
            case 2:
            {
                cout << "Wybrano platnosc BLIK. " << endl;
                platnoscBlik nowa1;
                s = nowa1.blik(cena);
                break;
            }
            case 3:
            {
                cout << "Wybrano platnosc karta. " << endl;
                platnoscKarta nowa2;
                s=nowa2.karta(cena);
                break;
            }
            default:
            {
                cout << "Niepoprawna forma platnosci. Wybierz jeszcze raz. " << endl;
                s=0;
                break;
            }
        }
    }
}

bool automat2::wrzuc_monete(float cena, float zaplata){
            if(fabs(0.09-zaplata) > cena){                     //fabs() daje wartość bezwzględną - użyty po to żeby porównać ze sobą liczby zmiennoprzecinkowe
                cout << "Nominal jest za duzy..." << endl;
                return 0;
            }
            else
                return 1;
        }
void automat2::czyZaplacono(float cena){
            float zaplata = 0.00;
            while(cena-0.09 > 0){
                cout << "Zostalo do zaplacenia: " << cena << endl;
                cout << "wrzuc monete" << endl;
                int z = 2;
                zaplata = readInt(z);
                z++;
                if(fabs(0.09-zaplata) > 5) zaplata *= 0.01;
                int i = wrzuc_monete(cena, zaplata);
                if(i==1) {
                    cena -= zaplata;
                }
            }
            cout << "Zaplacono!" << endl;
        }