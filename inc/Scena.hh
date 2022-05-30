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

    void Zmien_Lacze(PzG::LaczeDoGNUPlota& NoweLacze) {this->Lacze = NoweLacze;}

    void ZmienListe(std::list<std::shared_ptr<ObiektGeom>> NowaLista){this->ObiektySceny = NowaLista;}

    void DodajDoListyObiektow (ObiektGeom& Ob1){
        std::shared_ptr<ObiektGeom> Wsk = std::make_shared<ObiektGeom>(Ob1);
        (this->ObiektySceny).push_back(Wsk);}
    
    std::list<std::shared_ptr<ObiektGeom>> Wez_Liste () {return this->ObiektySceny;}

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