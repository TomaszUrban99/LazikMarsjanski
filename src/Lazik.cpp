#include "Lazik.hh"

enum TypKolizji Lazik::CzyKolizja (const std::shared_ptr<Lazik>& Wsk_Lazik) const
{
    if(this->Wez_ObrysXY().PrzeciecieObrysu_Przod((Wsk_Lazik)->Wez_ObrysXY())) return TK_Kolizja;
    if(Wez_ObrysXY().PrzeciecieObrysu_Tyl((Wsk_Lazik)->Wez_ObrysXY())) return TK_Kolizja;
    
    return TK_BrakKolizji;
}

void Lazik::TranslacjaLazika() //dynamic pointer cast - po tym trzeba sprawdzic
{
    double KatRadiany = StopnieNaRadiany(this->Wez_KatOrientacjiSt());

    Wektor3D PrzemieszczenieXY (Znak(this->Szybkosc)*(this->OdlegloscDoPrzejechania)*cos(KatRadiany),
                    Znak(this->Szybkosc)*(this->OdlegloscDoPrzejechania)*sin(KatRadiany), 0);
    
    /*this->Wez_ObrysXY().TranslacjaObrysu(PrzemieszczenieXY[0], PrzemieszczenieXY[1]);*/

    Wektor3D NowePolozenie ( (this->Wez_Polozenie())[0]+PrzemieszczenieXY[0],
                    (this->Wez_Polozenie())[1]+PrzemieszczenieXY[1], 0);

    this->ZmienPolozenie(NowePolozenie);
    this->Zmien_OdlegloscDoPrzejechania(ZERO);
}

void Lazik::ObrotLazika(double KatDoObrotuSt, double PredkoscObrotu)
{
    double Temp = 0;
    
    Temp = (this->Wez_KatOrientacjiSt())+Znak(PredkoscObrotu)*KatDoObrotuSt;
    this->ZmienKatOrientacjiSt(fmod(Temp, KAT_PELNY));
    this->ZmienMacierzRotacji(this->Wez_KatOrientacjiSt());
}