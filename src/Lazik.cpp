#include "Lazik.hh"

enum TypKolizji Lazik::CzyKolizja (std::shared_ptr<Lazik>& Wsk_Lazik)
{
    if (this->Wez_ObrysXY().Wez_Wierz_GornyPrawy() <= Wsk_Lazik->Wez_ObrysXY().Wez_Wierz_GornyPrawy()){ 
        if (this->Wez_ObrysXY().Wez_Wierz_GornyPrawy() >= Wsk_Lazik->Wez_ObrysXY().Wez_Wierz_DolnyLewy()) return TK_Kolizja;}

    if (this->Wez_ObrysXY().Wez_Wierz_DolnyLewy() <= Wsk_Lazik->Wez_ObrysXY().Wez_Wierz_GornyPrawy()){
        if (this->Wez_ObrysXY().Wez_Wierz_DolnyLewy() >= Wsk_Lazik->Wez_ObrysXY().Wez_Wierz_DolnyLewy()) return TK_Kolizja;}
    
    return TK_BrakKolizji;
}

void Lazik::TranslacjaLazika()
{
    double KatRadiany = StopnieNaRadiany(this->Wez_KatOrientacjiSt());

    Wektor3D PrzemieszczenieXY (Znak(this->Szybkosc)*(this->OdlegloscDoPrzejechania)*cos(KatRadiany),
                    Znak(this->Szybkosc)*(this->OdlegloscDoPrzejechania)*sin(KatRadiany), 0);
    
    this->Wez_ObrysXY().TranslacjaObrysu(PrzemieszczenieXY[0], PrzemieszczenieXY[1]);

    Wektor3D NowePolozenie ( (this->Wez_Polozenie())[0]+PrzemieszczenieXY[0],
                    (this->Wez_Polozenie())[1]+PrzemieszczenieXY[1], 0);

    this->ZmienPolozenie(NowePolozenie);
    this->Zmien_OdlegloscDoPrzejechania(ZERO);
}

void Lazik::ObrotLazika(double KatDoObrotuSt)
{
    double Temp;
    Temp = (this->Wez_KatOrientacjiSt())+Znak(this->PredkoscObrotu)*KatDoObrotuSt;
    this->ZmienKatOrientacjiSt(fmod(Temp, KAT_PELNY));
    this->ZmienMacierzRotacji(this->Wez_KatOrientacjiSt());
}