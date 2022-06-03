#include "ObiektGeom.hh"

void ObiektGeom::Znajdz_GornyPrawy(Wektor3D& WektorWspolrzednych)
{
    if(WektorWspolrzednych[0] > ((this->Obrys.Wez_Wierz_GornyPrawy())[0]))
        {(this->Obrys.Wez_Wierz_GornyPrawy()[0]) = WektorWspolrzednych[0];}
    
    if (WektorWspolrzednych[1] > ((this->Obrys.Wez_Wierz_GornyPrawy())[1]))
        {(this->Obrys.Wez_Wierz_GornyPrawy()[1]) = WektorWspolrzednych[1];}
}

void ObiektGeom::Znajdz_DolnyLewy(Wektor3D& WektorWspolrzednych)
{

    if(WektorWspolrzednych[0] < ((this->Obrys.Wez_Wierz_DolnyLewy())[0]))
        {(this->Obrys.Wez_Wierz_DolnyLewy()[0]) = WektorWspolrzednych[0];}
    
    if(WektorWspolrzednych[1] < (this->Obrys.Wez_Wierz_DolnyLewy()[1]))
        {(this->Obrys.Wez_Wierz_DolnyLewy()[1]) = WektorWspolrzednych[1];}

}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
    std::ifstream Input((*this).NazwaPliku_BrylaWzorcowa);
    if(Input.fail()){ return false; }

    std::ofstream Output((*this).NazwaPliku_PlikDoRysowania);
    if(Output.fail()){return false;}

    if(!Przelicz_i_Zapisz_Wierzcholki(Input, Output)) return false;

    return true;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::istream& Input, std::ostream& Output)
{
    int IndeksWiersza = ZERO;
    Wektor3D WspWierz;

    do 
    {
        Input>>WspWierz;
        if(!Input.fail())
        {
            WspWierz = (this->MacierzRotacji)*((this->Skala)*WspWierz) +(this->Polozenie);
            
            this->Znajdz_DolnyLewy(WspWierz);
            this->Znajdz_GornyPrawy(WspWierz);
            
            Output << WspWierz << std::endl;
            if(Output.fail()) {return false;}
            
            ++IndeksWiersza;
            if (IndeksWiersza%4 == 0){ Output << std::endl;}
        }
        
    }while(!Input.fail());

    if(!Input.eof()){return false;}
     
    return true;
}

std::ostream& operator<<(std::ostream& Output, ObiektGeom& DanyLazik)
{
    Output << "Nazwa Lazika: " << DanyLazik.Wez_NazwaObiektu() << std::endl;
    Output << "Polozenie lazika: " << DanyLazik.Wez_Polozenie() << std::endl;
    Output << "Kat orientacji lazika [st]: " << DanyLazik.Wez_KatOrientacjiSt() << std::endl;

    return Output;
}