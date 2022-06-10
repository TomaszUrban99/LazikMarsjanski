#ifndef LAZIKSFR_HH
#define LAZIKSFR_HH

#include <list>
#include <memory>
#include "Lazik.hh"
#include "ProbkaRegolitu.hh"

class LazikSFR: public Lazik {

    std::list<std::shared_ptr<ProbkaRegolitu>> ListaProbek;

    public:

    enum TypObiektu Obiekt_ID() const override {return ID_LazikSFR;}



};

#endif