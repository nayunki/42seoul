#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected :
        std::string type;
    public :
        AAnimal(void);
        AAnimal(const AAnimal& a);
        AAnimal& operator=(const AAnimal& a);
        virtual ~AAnimal(void);
        virtual void    makeSound(void) const = 0;
        const std::string& getType(void) const;
};

#endif