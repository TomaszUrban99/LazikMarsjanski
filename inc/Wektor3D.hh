#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "SWektor.hh"
#include "rozmiar.h"

/*!
    \brief Klasa modelująca pojęcie trójwymiarowego wektora.

    Klasa Wektor3D jest klasą pochodną klasy powstałej z szablonu SWektor zdefiniowanego
    w pliku nagłówkowym SWektor.hh.

    Atrybuty klasy Wektor3D:

    #1 tablica wartości typu double o rozmiarze równym stałej ROZMIAR z pliku
    nagłówkowego "rozmiar.h"

    #2 static int Count - zmienna statyczna przechowująca liczbę powstałych 
    obiektów klasy Wektor3D

    #3 static int CurrentCount - zmienna statyczna przechowująca liczbę aktualnie istniejących
    obiektów klasy Wektor3D

*/
class Wektor3D : public SWektor<double, ROZMIAR> {

    static int Count;
    static int Current_Count;

    public:

    Wektor3D()
    {
        ++Count;
        ++Current_Count;
    }

    ~Wektor3D()
    {
        --Current_Count;
    }

    int getCount(){return Count;}

    int getCurrentCount(){return Current_Count;}

};

#endif