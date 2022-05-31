#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "Wektor3D.hh"
#include "Scena.hh"

using namespace std;

int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;

int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  Wektor3D PolozenieFSR (0, 0, 0);
  Wektor3D PolozeniePerservance (20, 20, 0);
  Wektor3D PolozenieCuriosity (50, 50, 0);
  Wektor3D Skala (10, 10, 10);

  Lazik Ob1(Kolor_JasnoNiebieski, 0, PolozenieFSR, Skala, "FSR", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/FSR");
  Lazik Ob2(Kolor_JasnoNiebieski, 0, PolozenieCuriosity, Skala, "Curiosity", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Curiosity");
  Lazik Ob3(Kolor_JasnoNiebieski, 0, PolozeniePerservance, Skala, "Perservarance", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Perservarance");
  
  Scena Mars(Ob1);
  
  Mars.Inicjalizuj_Lacze();
  if (!Inicjalizuj_PowierzchnieMarsa(Mars.Wez_Lacze())) return 1;

  Mars.DodajDoListyObiektow(Ob1);
  Mars.DodajDoListyObiektow(Ob2);
  Mars.DodajDoListyObiektow(Ob3);

  Mars.DodajDoListyRysowania();

  int Number;

  cout << "Zmiana aktywnego lazika: " << endl;
  cout << "Podaj numer lazika (0-2)" << endl; // Dopisać makro zabezpieczające!!!
  cin >> Number;

  cout << "Aktywny lazik: " << endl;
  cout << *(Mars.Wez_AktywnyLazik()) << endl;

  Mars.Zmien_AktywnyLazik(Number);

  cout << "Aktywny lazik: " << endl;
  cout << *(Mars.Wez_AktywnyLazik()) << endl;
  
  cout << endl << "Start programu gnuplot" << endl << endl;
  (Mars.Wez_Lacze()).Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  double Temp;

  cout << "Podaj odleglosc" << endl;
  cin >> Temp;
  (Mars.Wez_AktywnyLazik())->Zmien_OdlegloscDoPrzejechania(Temp);
  cout << "Podaj szybkosc" << endl;
  cin >> Temp;
  (Mars.Wez_AktywnyLazik())->Zmien_Szybkosc(Temp);
  Mars.AnimacjaTranslacji();
  cout << "Lazik: " << endl;
  cout << *(Mars.Wez_AktywnyLazik());
  (Mars.Wez_Lacze()).Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
  
  cout << "Podaj kat obrotu" << endl;
  cin >> Temp;
  Ob1.Zmien_KatDoObrotuSt(Temp);
  cout << "Podaj predkosc obrotu" << endl;
  cin >> Temp;
  Ob1.Zmien_PredkoscObrotu(Temp);
  Ob1.ObrotLazika();
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj();

  cout << "Polozenie: " << Ob1.Wez_Polozenie() << endl;
  cout << "Kat orientacji: " << Ob1.Wez_KatOrientacjiSt() << endl;
  
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');

  cout << "Podaj odleglosc" << endl;
  cin >> Temp;
  Ob1.Zmien_OdlegloscDoPrzejechania(Temp);
  cout << "Podaj szybkosc" << endl;
  cin >> Temp;
  Ob1.Zmien_Szybkosc(Temp);
  Ob1.TranslacjaLazika();
  
  
  Ob1.Przelicz_i_Zapisz_Wierzcholki();

  cout << Ob1.Wez_KatOrientacjiSt() << endl;
  cout << Ob1.Wez_Polozenie() << endl;
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

    cout << "Podaj kat obrotu" << endl;
  cin >> Temp;
  Ob1.Zmien_KatDoObrotuSt(Temp);
  cout << "Podaj predkosc obrotu" << endl;
  cin >> Temp;
  Ob1.Zmien_PredkoscObrotu(Temp);
  Ob1.ObrotLazika();
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Lacze.Rysuj();

  cout << "Polozenie: " << Ob1.Wez_Polozenie() << endl;
  cout << "Kat orientacji: " << Ob1.Wez_KatOrientacjiSt() << endl;
  
  cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
  cin.ignore(100,'\n');


  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');
}
