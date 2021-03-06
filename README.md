
# Automat z napojami

Projekt wykonany w ramach zaliczenia ćwiczeń programowanie obiektowe.

## Etap 1

Program oferujący następujące funkcjonalności:

Po uruchomieniu programu użytkownik ma możliwość wybrania napoju do zakupienia (4
dowolne napoje). Automat ma na początku po 3 sztuki każdego napoju.
Automat akceptuje monety o nominałach 10 gr, 20 gr, 50 gr, 1 zł, 2 zł, 5 zł. Ceny napoi:
2 zł, 3 zł 70 gr, 6 zł 10 gr, 10 zł.

Automat zaraz po uruchomieniu prezentuje listę dostępnych napoi (nazwy i liczby sztuk)
wraz z cenami.

Napoje reprezentowane są jako obiekty klasy “Napój” z polami “ID”, “nazwa” oraz “cena”.
Po wybraniu napoju użytkownik jest proszony o wrzucenie monety. Program odczytuje
liczbę z wejścia i traktuje ją jako nominał (np. 10 -- 10 gr, 2 -- 2 zł). Wrzucona moneta
zostaje odjęta od ceny do zapłacenia przez użytkownika. Jeśli nominał jest większy od
kwoty jaka pozostaje do zapłaty, użytkownik musi wrzucić mniejszy nominał.

Po wrzuceniu całej kwoty do zapłaty liczba napojów danego rodzaju jest zmniejszana o
1 a użytkownik ma możliwość kupienia kolejnego napoju.

Jeśli napój się skończył użytkownik nie może go kupić i musi wybrać inny.

Liczby napoi przechowywane są w prywatnej tablicy w klasie reprezentującej automat.
Klasa ta ma ponadto publiczne metody:

    a. wypisz odstępne ilości napoi i ich ceny,
    b. wybierz napój
    c. wrzuć monetę (zmniejsza kwotę do zapłaty; zwraca true jeśli nominał jest
    mniejszy od ceny pozostającej do zapłaty i false w przeciwnym przypadku).
    d. sprawdź czy cena została zapłacona.

## Etap 2

Dodajemy nowe sposoby płatności - Karta i BLIK, które dziedziczą po klasie Płatność. Automat
może posiadać jedna, dwie lub wszystkie 3 metody płatności. 

Po wybraniu napoju, użytkownik decyduje się na sposób płatności. Płatność oferuje metodę ’zapłać’, która w odpowiedni sposób
realizuje zapłatę. Metoda ta jest wywołana przez automat po wyborze sposobu płatności i
przyjmuje kwotę, którą winien jest użytkownik, a zwraca status transakcji.