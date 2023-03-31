#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& a)
{
    std::cout << "Dog copy Constructor called" << std::endl;
    *this = a;
}

Dog& Dog::operator=(const Dog& a)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound(void) const
{
    std::cout << "Mong Mong ! ! !" << std::endl;
}