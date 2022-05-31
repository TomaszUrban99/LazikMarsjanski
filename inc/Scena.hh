#ifndef SCENA_HH
#define SCENA_HH

#include <memory>
#include <list>
#include <cmath>
#include "Lazik.hh"
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"

constexpr int STALA_ANIMACJI_TRANSLACJA = 1000;
constexpr int STALA_ANIMACJI_ROTACJA = 10;

class Scena{

    std::shared_ptr<Lazik> AktywnyLazik;
    std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;
    PzG::LaczeDoGNUPlota Lacze;

    public:

    /*!
        \brief Konstruktor parametryczny klasy Scena
        \param Lazik& PocztkowyAktywnyLazik - referencja do obiektu klasy
        Lazik, ktory bedzie pierwszym aktywnym lazikiem na scenie
    */
    Scena (Lazik& PocztkowyAktywnyLazik){
        this->AktywnyLazik = std::make_shared<Lazik>(PocztkowyAktywnyLazik);
    }

    /*!
        \brief Metoda umożliwiająca wybór aktywnego łazika.

        W pierwszej kolejności definiowany jest iterator dla listy ObiektySceny. Następnie
        w pętli for wyszukiwany jest lazik znajdujacy się na miejscu określonym przez parametr
        int NumerLazika. Następnie dla konkretnej wartości iteratora pozyskiwana jest referencja
        do obiektu. Obiekt jest konwertowany z typu ObiektGeom do typu Lazik.

        \param int NumerLazika - numer łazika na liście ObiektySceny
        \retval BRAK;
    */
    void Zmien_AktywnyLazik(int NumerLazika);

    /*!
        \brief Metoda umożliwiająca zmianę łącza do programu GNUPLOT
        \param PzG::LaczeDoGNUPlota& Nowe Lacze - referencja do łącza programu GNUPlot.
        \retval BRAK
    */
    void Zmien_Lacze(PzG::LaczeDoGNUPlota& NoweLacze) {this->Lacze = NoweLacze;}

    /*!
        \brief Metoda umożliwiająca zmianę listy obiektów klasy ObiektGeom znajdujących się
        na scenie.
    */
    void ZmienListe(std::list<std::shared_ptr<ObiektGeom>> NowaLista){this->ObiektySceny = NowaLista;}

    void DodajDoListyObiektow (ObiektGeom& Ob1);

    std::shared_ptr<Lazik> Wez_AktywnyLazik () {return this->AktywnyLazik;}
    
    std::list<std::shared_ptr<ObiektGeom>> Wez_Liste () const {return this->ObiektySceny;}

    std::list<std::shared_ptr<ObiektGeom>>& Wez_Liste () {return this->ObiektySceny;}

    PzG::LaczeDoGNUPlota& Wez_Lacze () {return this->Lacze;}

    /*!
        \brief Inicjalizuje połączenie z programem gnuplot oraz rozmiar świata.
        
        Inicjalizuje podstawowe parametry "swiata", tzn. jego wymiary,
        które będą widoczne jako obszar objęty układem współrzędnych.
        Następnie w tle uruchamiany jest program gnuplot.
        \param[in] rLacze - nieaktywne łącze do gnuplota.
    */
   void Inicjalizuj_Lacze();
   
   void DodajDoListyRysowania();

   int LiczbaKlatekTranslacja ();

   void AnimacjaTranslacji ();

   int LiczbaKlatekRotacji ();

   void AnimacjaObrotu ();

};

#endif