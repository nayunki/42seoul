#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *brain;
    public :
        Dog(void);
        Dog(const Dog& a);
        Dog& operator=(const Dog& a);
        ~Dog(void);
        void    makeSound(void) const;
        Brain*  getBrain(void);
};

#endif