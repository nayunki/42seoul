#include "PhoneBook.hpp"

void    PhoneBook::add(void)
{
    int i;

    if (this->idx < 8)
        i = idx;
    else
        i = idx % 8;
    this->contacts[i].add_one();
    this->contacts[i].set_index(i);
    this->idx++;
    return ;
}

void    PhoneBook::search(void)
{
    int i;
    std::string str;
    int idx;

    if (this->contacts[0].is_empty())
    {
        std::cout << "There is nothing to display" << std::endl;
        return ;
    }
    i = 0;
    while (i < 8 && !(this->contacts[i].is_empty()))
    {
        this->contacts[i].print_short();
        i++;
    }
    std::cout << "Select the index to display" << std::endl;
    std::getline(std::cin, str);
    if (std::cin.eof())
		return ;
    idx = str_to_int(str);
    if (0 <= idx && idx < i)
        this->contacts[idx].print_whole();
    else
        std::cout << "Try again. Put the valid index." << std::endl;
    return ;
}

void    PhoneBook::set_idx(void)
{
    this->idx = 0;
}

int str_to_int(std::string str)
{
    int i = -1;

    if (str == "0")
        i = 0;
    else if (str == "1")
        i = 1;
    else if (str == "2")
        i = 2;
    else if (str == "3")
        i = 3;
    else if (str == "4")
        i = 4;
    else if (str == "5")
        i = 5;
    else if (str == "6")
        i = 6;
    else if (str == "7")
        i = 7;
    return (i);
}
