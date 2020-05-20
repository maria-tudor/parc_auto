#include "mini.h"
#include "GT.h"
#pragma once

class tip_familie : public mini, public GT
{
    public:
        tip_familie(double = 0, double = 0, int = -1, double = 10, int = 200, int = 300, std::vector<int> = std::vector<int>(),std::vector<int> = std::vector<int>());
        tip_familie(const tip_familie&) = default;
        virtual ~tip_familie();

        virtual tip_familie& operator= (const tip_familie&) = default;

        virtual std::string ToString() const;
    protected:

        virtual void Afisare(std::ostream&) const;

};
