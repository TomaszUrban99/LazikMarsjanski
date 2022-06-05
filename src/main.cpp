#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "ProbkaRegolitu.hh"
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
  Wektor3D Skala (20, 20, 10);
  Wektor3D SkalaProbka (5, 5, 2);
  Wektor3D PolozenieProbka1 (-20, -20, 0);
  Wektor3D PolozenieProbka2 (-30, -30, 0);

  char klawisz[2] = "m";

  Lazik Ob1(Kolor_JasnoNiebieski, 0, PolozenieFSR, Skala, "FSR", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/FSR");
  Lazik Ob2(Kolor_JasnoNiebieski, 0, PolozenieCuriosity, Skala, "Curiosity", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Curiosity");
  Lazik Ob3(Kolor_JasnoNiebieski, 0, PolozeniePerservance, Skala, "Perservarance", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Perservarance");
  ProbkaRegolitu Ob4 (Kolor_Czerwony, 0, PolozenieProbka1, SkalaProbka, "Probka1", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka1");
  ProbkaRegolitu Ob5 (Kolor_Czerwony, 0, PolozenieProbka2, SkalaProbka, "Probka1", "bryly_wzorcowe/szescian1.dat", "pliki_do_rysowania/Probka2");

  Scena Mars(Ob1);

  Mars.DodajDoListyObiektow(Ob1);
  Mars.DodajDoListyObiektow(Ob2);
  Mars.DodajDoListyObiektow(Ob3);
  Mars.DodajDoListyObiektow(Ob4);
  Mars.DodajDoListyObiektow(Ob5);
  
  Mars.Inicjalizuj_Lacze();
  if (!Inicjalizuj_PowierzchnieMarsa(Mars.Wez_Lacze())) return 1;

  Mars.DodajDoListyRysowania();
  Mars.Zmien_AktywnyLazik(1);

  list<shared_ptr<ObiektGeom>>::iterator Iter = Mars.Wez_Liste().begin();

  while (Iter != Mars.Wez_Liste().end())
  {
    (**Iter).Przelicz_i_Zapisz_Wierzcholki();
    (**Iter).WyznaczObrysObiektu();
    if((*Iter)->Obiekt_ID() == ID_Lazik )
    {
      cout << "Lazik: " << (**Iter) << endl;
      cout << "Obrys lazikow: " << endl;
      cout << (**Iter).Wez_ObrysXY().Wez_Wierz_DolnyLewy();
      cout << (**Iter).Wez_ObrysXY().Wez_Wierz_GornyPrawy();
    }
    ++Iter;
  }

  cout << endl << "Start programu gnuplot" << endl << endl;
  (Mars.Wez_Lacze()).Rysuj();

  cout << "Nacisnij klawisz ENTER, aby przejsc dalej" << endl;
  cin.ignore(100,'\n');

  while((klawisz[0])!='k')
  {
    double Temp;

    switch(klawisz[0])
    {
      case 'j':
        
        cout << "Aktywny lazik: " << endl;
        cout << *(Mars.Wez_AktywnyLazik()) << endl;
        cout << "Podaj odleglosc" << endl;
        cin >> Temp;
        cout << Mars.Wez_AktywnyLazik()->Wez_NazwaPlikBrylaWzorcowa() << endl;
        cout << Mars.Wez_AktywnyLazik()->Wez_NazwaPlikDoRysowania() << endl;
        (*(Mars.Wez_AktywnyLazik())).Zmien_OdlegloscDoPrzejechania(Temp);
        cout << "Podaj szybkosc" << endl;
        cin >> Temp;
        cout << "Szybkosc pobrana: " << Temp << std::endl;
        (Mars.Wez_AktywnyLazik())->Zmien_Szybkosc(Temp);
        cout << "Plik wzorcowy po zmianie: " << Mars.Wez_AktywnyLazik()->Wez_NazwaPlikBrylaWzorcowa() << endl;
        cout << "Plik do rysowania po zmianie: " << Mars.Wez_AktywnyLazik()->Wez_NazwaPlikDoRysowania() << endl;
        cout << "Szybkosc 2.0: " << Mars.Wez_AktywnyLazik()->Wez_Szybkosc() << std::endl; 
        if(!Mars.AnimacjaTranslacji()) { cout << "Kolizja- ruch zatrzymany" << endl;}
      
        cout << "Nacisnij klawisz ENTER, aby przejść dalej." << endl;
        cin.ignore(100,'\n');
      
      break;

      case 'o':

        double Temp2;

        cout << "Podaj kat obrotu" << endl;
        cin >> Temp;
        cout << "Podaj predkosc obrotu" << endl;
        cin >> Temp2;
        
        cout << "Dolny lewy: " << Mars.Wez_AktywnyLazik()->Wez_ObrysXY().Wez_Wierz_DolnyLewy() << std::endl;
        cout << "Gorny prawy: " << Mars.Wez_AktywnyLazik()->Wez_ObrysXY().Wez_Wierz_GornyPrawy() << std::endl;
        Mars.AnimacjaObrotu(Temp, Temp2);
        cout << "Dolny lewy po rotacji: " << Mars.Wez_AktywnyLazik()->Wez_ObrysXY().Wez_Wierz_DolnyLewy() << std::endl;
        cout << "Gorny prawy po rotacji: " << Mars.Wez_AktywnyLazik()->Wez_ObrysXY().Wez_Wierz_GornyPrawy() << std::endl;

        cout << "Nacisnij klawisz ENTER, aby przejść dalej." << endl;
        cin.ignore(100,'\n');
      
      break;

      case 'm':

        cout << "Menu programu lazik marsjanski" << endl;
        cout << "j - jazda na wprost" << endl;
        cout << "o - obrot lazika" << endl;
        cout << "d - wyswietl aktywny lazik" << endl;
        cout << "s - selekcja lazika" << endl;
        cout << "k - koniec programu" << endl;
      
      break;

      case 'd':

        cout << *(Mars.Wez_AktywnyLazik()) << endl;
      
      break;

      case 's':

        int Numer;
        cout << "Podaj numer lazika, ktory chcesz wybrac" << endl;
        cin >> Numer;
        Mars.Zmien_AktywnyLazik(Numer);
        cout << "Aktywny lazik: " << endl;
        cout << *(Mars.Wez_AktywnyLazik()) << endl;
      
      break;

      default :

        cout << "Nierozpoznana komenda" << endl;
      
      break;
    }

    cout << "Podaj komende (m - wyswietl menu) " << endl;
    cin >> klawisz;
  }

  return 0;
}
