# include "Character.hpp"
# include "AMateria.hpp"

Character::Character(void)
{
    for (std::size_t i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

Character::Character(const std::string& nm)
{
    this->name = nm;
    for (std::size_t i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

Character::Character(const Character& a)
{
    this->name = a.name;
    for (std::size_t i = 0; i < 4; i++)
    {
        if (a.materias[i])
            this->materias[i] = a.materias[i]->clone();
        else
            this->materias[i] = NULL;
    }
}

Character& Character::operator=(const Character& a)
{
    if (this != &a)
    {
        this->name = a.name;
        Character tmp(a);
        for (std::size_t i = 0; i < 4; i++)
        {
            AMateria *materia = this->materias[i];
            this->materias[i] = tmp.materias[i];
            tmp.materias[i] = materia;
        }
    }
    return (*this);
}

Character::~Character()
{
    for (std::size_t i = 0; i < 4; i++)
        delete this->materias[i];
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (std::size_t i = 0; i < 4; i++)
    {
        if (!this->materias[i])
        {
            this->materias[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 4 || idx < 0)
        return ;
    this->materias[idx] = NULL;
}

AMateria *Character::get(int idx)
{
    if (idx >= 4 || idx < 0)
        return (0);
    return (this->materias[idx]);
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4 || idx < 0)
        return ;
    if (!materias[idx])
        return ;
    this->materias[idx]->use(target);
}