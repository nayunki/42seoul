#include "ScavTrap.hpp"

int	main(void)
{
    ScavTrap c("C");
    ScavTrap d("D");

	c.attack("D");
	d.takeDamage(c.GetAttackDmg());
	d.beRepaired(30);
	d.attack("C");
	c.takeDamage(d.GetAttackDmg());
    c.beRepaired(20);

    d.guardGate();

	return (0);
}