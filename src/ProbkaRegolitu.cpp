#include "ProbkaRegolitu.hh"

std::ostream& operator<< (std::ostream& Output, const ProbkaRegolitu Probka)
{
    Output << Probka.Wez_NazwaObiektu() << " " << "polozenie: " << Probka.Wez_Polozenie() << std::endl;
    return Output;
}