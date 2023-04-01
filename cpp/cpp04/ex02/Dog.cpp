#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void)
{
    std::cout << "Dog Default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& a)
{
    std::cout << "Dog copy Constructor called" << std::endl;
    this->type = a.type;
    if (a.brain)
        this->brain = new Brain(*a.brain);
    else
        this->brain = NULL;
}

Dog& Dog::operator=(const Dog& a)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &a)
    {
        Dog tmp(a);
        Brain *brain = this->brain;
        this->brain = tmp.brain;
        tmp.brain = brain;
        this->type = a.type;
    }
    return (*this);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void    Dog::makeSound(void) const
{
    std::cout << "Mong Mong ! ! ! " << std::endl;
}

Brain   *Dog::getBrain(void)
{
    return (this->brain);
}