#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
    protected :
        std::string type;
    public :
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& a);
        WrongAnimal& operator=(const WrongAnimal& a);
        virtual ~WrongAnimal(void);
        virtual void    makeSound(void) const;
        std::string getType(void) const;
};

#endif