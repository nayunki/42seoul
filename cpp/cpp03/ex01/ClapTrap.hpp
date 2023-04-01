#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected :
		std::string name;
		unsigned int	Hit_points;
		unsigned int	Energy_points;
		unsigned int	Attack_damage;
	public :
		ClapTrap(void);
		ClapTrap(const std::string& nm);
		ClapTrap(const ClapTrap& a);
		ClapTrap& operator=(const ClapTrap& a);
		virtual ~ClapTrap(void);
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        unsigned int    GetAttackDmg(void);
};

#endif