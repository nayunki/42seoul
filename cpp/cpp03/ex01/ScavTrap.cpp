#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    this->name = "Default";
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
}

ScavTrap::ScavTrap(std::string nm)
{
    std::cout << "ScavTrap " << nm << " constructor called" << std::endl;
    this->name = nm;
    this->Hit_points = 100;
    this->Energy_points = 50;
    this->Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& a)
{
    std::cout << "ScavTrap copy Constructor called" << std::endl;
    *this = a;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& a)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &a)
    {
        this->name = a.name;
        this->Hit_points = a.Hit_points;
        this->Energy_points = a.Energy_points;
        this->Attack_damage = a.Attack_damage;
    }
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't attack." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target;
    std::cout << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
    this->Energy_points--;
}

void ScavTrap::guardGate(void)
{
    if (this->Energy_points == 0 || this->Hit_points == 0)
    {
        std::cout << "ScavTrap " << this->name << " can't guard the Gate." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name << " is now guarding the Gate." << std::endl;
}