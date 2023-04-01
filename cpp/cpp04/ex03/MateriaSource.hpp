#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria *memory[4];
    public :
        MateriaSource(void);
        MateriaSource(const MateriaSource& a);
        MateriaSource& operator=(const MateriaSource& a);
        ~MateriaSource();
        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const& type);
};

#endif