#include "HumanB.hpp"

HumanB::HumanB(std::string nm) : name(nm)
{
}

HumanB::~HumanB(void)
{
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->b->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &wp)
{
    this->b = &wp;
}