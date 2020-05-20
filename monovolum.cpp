#include "monovolum.h"

monovolum::monovolum(double lungime, double volum, std::string data): automobil(lungime,volum,4),data(data)
{
//    delete this;
}

std::string monovolum::DataFabricarii() const
{
    return data;
}

void monovolum::Afisare(std::ostream& g) const
{
    g<<ToString();
}

std::string monovolum::ToString() const
{
    return ("{ lungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\n data fabricarii: " + data + " }");
}
void monovolum::operator=(const monovolum &M){


    this->lungime=M.lungime;
    this->volum=M.volum;
    this->data=M.data;

}
