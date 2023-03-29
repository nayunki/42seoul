#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon      *b;
    public:
        HumanB::HumanB(std::string);
        void    attack(void);
        void    setWeapon(Weapon.type);
};

#endif