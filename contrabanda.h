#include <exception>

class contrabanda : public std::exception
{
    public:
        contrabanda () throw() = default;
        contrabanda(const contrabanda&) throw() = default;
        contrabanda& operator= (const contrabanda&) throw() = default;
        virtual ~contrabanda() throw() = default;
        virtual const char* what() const throw();

};
