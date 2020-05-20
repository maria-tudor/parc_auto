#include "automobil.h"
#include <vector>
#pragma once

class mini: public virtual automobil
{
    public:
        mini(double = 0, double = 0, int = -1, double = 10, std::vector<int> = std::vector<int>());
        mini(const mini&) = default;
        virtual ~mini() = default;

        virtual mini& operator= (const mini&) = default;

        virtual std::string ToString() const;
        virtual std::string GetParcare() const;

        static mini stom(std::string);
    protected:
        const double consum;
        const std::vector<int> asistenta_parcare;

        virtual void Afisare(std::ostream&) const;

        static std::string GetAParcare(int);
        static int GiveAparcare(std::string);
};
