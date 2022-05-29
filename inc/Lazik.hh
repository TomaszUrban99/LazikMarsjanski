#ifndef LAZIK_HH
#define LAZIK_HH

#include <cmath>
#include "ObiektGeom.hh"
#include "OperacjeMat.hh"

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

   void Zmien_OdlegloscDoPrzejechania(double NowaOdleglosc){
    this->OdlegloscDoPrzejechania = NowaOdleglosc;}
    
    void Zmien_Szybkosc(double NowaSzybkosc){
        this->Szybkosc = NowaSzybkosc;}
    
    void Zmien_KatDoObrotuSt(double NowyKatDoObrotuSt){
        this->KatDoObrotuSt = NowyKatDoObrotuSt;}
    
    void Zmien_PredkoscObrotu(double NowaPredkoscObrotu){
        this->PredkoscObrotu = NowaPredkoscObrotu;}

    double Wez_OdlegloscDoPrzejechania () const {return this->OdlegloscDoPrzejechania;}
    double& Wez_OdlegloscDoPrzejechania () {return this->OdlegloscDoPrzejechania;}

    double Wez_Szybkosc () const {return this->Szybkosc;}
    double& Wez_Szybkosc () {return this->Szybkosc;}

    double Wez_KatDoObrotuSt () const {return this->KatDoObrotuSt;}
    double& Wez_KatDoObrotuSt () {return this->KatDoObrotuSt;}

    double Wez_PredkoscObrotu () const {return this->PredkoscObrotu;}
    double& Wez_PredkoscObrotu () {return this->PredkoscObrotu;} 

   void TranslacjaLazika ();

   void ObrotLazika ();

};

#endif