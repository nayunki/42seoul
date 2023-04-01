#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private :
        Brain *brain;
    public :
        Cat(void);
        Cat(const Cat& a);
        Cat& operator=(const Cat& a);
        ~Cat(void);
        void    makeSound(void) const;
        Brain*  getBrain(void);
};

#endif