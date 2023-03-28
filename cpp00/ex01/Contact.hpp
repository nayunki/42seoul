#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"

class   Contact
{
    private :
        std::string idx;
        std::string f_name;
        std::string l_name;
        std::string n_name;
        std::string phone;
        std::string secret;
    public :
        std::string  short_n_align(std::string str);
        void    set_index(int index);
        void    add_error(void);
        void    add_one(void);
        void    print_short(void);
        void    print_whole(void);
};

#endif