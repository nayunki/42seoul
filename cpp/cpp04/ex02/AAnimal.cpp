#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal Default constructor called" << std::endl;
    this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& a)
{
    std::cout << "AAnimal copy Constructor called" << std::endl;
    *this = a;
}

AAnimal& AAnimal::operator=(const AAnimal& a)
{
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return (*this);
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal destructor called" << std::endl;
}

const std::string& AAnimal::getType(void) const
{
    return (this->type);
}