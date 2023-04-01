#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    public :
        Ice(void);
        Ice(const Ice& a);
        Ice& operator=(const Ice&);
        ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif