#include "Scena.hh"

void Scena::Zmien_AktywnyLazik(int NumerLazika)
{
  std::list<std::shared_ptr<ObiektGeom>>::iterator Iter = (this->ObiektySceny).begin();
        
  for ( int i = 0; i < NumerLazika; ++i) {++Iter;} 
        
  ObiektGeom *Temp2 = (*Iter).get();
  Lazik *Temp = new Lazik();
  Temp = static_cast<Lazik*>(Temp2);
  (this->AktywnyLazik).reset(Temp);
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

int Scena::LiczbaKlatekTranslacja () {
  return ceil (fabs(this->AktywnyLazik->Wez_OdlegloscDoPrzejechania())/fabs(this->AktywnyLazik->Wez_Szybkosc()))*STALA_ANIMACJI_TRANSLACJA;
}

void Scena::AnimacjaTranslacji()
{
  int LiczbaKlatek = this->LiczbaKlatekTranslacja();
  double Odleglosc_Klatka = (fabs(this->AktywnyLazik->Wez_OdlegloscDoPrzejechania()))/LiczbaKlatek;

  for ( int i = 0; i < LiczbaKlatek; ++i)
  {
    this->AktywnyLazik->Zmien_OdlegloscDoPrzejechania(Odleglosc_Klatka);
    this->AktywnyLazik->TranslacjaLazika();
    this->AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki();
    (this->Lacze).Rysuj();
  }
}

int Scena::LiczbaKlatekRotacji(){
  return ceill (fabs(this->AktywnyLazik->Wez_KatDoObrotuSt())/fabs(this->AktywnyLazik->Wez_PredkoscObrotu()))*STALA_ANIMACJI_ROTACJA;
}

void Scena::AnimacjaObrotu()
{
  int LiczbaKlatek = LiczbaKlatekRotacji();
  double Kat_Klatka = (fabs(this->AktywnyLazik->Wez_KatDoObrotuSt()))/LiczbaKlatek;

  for (int i = 0; i < LiczbaKlatek; ++i)
  {
    this->AktywnyLazik->Zmien_KatDoObrotuSt(Kat_Klatka);
    this->AktywnyLazik->ObrotLazika();
    std::cout<<this->AktywnyLazik->Wez_KatOrientacjiSt()<<std::endl;
    this->AktywnyLazik->Przelicz_i_Zapisz_Wierzcholki();
    (this->Lacze).Rysuj();
  }
}