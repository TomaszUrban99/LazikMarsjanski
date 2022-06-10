#include "ObrysXY.hh"

    bool ObrysXY::PrzeciecieObrysu_Przod (const ObrysXY& Obrys) const
    {
        /* Rozpoczecie sprawdzenia od gornego prawego wierzcholka */
        if( Obrys.Wierz_DolnyLewy[0] <= Wierz_GornyPrawy[0])
            {
                if( Obrys.Wierz_GornyPrawy[0] >= Wierz_GornyPrawy[0] )
                {
                    if( Obrys.Wierz_DolnyLewy[1] <= Wierz_GornyPrawy[1])
                        if( Obrys.Wierz_GornyPrawy[1] >= Wierz_GornyPrawy[1]) return true;
                    
                    if( Obrys.Wierz_DolnyLewy[1] <= Wierz_DolnyLewy[1])
                        if( Obrys.Wierz_GornyPrawy[1] >= Wierz_DolnyLewy[1]) return true;
                }
            }

        return false;
    }

    bool ObrysXY::PrzeciecieObrysu_Tyl (const ObrysXY& Obrys) const
    {
        if( Obrys.Wierz_DolnyLewy[0] <= Wierz_DolnyLewy[0] )
        {
            if( Obrys.Wierz_GornyPrawy[0] >= Wierz_DolnyLewy[0] )
            {
                if( Obrys.Wierz_DolnyLewy[1] <= Wierz_DolnyLewy[1])
                    if( Obrys.Wierz_GornyPrawy[1] >= Wierz_DolnyLewy[1]) return true;
                
                if( Obrys.Wierz_DolnyLewy[1] <= Wierz_GornyPrawy[1])
                    if( Obrys.Wierz_GornyPrawy[1] >= Wierz_GornyPrawy[1]) return true;
            }
        }

        return false;
    }