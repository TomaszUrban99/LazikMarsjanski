#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include "ObiektGeom.hh"

class ProbkaRegolitu: public ObiektGeom{

    public:

    ProbkaRegolitu () = default;

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
  ProbkaRegolitu( int Kolor, double PoczatkowyKatOrientacjiSt, 
                Wektor3D& PoczatkowePolozenie, Wektor3D& NowaSkala,
                const std::string NowaNazwaObiektu, const std::string PlikWzorcowy, 
                const std::string PlikDoRysowania)
   {
       this->Zmien_KolorID(Kolor);
       this->ZmienKatOrientacjiSt(PoczatkowyKatOrientacjiSt);
       this->ZmienMacierzRotacji(PoczatkowyKatOrientacjiSt);
       this->ZmienPolozenie(PoczatkowePolozenie);
       this->ZmienSkale(NowaSkala);
       this->ZmienNazwaObiektu(NowaNazwaObiektu);
       this->ZmienNazwaPliku_BrylaWzorcowa(PlikWzorcowy);
       this->ZmienNazwaPliku_PlikDoRysowania(PlikDoRysowania);
   }

    /*!
        \brief Metoda zwracająca identyfikator obiektu
        \retval enum TypObiektu - identyfikator charakteryzujący próbkę regolitu
    */
    virtual enum TypObiektu Obiekt_ID () const override {return ID_ProbkaRegolitu;}
};

std::ostream& operator<<(std::ostream& Output, const ProbkaRegolitu Probka);

#endif