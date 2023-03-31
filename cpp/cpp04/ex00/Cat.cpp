#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& a)
{
    std::cout << "Cat copy Constructor called" << std::endl;
    *this = a;
}

Cat& Cat::operator=(const Cat& a)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "Nya Nya . . ." << std::endl;
}