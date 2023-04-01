#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& a)
{
    std::cout << "Brain copy Constructor called" << std::endl;
    *this = a;
}

Brain& Brain::operator=(const Brain& a)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &a)
    {
        for (std::size_t i = 0; i < BRAIN_SIZE; i++)
            this->ideas[i] = a.getIdea(i);
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(std::size_t i) const
{
    return (this->ideas[i]);
}

void    Brain::setIdea(std::size_t i, const std::string& str)
{
    this->ideas[i] = str;
}