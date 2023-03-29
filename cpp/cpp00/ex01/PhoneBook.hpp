#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     idx;
    public:
        void    add(void);
        void    search(void);
        void    set_idx(void);
};

int str_to_int(std::string str);

#endif