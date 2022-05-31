#ifndef SCENA_HH
#define SCENA_HH

#include <memory>
#include <list>
#include "Lazik.hh"
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"

class Scena{

    std::shared_ptr<Lazik> AktywnyLazik;
    std::list<std::shared_ptr<ObiektGeom>> ObiektySceny;
    PzG::LaczeDoGNUPlota Lacze;

    public:

    Scena (Lazik& PocztkowyAktywnyLazik)
    {
        this->AktywnyLazik = std::make_shared<Lazik>(PocztkowyAktywnyLazik);
    }

    void Zmien_AktywnyLazik(int NumerLazika) {
        std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = (this->ObiektySceny).begin();
        
        for ( int i = 0; i < NumerLazika; ++i) {++Iter;} 
        
        ObiektGeom *Temp2 = (*Iter).get();
        Lazik *Temp = new Lazik();
        Temp = static_cast<Lazik*>(Temp2);
        (this->AktywnyLazik).reset(Temp);
    }

    void Zmien_Lacze(PzG::LaczeDoGNUPlota& NoweLacze) {this->Lacze = NoweLacze;}

    void ZmienListe(std::list<std::shared_ptr<ObiektGeom>> NowaLista){this->ObiektySceny = NowaLista;}

    void DodajDoListyObiektow (ObiektGeom& Ob1){
        std::shared_ptr<ObiektGeom> Wsk = std::make_shared<ObiektGeom>();
        *Wsk = Ob1;
        (this->ObiektySceny).push_back(Wsk);
    }

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

};

#endif