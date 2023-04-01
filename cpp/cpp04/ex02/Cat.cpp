#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
    std::cout << "Cat Default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& a)
{
    std::cout << "Cat copy Constructor called" << std::endl;
    this->type = a.type;
    if (a.brain)
        this->brain = new Brain(*a.brain);
    else
        this->brain = NULL;
}

Cat& Cat::operator=(const Cat& a)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &a)
    {
        Cat tmp(a);
        Brain *brain = this->brain;
        this->brain = tmp.brain;
        tmp.brain = brain;
        this->type = a.type;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void    Cat::makeSound(void) const
{
    std::cout << "Nya Nya . . ." << std::endl;
}

Brain   *Cat::getBrain(void)
{
    return (this->brain);
}