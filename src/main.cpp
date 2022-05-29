#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "Wektor3D.hh"



using namespace std;

/*!
 *  \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
 *
 *  Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
 *  które będą widoczne jako obszar objęty układem współrzędnych.
 *  Następnie w tle uruchamiany jest program gnuplot.
 *  \param[in] rLacze - nieaktywne łącze do gnuplota.
 */
void Inicjalizuj_Lacze(PzG::LaczeDoGNUPlota  &rLacze)
{
  rLacze.ZmienTrybRys(PzG::TR_3D);
  rLacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  rLacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  rLacze.UstawZakresZ(-0, 90);  
  rLacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  rLacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}



void DodajDoListyRysowania(PzG::LaczeDoGNUPlota &rLacze, const ObiektGeom  &rOb)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &rLacze.DodajNazwePliku(rOb.Wez_NazwaPlikDoRysowania());
  wInfoPliku->ZmienKolor(rOb.Wez_KolorID());
}


int Wektor3D::Count = 0;
int Wektor3D::Current_Count = 0;
int main()
{
  PzG::LaczeDoGNUPlota  Lacze;
  Wektor3D PolozenieFSR (0, 0, 0);
  Wektor3D PolozeniePerservance (20, 20, 0);
  Wektor3D PolozenieCuriosity (100, 100, 0);
  Wektor3D Skala (10, 10, 10);
  
  Inicjalizuj_Lacze(Lacze);
  if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) return 1;

  Lazik Ob1(Kolor_JasnoNiebieski, 0, PolozenieFSR, Skala, "FSR", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/FSR");
  Lazik Ob2(Kolor_JasnoNiebieski, 0, PolozenieCuriosity, Skala, "Curiosity", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Curiosity");
  Lazik Ob3(Kolor_JasnoNiebieski, 0, PolozeniePerservance, Skala, "Perservarance", "bryly_wzorcowe/szescian3.dat", "pliki_do_rysowania/Perservarance");

  DodajDoListyRysowania(Lacze,Ob1);
  DodajDoListyRysowania(Lacze,Ob2);
  DodajDoListyRysowania(Lacze,Ob3);
  
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
  Ob2.Przelicz_i_Zapisz_Wierzcholki();
  Ob3.Przelicz_i_Zapisz_Wierzcholki();  
  
  cout << endl << "Start programu gnuplot" << endl << endl;
  Lacze.Rysuj();

  cout << "Nacisnij klawisz ENTER, aby FSR wykonal przesuniecie." << endl;
  cin.ignore(100,'\n');

  double Temp;

  cout << "Podaj odleglosc" << endl;
  cin >> Temp;
  Ob1.Zmien_OdlegloscDoPrzejechania(Temp);
  cout << "Podaj szybkosc" << endl;
  cin >> Temp;
  Ob1.Zmien_Szybkosc(Temp);
  Ob1.TranslacjaLazika();
  Ob1.Przelicz_i_Zapisz_Wierzcholki();
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
