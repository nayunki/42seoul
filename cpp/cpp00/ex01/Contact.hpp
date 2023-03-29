#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class   Contact
{
    private :
        int idx; //std library 안에 존재한다는 뜻
        std::string f_name;
        std::string l_name;
        std::string n_name;
        std::string phone;
        std::string secret;
    public :
        std::string  shorten(std::string str);
        void    set_index(int index);
        void    add_error(void);
        void    add_one(void);
        void    print_short(void);
        void    print_whole(void);
        int     is_empty(void);
};

#endif