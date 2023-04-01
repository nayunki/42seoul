#include "AMateria.hpp"

AMateria::AMateria(void)
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& a) : type(a.type)
{
}

AMateria& AMateria::operator=(const AMateria&)
{
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType(void) const
{
    return (this->type);
}

void AMateria::use(ICharacter&)
{
}