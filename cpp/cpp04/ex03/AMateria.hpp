#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
    protected :
        std::string type;
    public :
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const& a);
        AMateria& operator=(const AMateria&);
        virtual ~AMateria(void);
        std::string const& getType(void) const;
        virtual AMateria* clone(void) const = 0;
        virtual void use(ICharacter&);
};

#endif