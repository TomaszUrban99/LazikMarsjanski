#include <iostream>
#include <fstream>
#include "Wektor3D.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
    Wektor3D Collere;

    ifstream Input("Wektorek.txt");

    Input >> Collere;

    for (int i = 0; i < ROZMIAR; ++i)
    {
        Input>>Collere;
    }

    cout << "Wektorek: " << Collere << endl;

    cout << "Liczba powstałych obiektów: "<<Collere.getCount()<<endl;
    cout << "Liczba aktualnie powstałych obiektów: "<<Collere.getCurrentCount()<<endl;

    return 0;    
}