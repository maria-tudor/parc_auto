#include "GT.h"
#include <iostream>
GT::GT(double lungime, double volum, int tip, int putere, int autonomie, std::vector<int> asistenta_drum):automobil(lungime,volum,tip),putere(putere),autonomie(autonomie),asistenta_drum(asistenta_drum)
{}

std::string GT::GetADrum(int x)
{
    switch (x)
    {
        case 0: return "Sistem navigatie cu harta europei";
        case 1: return "Sistem navigatie cu harta americii de nord";
        case 2: return "Sistem navigatie cu harta americii de sud";
        case 3: return "Sistem navigatie cu harta australiei";
        case 4: return "Sistem de mentinere a vitezei de rulare";
        case 5: return "Sistem lane keep assist";
        case 6: return "Heads up display";
        case 7: return "Sistem cruse control cu reglare automata a vitezei";
    }
    return "Eh..";
}

std::string GT::GetDrum()const
{
    std::string aux;
    for (auto x : asistenta_drum)
        aux= aux + GetADrum(x) + '\n';
    if(aux.size()>0)
        aux.resize(aux.size()-1);
    return aux;
}

std::string GT::ToString() const
{
    return ("{ lungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\ntip: " + GetTip() + "\nputere: " + std::to_string(putere) + "\nautonomie: " + std::to_string(autonomie) + '\n' + GetDrum() + " }");
}

void GT::Afisare(std::ostream& g) const
{
    g<<ToString();
}

int GT::GiveADrum(std::string x)
{
    if(x=="Sistem navigatie cu harta europei")
        return 0;
     else if(x=="Sistem navigatie cu harta americii de nord")
        return 1;
     else if(x=="Sistem navigatie cu harta americii de sud")
        return 2;
     else if(x=="Sistem navigatie cu harta australiei")
        return 3;
     else if(x=="Sistem de mentinere a vitezei de rulare")
        return 4;
     else if(x=="Sistem lane keep assist")
        return 5;
     else if(x=="Heads up display")
        return 6;
     else if(x=="Sistem cruse control cu reglare automata a vitezei")
        return 7;
     else
        return -1;
}

GT GT::stog(std::string x)
{
    double lungime = std::stod(x.substr(x.find("lungime")+8));
    double volum = std::stod(x.substr(x.find("volum")+6));

    std::string aux = x.substr(x.find("tip")+5);
    if(aux.find('\n')==std::string::npos)
        aux.resize(aux.size()-2);
    else
        aux.resize(aux.find('\n'));
    int tip = automobil::GiveTip(aux);

    int putere = std::stoi(x.substr(x.find("putere")+7));
    int autonomie = std::stoi(x.substr(x.find("autonomie")+10));

    aux=x.substr(x.find("autonomie"));
    int numara = 0;
    for(auto y : aux)
        if(y=='\n')
            ++numara;
    std::vector<int> asistenta_drum(numara);
    if(asistenta_drum.size()>0)
    {
        aux=aux.substr(aux.find('\n')+1);
        unsigned i = 1;
        std::string aux2;
        while(i<asistenta_drum.size())
        {
            aux2=aux;
            aux2.resize(aux2.find('\n'));
            asistenta_drum[i-1]=GiveADrum(aux2);
            ++i;
            aux=aux.substr(aux.find('\n')+1);
        }
        aux.resize(aux.size()-2);
        asistenta_drum[i-1]=GiveADrum(aux);
    }
    return GT(lungime,volum,tip,putere,autonomie,asistenta_drum);
}
