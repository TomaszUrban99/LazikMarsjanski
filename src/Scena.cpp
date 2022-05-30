#include "Scena.hh"

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