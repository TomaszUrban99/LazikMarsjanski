#ifndef LAZIK_HH
#define LAZIK_HH

#include "ObiektGeom.hh"

class Lazik: public ObiektGeom{

    double OdlegloscDoPrzejechania = 0;
    double Szybkosc = 0;
    double KatDoObrotuSt = 0;
    double PredkoscObrotu = 0;

    public:

    /*!
        \brief Kontruktor parametryczny obiektu klasy ObiektGeom.
        \param int Kolor - numer identyfikacyjny koloru w jakim ma
        być wyświetlany obiekt
        \param double PoczatkowyKatOrientacjiSt - początkowy kąt orientacji
        obiektu na planszy
        \param Wektor3D& PocztkowePolozenie - poczatkowe polozenie obiektu
        \param Wektor3D& NowaSkala - skala z jaką ma być wyświetlany obiekt
        \param std::string NowaNazwaObiektu - nazwa tworzonego obiektu
        \param std::string PlikWzorcowy - nazwa pliku wraz z ścieżką, z którego będą 
        brane współrzędne wzorcowej bryły
        \param std::string PlikDoRysowania - nazwa pliku, do którego będą zapisywane
        wyliczone współrzędne
    */
   Lazik(int Kolor, double PoczatkowyKatOrientacjiSt, 
                Wektor3D& PoczatkowePolozenie, Wektor3D& NowaSkala,
                std::string NowaNazwaObiektu, std::string PlikWzorcowy, 
                std::string PlikDoRysowania)
   {
       this->Zmien_KolorID(Kolor);
       this->ZmienKatOrientacjiSt(PoczatkowyKatOrientacjiSt);
       this->ZmienMacierzRotacji(PoczatkowyKatOrientacjiSt);
       this->ZmienPolozenie(PoczatkowePolozenie);
       this->ZmienSkale(NowaSkala);
       this->ZmienNazwaObiektu (NowaNazwaObiektu);
       this->ZmienNazwaPliku_BrylaWzorcowa(PlikWzorcowy);
       this->ZmienNazwaPliku_PlikDoRysowania(PlikDoRysowania); 
   }


};

#endif