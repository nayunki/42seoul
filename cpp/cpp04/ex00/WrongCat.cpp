#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat Default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& a)
{
    std::cout << "WrongCat copy Constructor called" << std::endl;
    *this = a;
}

WrongCat& WrongCat::operator=(const WrongCat& a)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &a)
        this->type = a.type;
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}