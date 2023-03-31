#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat(void);
        Cat(const Cat& a);
        Cat& operator=(const Cat& a);
        ~Cat(void);
        void    makeSound(void) const;
};

#endif