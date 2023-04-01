#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
    this->name = "Default";
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
}

FragTrap::FragTrap(const std::string& nm)
{
    std::cout << "FragTrap " << nm << " constructor called" << std::endl;
    this->name = nm;
    this->Hit_points = 100;
    this->Energy_points = 100;
    this->Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& a)
{
    std::cout << "FragTrap copy Constructor called" << std::endl;
    *this = a;
}

FragTrap& FragTrap::operator=(const FragTrap& a)
{
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &a)
    {
        this->name = a.name;
        this->Hit_points = a.Hit_points;
        this->Energy_points = a.Energy_points;
        this->Attack_damage = a.Attack_damage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    if (this->Hit_points == 0)
    {
        std::cout << "FragTrap " << this->name << " can't highfive." << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " HIGHFIVE ~!" << std::endl;
}