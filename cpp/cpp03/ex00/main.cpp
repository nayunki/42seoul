#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(a.GetAttackDmg());
	b.beRepaired(3);
	b.attack("A");
	a.takeDamage(b.GetAttackDmg());
	a.beRepaired(10);
	return (0);
}