#ifndef BRAIN_HPP
# define BRAIN_HPP

# define BRAIN_SIZE 100

# include <iostream>
# include <string>

class Brain
{
    private :
        std::string ideas[BRAIN_SIZE];
    public :
        Brain(void);
        Brain(const Brain& a);
        Brain& operator=(const Brain& a);
        ~Brain(void);
        const std::string& getIdea(std::size_t i) const;
        void    setIdea(std::size_t i, const std::string& str);
};

#endif