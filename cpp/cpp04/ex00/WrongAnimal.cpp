#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
    std::cout << "WrongAnimal copy Constructor called" << std::endl;
    *this = a;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal doesn't make sound." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}