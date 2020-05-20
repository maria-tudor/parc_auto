#include <exception>

class indisponibil : public std::exception
{
    public:
        indisponibil () throw() = default;
        indisponibil(const indisponibil&) throw() = default;
        indisponibil& operator= (const indisponibil&) throw() = default;
        virtual ~indisponibil() throw() = default;
        virtual const char* what() const throw();

};
