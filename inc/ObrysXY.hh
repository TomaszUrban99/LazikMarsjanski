#ifndef OBRYSXY_HH
#define OBRYSXY_HH

#include "Wektor2D.hh"

/*!
    \brief Klasa modelująca pojęcie obrysu obiektu.
*/
class ObrysXY{

    Wektor2D Wierz_DolnyLewy;
    Wektor2D Wierz_GornyPrawy;

    public:

    /*__________________Metody dostepu____________________*/
    
    void Zmien_Wierz_DolnyLewy(Wektor2D& NowyWierzcholek)
        {this->Wierz_DolnyLewy = NowyWierzcholek;}

    void Zmien_Wierz_GornyPrawy (Wektor2D& NowyWierzcholek) 
        {this->Wierz_GornyPrawy = NowyWierzcholek;}

    /*!
        \brief Metoda zwracająca referencję do atrybutu 
        Wektor2D Wierz_DolnyLew klasy ObrysXY
        \param BRAK
        \retval Referencja do pola Wierz_DolnyLewy klasy ObrysXY.
    */
    Wektor2D& Wez_Wierz_DolnyLewy ()
        {return this->Wierz_DolnyLewy;}
    
    Wektor2D Wez_Wierz_DolnyLewy () const
        {return this->Wierz_DolnyLewy;}
    
    Wektor2D& Wez_Wierz_GornyPrawy ()
        {return this->Wierz_GornyPrawy;}
    
    Wektor2D Wez_Wierz_GornyPrawy () const
        {return this->Wierz_GornyPrawy;}

    /*___________________Metody pozostale_______________________*/

    void TranslacjaObrysu (double PrzemieszczenieWspX, double PrzemieszczenieWspY)
    {
        Wektor2D Przemieszczenie;
        
        Przemieszczenie[0] = PrzemieszczenieWspX;
        Przemieszczenie[1] = PrzemieszczenieWspY;
        
        this->Wez_Wierz_DolnyLewy() = this->Wez_Wierz_DolnyLewy() + Przemieszczenie;
        this->Wez_Wierz_GornyPrawy() = this->Wez_Wierz_GornyPrawy() + Przemieszczenie;
    }


};

#endif