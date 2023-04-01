#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap(void);
        FragTrap(const std::string& nm);
        FragTrap(const FragTrap& a);
        FragTrap& operator=(const FragTrap& a);
        ~FragTrap(void);
        void highFivesGuys(void);
};

#endif