#ifndef MACIERZ3D_HH
#define MACIERZ3D_HH

#include <cmath>
#include "OperacjeMat.hh"
#include "SMacierz.hh"

using Wektor = SWektor<double, ROZMIAR>;

constexpr int ZERO = 0;
constexpr int JEDEN = 1;
constexpr int DWA = 2;

/*!
    \brief Klasa modelująca pojęcie macierzy trójwymiarowej.

    Klasa Macierz3D dziedziczy z klasy SMacierz zdefiniowanej w pliku nagłówkowym
    SMacierz.hh.

*/
class Macierz3D : public SMacierz<Wektor, double, ROZMIAR>{
    
    public:

    /*!
        \brief Metoda zwracająca macierz rotacji wokół osi Z w kartezjańskim
        układzie współrzędnych

        \param double AngleSt - wartość kąta wyrażona w stopniach, dla którego
        ma zostać wyznaczona macierz rotacji

        \retval Macierz rotacji dla obrotu wokół osi Z.
    */
    Macierz3D MacierzRotacjiZ (double AngleSt);
};

#endif