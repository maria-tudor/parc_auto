#include "tip_familie.h"
#include "mini.h"
#include "GT.h"

tip_familie::tip_familie(double lungime, double volum, int tip, double consum, int putere, int autonomie, std::vector<int> asistenta_parcare, std::vector<int> asistenta_drum): automobil(lungime,volum,tip),mini(lungime,volum,tip,consum,asistenta_parcare),GT(lungime,volum,tip,putere,autonomie,asistenta_drum)
{}

tip_familie::~tip_familie()
{}

std::string tip_familie::ToString() const
{
    return ("{ lungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\ntip: " + GetTip() + "\nconsum: " + std::to_string(consum) +"\nlungime: " + std::to_string(lungime) + "\nvolum: " + std::to_string(volum) + "\ntip: " + GetTip() + "\nputere: " + std::to_string(putere) + "\nautonomie: " + std::to_string(autonomie) + "\nDotari parcare:\n" + GetParcare() + "\nDotariDrum:\n" + GetDrum() + " }");
}
void tip_familie::Afisare(std::ostream& g) const
{
    g<<ToString();
}
