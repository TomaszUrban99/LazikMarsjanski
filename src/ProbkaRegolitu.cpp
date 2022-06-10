#include "ProbkaRegolitu.hh"

enum TypKolizji ProbkaRegolitu::CzyKolizja( const std::shared_ptr<Lazik>& Wsk_Lazik) const
{
    Wektor2D Temp;
    Wektor2D Wersor;
    double Winkel = 0;

    Wersor [0] = cos(StopnieNaRadiany(Wsk_Lazik->Wez_KatOrientacjiSt())); /* pierwsza wspolrzedna wektora kierunkowego */
    Wersor [1] = sin(StopnieNaRadiany(Wsk_Lazik->Wez_KatOrientacjiSt()));


    Temp [0] = (Wez_Polozenie())[0] - (Wsk_Lazik->Wez_Polozenie())[0];
    Temp [1] = (Wez_Polozenie())[1] - (Wsk_Lazik->Wez_Polozenie())[1];

    double Odleglosc = Temp.modul();

    Odleglosc = Odleglosc/acos(((Temp[0]*Wersor[0])+(Temp[1]*Wersor[1]))/Odleglosc);

    if ( (Wsk_Lazik->Wez_SzerokoscObiektu()) * 0,2 > Odleglosc ) return TK_PrzejazdNadProbka;
    else return TK_Kolizja;

}

std::ostream& operator<< (std::ostream& Output, ProbkaRegolitu& Probka)
{
    Output << Probka.Wez_NazwaObiektu() << " " << "polozenie: " << Probka.Wez_Polozenie() << std::endl;
    return Output;
}