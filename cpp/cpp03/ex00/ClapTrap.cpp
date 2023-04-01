#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
    this->name = "Default";
    this->Hit_points = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string& nm)
{
    std::cout << "ClapTrap " << nm << " constructor called" << std::endl;
    this->name = nm;
    this->Hit_points = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& a)
{
    std::cout << "ClapTrap copy Constructor called" << std::endl;
    *this = a;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& a)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &a)
    {
        this->name = a.name;
        this->Hit_points = a.Hit_points;
        this->Energy_points = a.Energy_points;
        this->Attack_damage = a.Attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target;
    std::cout << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    this->Energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " took ";
    std::cout << amount << " points of damage." << std::endl;
    if (amount > this->Hit_points)
        this->Hit_points = 0;
    else
        this->Hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std::cout << "ClapTrap " << this->name << " can't be repaired." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " got ";
    std::cout << amount << " points of repair!" << std::endl;
    this->Energy_points--;
    this->Hit_points += amount;
}

unsigned int    ClapTrap::GetAttackDmg(void)
{
    return (this->Attack_damage);
}