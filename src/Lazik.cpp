#include "Lazik.hh"

void Lazik::TranslacjaLazika()
{
    double KatRadiany = StopnieNaRadiany(this->Wez_KatOrientacjiSt());

    Wektor3D NowePolozenie ( (this->Wez_Polozenie())[0]+Znak(this->Szybkosc)*(this->OdlegloscDoPrzejechania)*cos(KatRadiany),
                    (this->Wez_Polozenie())[1]+Znak(this->Szybkosc)*(this->OdlegloscDoPrzejechania)*sin(KatRadiany), 0);

    this->ZmienPolozenie(NowePolozenie);
    this->Zmien_OdlegloscDoPrzejechania(ZERO);
}

void Lazik::ObrotLazika()
{
    double Temp;
    Temp = (this->Wez_KatOrientacjiSt())+Znak(this->PredkoscObrotu)*(this->KatDoObrotuSt);
    this->ZmienKatOrientacjiSt(fmod(Temp, KAT_PELNY));
    this->ZmienMacierzRotacji(this->Wez_KatOrientacjiSt());
    this->Zmien_KatDoObrotuSt(ZERO); 
}