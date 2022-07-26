#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include <fstream>
#include <memory>
#include "Wektor3D.hh"
#include "ObrysXY.hh"
#include "Macierz3D.hh"

class Lazik;

/*!
    \brief Typ wyliczeniowy TypObiektu definiujący możliwe rodzaje obiektow
    znajdujacych się na scenie.
*/
enum TypObiektu { ID_ObiektGeom, ID_Lazik, ID_LazikSFR, ID_ProbkaRegolitu};

/*!
    \brief Typ wyliczeniowy TypKolizji definiujący możliwe rodzaje kolizji
    zachodzące pomiędzy obiektami klas pochodnych klasy ObiektGeom
*/
enum TypKolizji { TK_BrakKolizji, TK_PrzejazdNadProbka, TK_Kolizja };

class ObiektGeom{

    int KolorID;
    
    double KatOrientacjiSt;
    double SzerokoscObiektu;
    
    Wektor3D Polozenie;
    Wektor3D Skala;

    Macierz3D MacierzRotacji;
    
    std::string NazwaObiektu;
    std::string NazwaPliku_BrylaWzorcowa;
    std::string NazwaPliku_PlikDoRysowania;

    ObrysXY Obrys;
    
    public:

    ObiektGeom() = default;

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
                const std::string NowaNazwaObiektu, const std::string PlikWzorcowy, 
                const std::string PlikDoRysowania)
   {
       KolorID = Kolor;
       KatOrientacjiSt = PoczatkowyKatOrientacjiSt;
       MacierzRotacji = (this->MacierzRotacji).MacierzRotacjiZ(PoczatkowyKatOrientacjiSt);
       Polozenie = PoczatkowePolozenie;
       Skala = NowaSkala;
       NazwaObiektu = NowaNazwaObiektu;
       NazwaPliku_BrylaWzorcowa = PlikWzorcowy;
       NazwaPliku_PlikDoRysowania = PlikDoRysowania;
       SzerokoscObiektu = 0;
   }

   ObiektGeom(const ObiektGeom&) = default;

   virtual enum TypObiektu Obiekt_ID () const = 0;

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

    void ZmienNazwaObiektu (const std::string NowaNazwaObiektu) {this->NazwaObiektu = NowaNazwaObiektu;}

    void ZmienNazwaPliku_BrylaWzorcowa (const std::string NowaNazwaPliku){
        (this->NazwaPliku_BrylaWzorcowa) = NowaNazwaPliku;}

    void ZmienNazwaPliku_PlikDoRysowania (const std::string NowaNazwaPliku){(this->NazwaPliku_PlikDoRysowania) = NowaNazwaPliku;}
    
    int Wez_KolorID() const {return this->KolorID;} 
    
    double Wez_KatOrientacjiSt() const {return this->KatOrientacjiSt;}

    double& Wez_KatOrientacjiSt() {return this->KatOrientacjiSt;}

    double Wez_SzerokoscObiektu () const {return SzerokoscObiektu;}

    double& Wez_SzerokoscObiektu () {return SzerokoscObiektu;}

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

    ObrysXY& Wez_ObrysXY () {return this->Obrys;}

    ObrysXY Wez_ObrysXY () const {return this->Obrys;}

    void Znajdz_DolnyLewy (Wektor3D& WektorWspolrzednych);

    void Znajdz_GornyPrawy (Wektor3D& WektorWspolrzednych);

    bool WyznaczObrysObiektu ();

    bool Przelicz_i_Zapisz_Wierzcholki ();

    bool Przelicz_i_Zapisz_Wierzcholki (std::istream& Input, std::ostream& Output);

    Wektor2D KonwersjaNaDwuwymiarowy(Wektor3D& Wektor2) const;

    bool WyliczSzerokosc_Obiektu ();

    virtual enum TypKolizji CzyKolizja ( const std::shared_ptr<Lazik>& Wsk_Lazik ) const = 0;
};

std::ostream& operator<<(std::ostream& Output, ObiektGeom& DanyLazik);

#endif
