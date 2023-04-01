#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice& a) : AMateria(a)
{
}

Ice& Ice::operator=(const Ice&)
{
    return (*this);
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}