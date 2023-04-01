#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (std::size_t i = 0; i < 4; i++)
        this->memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& a)
{
    for(int i = 0; i < 4; i++)
        this->memory[i] = a.memory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& a)
{
    if (this != &a)
    {
        for(int i = 0; i < 4; i++)
            this->memory[i] = a.memory[i];
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (std::size_t i = 0; i < 4; i++)
        delete this->memory[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for (std::size_t i = 0; i < 4; i++)
    {
        if (!this->memory[i])
        {
            this->memory[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (std::size_t i = 0; i < 4; i++)
    {
        if (this->memory[i] && this->memory[i]->getType() == type)
            return (this->memory[i]->clone());
    }
    return (0);
}