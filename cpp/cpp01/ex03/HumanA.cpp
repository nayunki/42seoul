#include "HumanA.hpp"

HumanA::HumanA(std::string nm, Weapon &wp) : name(nm), a(wp)
{
}

HumanA::~HumanA(void)
{
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their ";
    std::cout << this->a.getType() << std::endl;
}