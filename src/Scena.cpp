#include "Scena.hh"

void Scena::Zmien_AktywnyLazik(int NumerLazika)
{
  
  std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = (this->ObiektySceny).begin();
        
  for ( int i = 0; i < NumerLazika; ++i) {++Iter;} 

  this->AktywnyLazik = std::static_pointer_cast<Lazik>(*Iter);
}

bool Scena::Kolizja_SprawdzLaziki()
{
  std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = (this->ObiektySceny.begin());
  
  for (long unsigned int i = 0; i < (this->ObiektySceny.size()); ++i)
  {
    std::shared_ptr<Lazik> TempLazik = std::static_pointer_cast<Lazik>(*Iter);
    if( this->AktywnyLazik != TempLazik){
      if(this->AktywnyLazik->CzyKolizja(TempLazik) == TK_Kolizja) return true;
    }
    ++Iter;
  }

  return false;
}

void Scena::Inicjalizuj_Lacze()
{
  this->Lacze.ZmienTrybRys(PzG::TR_3D);
  this->Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  this->Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  this->Lacze.UstawZakresZ(-0, 90);  
  this->Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  this->Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
}

void Scena::DodajDoListyRysowania()
{
  std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = (this->ObiektySceny).begin();
  PzG::InfoPlikuDoRysowania *wInfoPliku;

   while ( Iter != (this->ObiektySceny).end())
  {
      wInfoPliku =&(this->Lacze.DodajNazwePliku((*Iter)->Wez_NazwaPlikDoRysowania()));
      (wInfoPliku)->ZmienKolor((*Iter)->Wez_KolorID());
      ++Iter;
  }
 
}

int Scena::LiczbaKlatekTranslacja () const {
  return ceil (fabs(this->AktywnyLazik->Wez_OdlegloscDoPrzejechania())/fabs(this->AktywnyLazik->Wez_Szybkosc()))*STALA_ANIMACJI_TRANSLACJA;
}

bool Scena::AnimacjaTranslacji()
{
  int LiczbaKlatek = this->LiczbaKlatekTranslacja();
  double Odleglosc_Klatka = ((this->AktywnyLazik->Wez_OdlegloscDoPrzejechania()))/LiczbaKlatek;

  for ( int i = 0; i < LiczbaKlatek; ++i)
  {
    this->AktywnyLazik->Zmien_OdlegloscDoPrzejechania(Odleglosc_Klatka);
    this->AktywnyLazik->TranslacjaLazika();
    
    if(this->Kolizja_SprawdzLaziki()){

      (this->Lacze).Rysuj();
      return false;
    }
    this->AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki();
    (this->Lacze).Rysuj();
  }

  return true;
}

void Scena::DodajDoListyObiektow (Lazik& Ob1){
  std::shared_ptr<ObiektGeom> Wsk = std::make_shared<Lazik>();
  *Wsk = Ob1;
  (this->ObiektySceny).push_back(Wsk);
}

void Scena::DodajDoListyObiektow (ProbkaRegolitu& Ob1){
  std::shared_ptr<ObiektGeom> Wsk = std::make_shared<ProbkaRegolitu>();
  *Wsk = Ob1;
  (this->ObiektySceny).push_back(Wsk);
}

int Scena::LiczbaKlatekRotacji(double KatDoObrotuSt, double PredkoscObrotu){
  return ceil (fabs(KatDoObrotuSt)/fabs(PredkoscObrotu))*STALA_ANIMACJI_ROTACJA;
}

void Scena::AnimacjaObrotu(double KatDoObrotuSt, double PredkoscObrotu)
{
  int LiczbaKlatek = this->LiczbaKlatekRotacji(KatDoObrotuSt, PredkoscObrotu);
  double Kat_Klatka = (fabs(KatDoObrotuSt))/LiczbaKlatek;

  for (int i = 0; i < LiczbaKlatek; ++i)
  {
    this->AktywnyLazik->ObrotLazika(Kat_Klatka, PredkoscObrotu);
    this->AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki();
    (this->Lacze).Rysuj();
  }
}

std::list<std::shared_ptr<ProbkaRegolitu>> Scena::Wyswietl_Laziki()
{
  std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = this->Wez_Liste().begin();
    // inicjalizacjia Iteratora umożliwiającego poruszanie się po liście
  std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;
    // lista zawierajaca wylacznie obiekty typu ProbkaRegolitu
  std::shared_ptr<ProbkaRegolitu> TempProbka;
      
      while (Iter != this->Wez_Liste().end())
      {
        if ((*Iter)->Obiekt_ID() == ID_ProbkaRegolitu)
        {
          TempProbka = std::static_pointer_cast<ProbkaRegolitu>(*Iter);
          ListaProbek.push_back(TempProbka);
        } 
        ++Iter;
      }
  
  return ListaProbek;
}

std::ostream& operator<< (std::ostream& Output, std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek)
{
    int i = 0;
        // zmienna pomocnicza do zliczania probek
    
    if (ListaProbek.size() == 0)
        Output << "Brak probek" << std::endl;
    else
    {
        Output << "Lista probek: " << std::endl;
        std::list<std::shared_ptr<ProbkaRegolitu>>::iterator Iter = ListaProbek.begin();

        while (Iter != ListaProbek.end())
        {
          ++i;
          Output << "Probka " << i << ": " << (**Iter);
          ++Iter;
        } 
    }

    return Output;
}