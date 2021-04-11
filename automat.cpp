#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>

#include "napoj.h"
#include "automat.h"
#include "platnosc.h"
#include "platnoscKarta.h"
#include "platnoscBlik.h"

using namespace std;

void automat::bladAutomat(int b){
    if(b==1 || b==2 || b==3 || b==4)
        return;
    if(fabs(b)>9999999)
        throw 99;
    if(b<1 || b>4)
        throw 9.999f;
}
template<typename T>                        // szblon gdyby w przyszłości istniała potrzeba wczytywania nie tylko INTów
T automat::czytaj(T a){
    std::ifstream plik;
    plik.open("stdin.txt");                 // po dodaniu numeru po nazwie stdin otworzy sie kolejny plik
    T zmienna[5];
    for(int i = 0;i<5;i++){
        plik >> zmienna[i];
    }
    return zmienna[a];
}
void automat::wypiszNapoje(const vector <napoj> & vec){
            cout << fixed;
            cout << setprecision(2);
            cout << "Dostepne napoje: " << endl;
            for(unsigned int i=0; i < 4; i++){
                cout << vec[i].ID << ". " << vec[i].nazwa << ", cena: " << vec[i].cena << " zl, ilosc: " << iloscNapojow[i] << endl;
            }
}
int automat::wybierzNapoj(int x) {
            int b = 0;
            int stop = 0;
            if(x == 1){
                b = czytaj(0);
                try{
                    bladAutomat(b);
                }
                catch(int x){
                    cout << "Niestety plik jest pusty lub uszkodzony. Musisz wpisywac komendy samodzielnie. " << endl;
                    return 999;
                }
                catch(float x){
                    cout << "Dane w pliku sa wpisane niepoprawnie. Musisz wpisywac komendy samodzielnie. " << endl;
                    return 999;
                }
                catch(...){
                    cout << "Wystapil blad. Musisz wpisywac komendy samodzielnie. " << endl;
                    return 999;
                }
            }
            else{
                while(stop != 1){
                    cout << "Wybierz napoj(1-4): " << endl;
                    cin >> b;
                    stop = ilosc(b);    //jeżeli ilośćNapojów = 0 lub wybrany zostanie napój którego nie ma na liście, napój nie zostanie wybrany
                }
            }
            return b;
}
bool automat::ilosc(int b){
            if(b == 0){
                cout << "0 Nie ma napoju o takim numerze. " << endl;
                return 0;
            }
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
void automat::sposobPlatnosci(const vector <napoj> & vec, int i, int x){
    int s = 0;
    while(s == 0){
        cout << "Wybierz rodzaj platnosci:\n1. gotowka\n2. BLIK\n3. Karta" << endl;
        if(x==1)
            s = czytaj(1);
        else
            cin >> s;

        int n;

        float ceny[4] = {vec[0].cena, vec[1].cena, vec[2].cena, vec[3].cena};
        float cena = ceny[i-1];

        switch(s){
            case 1:
            {
                cout << "Wybrano platnosc gotowka. " << endl;
                czyZaplacono(cena, x); 
                break;
            }
            case 2:
            {
                cout << "Wybrano platnosc BLIK. " << endl;
                platnoscBlik nowa1;
                int BLIK;
                if(x==1)
                    BLIK = czytaj(2);
                else
                    BLIK = 0;
                s = nowa1.blik(cena, BLIK);
                break;
            }
            case 3:
            {
                cout << "Wybrano platnosc karta. " << endl;
                platnoscKarta nowa2;
                int PIN;
                if(x==1)
                    PIN = czytaj(2);
                else
                    PIN = 0;
                s=nowa2.karta(cena, PIN);
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
bool automat::wrzuc_monete(float cena, float zaplata){
            if(fabs(0.09-zaplata) > cena){                     //fabs() daje wartość bezwzględną - użyty po to żeby porównać ze sobą liczby zmiennoprzecinkowe
                cout << "Nominal jest za duzy..." << endl;
                return 0;
            }
            else
                return 1;
}
void automat::czyZaplacono(float cena, int x){
            float zaplata = 0.00;
            while(cena-0.09 > 0){
                cout << "Zostalo do zaplacenia: " << cena << endl;
                cout << "wrzuc monete" << endl;
                if(x==1)
                    zaplata = czytaj(2);
                else
                    cin >> zaplata;
                    
                if(fabs(0.09-zaplata) > 5) zaplata *= 0.01;
                int i = wrzuc_monete(cena, zaplata);
                if(i==1)
                    cena -= zaplata;
            }
            cout << "Zaplacono!" << endl;
}