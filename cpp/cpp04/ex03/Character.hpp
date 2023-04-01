#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
    private :
        AMateria *materias[4];
        std::string name;
    public :
        Character(void);
        Character(const std::string& nm);
        Character(const Character& a);
        Character& operator=(const Character& a);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        AMateria *get(int idx);
        void use(int idx, ICharacter& target);
};

#endif