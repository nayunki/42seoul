#include "FragTrap.hpp"

int	main(void)
{
    FragTrap e("E");
    FragTrap f("F");

	e.attack("F");
	f.takeDamage(e.GetAttackDmg());
	f.beRepaired(30);
	f.attack("E");
	e.takeDamage(f.GetAttackDmg());
	f.attack("E");
	e.takeDamage(f.GetAttackDmg());
	f.attack("E");
	e.takeDamage(f.GetAttackDmg());
	f.attack("E");
	e.takeDamage(f.GetAttackDmg());

    e.highFivesGuys();
    f.highFivesGuys();

	return (0);
}