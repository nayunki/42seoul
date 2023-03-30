#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon      &a;
    public:
        HumanA(std::string nm, Weapon &wp);
        ~HumanA(void);
        void    attack(void);
};

#endif