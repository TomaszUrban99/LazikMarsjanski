#include <iostream>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
   

    ifstream Input("Wektorek.txt");
    
    Wektor3D Collere;
    Wektor3D Gender;
    double Kat = 60;
    Macierz3D Tusk;

    Input>>Collere;
    cout << "Wektorek: " << Collere << endl;
    Input>>Gender;
    cout << "Genderek: " << Gender << endl;

    cout << "Wynik mnozenia: " << (Collere * Gender) << endl;

    cout << "Macierz rotacji: " << endl;
    Tusk = Tusk.MacierzRotacjiZ(Kat);

    cout << "Wynik mnozenia skalarnego: " << endl;
    cout << Tusk * Collere << endl;

    cout << "Liczba powstałych obiektów: "<<Collere.getCount()<<endl;
    cout << "Liczba aktualnie powstałych obiektów: "<<Collere.getCurrentCount()<<endl;


    

    return 0;    
}