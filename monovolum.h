#include "automobil.h"
#pragma once

class monovolum : public automobil
{
    public:
        monovolum(double = 0,double = 0, std::string = "2000 01 01");
        monovolum(const monovolum&) = default;
        virtual ~monovolum() = default;
        void operator=(const monovolum &);
      //  virtual monovolum& operator= (const monovolum&) = default;

        virtual std::string DataFabricarii() const;
        virtual std::string ToString() const;
    protected:
        std::string data;
        virtual void Afisare(std::ostream&) const;
};
