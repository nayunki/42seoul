#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure(void);
        Cure(const Cure& a);
        Cure& operator=(const Cure&);
        ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif