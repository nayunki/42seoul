#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure& a) : AMateria(a)
{
}

Cure& Cure::operator=(const Cure&)
{
    return (*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}