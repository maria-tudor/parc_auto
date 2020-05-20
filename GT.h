#include "automobil.h"
#include <vector>
#pragma once

class GT : public virtual automobil
{
    public:
        GT(double = 0, double = 0, int = -1, int = 200, int = 300, std::vector<int> = std::vector<int>());
        GT(const GT&) = default;
        virtual ~GT() = default;

        virtual GT& operator= (const GT&) = default;

        virtual std::string ToString() const;
        virtual std::string GetDrum() const;

        static GT stog(std::string);
    protected:
        const int putere;
        const int autonomie;
        const std::vector<int> asistenta_drum;

        virtual void Afisare(std::ostream&) const;

        static std::string GetADrum(int);
        static int GiveADrum(std::string);
};
