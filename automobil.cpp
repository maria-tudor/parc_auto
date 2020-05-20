#include "automobil.h"
#include "contrabanda.h"

automobil::automobil(double lungime, double volum, int tip):lungime(lungime),volum(volum),tip(tip)
{}
automobil::~automobil()
{}
std::string automobil::GetTip() const {
    switch(this->tip)
    {
    case 0: return "hatchback";
    case 1: return "combi";
    case 2: return "sedan";
    }
    return "tip necunoscut";
}

int automobil::GiveTip(std::string x)
{
    if(x=="hatchback")
        return 0;
    else if(x=="combi")
        return 1;
    else if(x=="sedan")
        return 2;
    else
        return -1;
}

std::ostream& operator<< (std::ostream& g,const automobil& x)
{
    x.Afisare(g);
    return g;
}
std::istream& operator>> (std::istream& f,const automobil& x)
{
    throw contrabanda();
    return f;
}

