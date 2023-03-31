#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal Default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& a)
{
    std::cout << "Animal copy Constructor called" << std::endl;
    *this = a;
}

Animal& Animal::operator=(const Animal& a)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal doesn't make sound." << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}