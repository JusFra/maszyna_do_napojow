#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

#include "napoj.h"
#include "automat.h"

using namespace std;

void blad(int);
int wpisywanie();

int main()
{
    vector <napoj> vec;
    vec.emplace_back(1, "Cola", 2.00);
    vec.emplace_back(2, "Pepsi", 3.70);
    vec.emplace_back(3, "Fanta", 6.10);
    vec.emplace_back(4, "Sprite", 10.00);

    cout << "\nAutomat przyjmuje monety o nominalach: \n10 gr, 20 gr, 50 gr, 1 zl, 2 zl, 5 zl" << endl;

    int stop = 1;
    int i = 0;    //zmienna przedtawiajaca ilosc napojow
    
    int x = wpisywanie();
    cout << x << endl;

    automat nowy;
    while(stop != 0){
        nowy.wypiszNapoje(vec);
        i = nowy.wybierzNapoj(x);
        if(i==999){
            x=0;
            i = nowy.wybierzNapoj(x);
        }
        nowy.sposobPlatnosci(vec, i, x);
            
        cout << "Oto Twoj napoj. Jezeli chcesz kontynuwac zakupy wybierz 1. Jezeli chcesz zakonczyc wybierz 0. " << endl;
        cin >> stop;
    }
    cout <<"Do widzenia!" << endl;
    return 0;
}

void blad(int x){
    if(x==0 || x==1){return;}
    else{throw x;}
}

int wpisywanie(){
    cout << "Czy chcesz czytac komendy z pliku? Jesli tak wcisnij 1. Jezeli chcesz wpisywac komendy samodzielnie wcisnij 0 " << endl;
    int x = 0; // x to zmienna która będzie zwracana(0 lub 1). Oznacza to czy mamy wpisywac komendy samodzielnie czy z pliku.
    cin >> x;
   
    try{
        blad(x);   
    }
    catch(int x){
        cout << "Blad. Twoj wybor to: " << x << ". Nie ma takiej opcji. Kontynuuj zakupy wpisujac komendy samodzielnie." << endl;
        return 0; // zwraca 0 czyli użytkownik będzie wpisywał dalej sam komendy
    }
    return x; // 0 lub 1
}
