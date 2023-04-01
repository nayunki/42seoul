#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat(void);
        WrongCat(const WrongCat& a);
        WrongCat& operator=(const WrongCat& a);
        virtual ~WrongCat(void);
        void    makeSound(void) const;
};

#endif