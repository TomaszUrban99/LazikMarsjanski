#include "ObiektGeom.hh"

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
    std::ifstream Input(this->NazwaPliku_BrylaWzorcowa);
    if(Input.fail()) return false;

    std::ofstream Output(this->NazwaPliku_PlikDoRysowania);
    if(Output.fail()) return false;

    if(!Przelicz_i_Zapisz_Wierzcholki(Input, Output)) return false;
    
    Input.close();
    Output.close();

    return true;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki(std::istream& Input, std::ostream& Output)
{
    int IndeksWiersza = ZERO;
    Wektor3D WspWierz;

    do 
    {
        Input>>WspWierz;
        if(Input.fail()) return false;

        WspWierz = (this->MacierzRotacji)*((this->Skala)*WspWierz)+(this->Polozenie);
        Output << WspWierz << std::endl;
        if(Output.fail()) return false;
        ++IndeksWiersza;

        if (IndeksWiersza%4 == 0){ Output << std::endl;}
        
    }while(!Input.fail());

    if(!Input.eof()) return false;
    return true;
}