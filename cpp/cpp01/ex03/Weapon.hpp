#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon(std::string str);
        ~Weapon(void);
        const std::string &getType(void);
        void setType(std::string str);
};

#endif