#include "mini.h"
#include <iostream>

mini::mini(double lungime, double volum, int tip, double consum, std::vector<int> dotari):automobil(lungime,volum,tip),consum(consum),asistenta_parcare(dotari)
{}

 std::string mini::ToString() const
 {
     return ("{ lungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\ntip: " + GetTip() + "\nconsum: " + std::to_string(consum) +'\n' + GetParcare() + " }");
 }

 std::string mini::GetParcare() const
 {
     std::string aux;
     for (auto x : asistenta_parcare)
        aux= aux + GetAParcare(x) + '\n';
    if(aux.size()>0)
        aux.resize(aux.size()-1);
     return aux;

 }

 std::string mini::GetAParcare(int x)
 {
     switch(x)
     {
         case 0: return "Senzori parcare spate";
         case 1: return "Senzori parcare fata";
         case 2: return "Senzori parcare laterali";
         case 3: return "Camera marsarier";
         case 4: return "Sistem camere 360°";
         case 5: return "Sistem de parcare automat";
     }
     return "nu se cunoaste sistemul de parcare";
 }
 int mini::GiveAparcare(std::string x)
 {
     if(x=="Senzori parcare spate")
        return 0;
     else if(x=="Senzori parcare fata")
        return 1;
     else if(x=="Senzori parcare laterali")
        return 2;
     else if(x=="Camera marsarier")
        return 3;
     else if(x=="Sistem camere 360°")
        return 4;
     else if(x=="Sistem de parcare automat")
        return 5;
     else
        return -1;
 }

 mini mini::stom(std::string x)
 {
    double lungime = std::stod(x.substr(x.find("lungime")+8));
    double volum = std::stod(x.substr(x.find("volum")+6));
    double consum= std::stod(x.substr(x.find("consum")+7));
//    int tip;
    std::string aux = x.substr(x.find("tip")+5);
    if(aux.find('\n')==std::string::npos)
        aux.resize(aux.size()-2);
    else
        aux.resize(aux.find('\n'));
    int tip = automobil::GiveTip(aux);
    aux=x.substr(x.find("consum"));
    int numara = 0;
    for(auto y : aux)
        if(y=='\n')
            ++numara;
    std::vector<int> asistenta_parcare(numara);
    if(asistenta_parcare.size()>0)
    {
        aux=aux.substr(aux.find('\n')+1);
        unsigned i = 1;
        std::string aux2;
        while(i<asistenta_parcare.size())
        {
            aux2=aux;
            aux2.resize(aux2.find('\n'));
            asistenta_parcare[i-1]=GiveAparcare(aux2);
            ++i;
            aux=aux.substr(aux.find('\n')+1);
        }
        aux.resize(aux.size()-2);
        asistenta_parcare[i-1]=GiveAparcare(aux);
    }
    return mini(lungime,volum,tip,consum,asistenta_parcare);
 }

void mini::Afisare(std::ostream& g) const
{
    g<<ToString();
}
