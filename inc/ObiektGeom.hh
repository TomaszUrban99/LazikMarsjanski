#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3D.hh"

class ObiektGeom{

    int KolorID;
    
    double KatOrientacjiSt;
    
    Wektor3D Polozenie;
    Wektor3D Skala;

    Macierz3D MacierzRotacji;
    
    std::string NazwaObiektu;
    std::string NazwaPliku_BrylaWzorcowa;
    std::string NazwaPliku_PlikDoRysowania;

    public:

    ObiektGeom () = default;

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
   ObiektGeom( int Kolor, double PoczatkowyKatOrientacjiSt, 
                Wektor3D& PoczatkowePolozenie, Wektor3D& NowaSkala,
                std::string NowaNazwaObiektu, std::string PlikWzorcowy, 
                std::string PlikDoRysowania)
   {
       this->KolorID = Kolor;
       this->KatOrientacjiSt = PoczatkowyKatOrientacjiSt;
       this->MacierzRotacji = (this->MacierzRotacji).MacierzRotacjiZ(PoczatkowyKatOrientacjiSt);
       this->Polozenie = PoczatkowePolozenie;
       this->Skala = NowaSkala;
       this->NazwaObiektu = NowaNazwaObiektu;
       this->NazwaPliku_BrylaWzorcowa = PlikWzorcowy;
       this->NazwaPliku_PlikDoRysowania = PlikDoRysowania; 
   }
   
   /*!
    \brief Metoda umożliwiająca zmianę identyfikatora określającego kolor
    wyświetlanego obiektu.
   */
   void Zmien_KolorID (int NowyKolor) {this->KolorID = NowyKolor;}

    /*!
        \brief Metoda umożliwiająca zmianę wektora określającego położenie obiektu.
        \param Wektor3D& NowePolozenie - referencja do wektora przechowujące współrzędne
        nowego położenia.
        \retval BRAK
    */
    void ZmienPolozenie (Wektor3D& NowePolozenie) {this->Polozenie = NowePolozenie;}

    /*!
        \brief Metoda umożliwiająca zmianę kąta orientacji obiektu geometrycznego
        \param double NowyKatSt - zmienna przechowująca wartość nowego kąta orientacji
        \retval BRAK
    */
    void ZmienKatOrientacjiSt (double NowyKatSt) {
        this->KatOrientacjiSt = NowyKatSt;
        ZmienMacierzRotacji(this->KatOrientacjiSt);
    }

    /*!
        \brief Metoda umożliwiająca zmianę wektora określającego skalę wyświetlania obiektów.
        \param Wektor3D& NowePolozenie - referencja do wektora przechowujące współrzędne
        nowego położenia.
        \retval BRAK
    */
    void ZmienSkale (Wektor3D& NowaSkala) {this->Skala = NowaSkala;}

    void ZmienMacierzRotacji(double AngleSt) { this->MacierzRotacji = this->MacierzRotacji.MacierzRotacjiZ(AngleSt);}

    void ZmienMacierzRotacji (Macierz3D& NowaMacierzRotacji) {this->MacierzRotacji = NowaMacierzRotacji;}

    void ZmienNazwaObiektu (std::string NowaNazwaObiektu) {this->NazwaObiektu = NowaNazwaObiektu;}

    void ZmienNazwaPliku_BrylaWzorcowa (std::string NowaNazwaPliku){this->NazwaPliku_BrylaWzorcowa = NowaNazwaPliku;}

    void ZmienNazwaPliku_PlikDoRysowania (std::string NowaNazwaPliku){this->NazwaPliku_PlikDoRysowania = NowaNazwaPliku;}
    
    int Wez_KolorID() const {return this->KolorID;} 
    
    double Wez_KatOrientacjiSt() const {return this->KatOrientacjiSt;}

    double& Wez_KatOrientacjiSt() {return this->KatOrientacjiSt;}

    Wektor3D Wez_Polozenie() const {return this->Polozenie;}

    Wektor3D& Wez_Polozenie() {return this->Polozenie;} 

    Wektor3D Wez_Skale() const {return this->Skala;}

    Wektor3D& Wez_Skale() {return this->Skala;}
    
    Macierz3D Wez_MacierzRotacji() const {return this->MacierzRotacji;}

    Macierz3D& Wez_MacierzRotacji() {return this->MacierzRotacji;}

    std::string Wez_NazwaObiektu() const {return this->NazwaObiektu;}

    std::string& Wez_NazwaObiektu() {return this->NazwaObiektu;}

    std::string Wez_NazwaPlikBrylaWzorcowa () const {return this->NazwaPliku_BrylaWzorcowa;}

    std::string& Wez_NazwaPlikBrylaWzorcowa () {return this->NazwaPliku_BrylaWzorcowa;}

    std::string Wez_NazwaPlikDoRysowania () const {return this->NazwaPliku_PlikDoRysowania;} 

    std::string& Wez_NazwaPlikDoRysowania () {return this->NazwaPliku_PlikDoRysowania;} 

    bool Przelicz_i_Zapisz_Wierzcholki ();

    bool Przelicz_i_Zapisz_Wierzcholki (std::istream& Input, std::ostream& Output);  
};

std::ostream& operator<<(std::ostream& Output, ObiektGeom& DanyLazik);

#endif
