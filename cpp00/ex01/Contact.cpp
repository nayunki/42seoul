#include "Contact.hpp"

void    Contact::set_index(int index)
{
    this->idx = index;
}

void    Contact::add_error(void)
{
    std::cout << "Fields can't be empty" << std::endl;
    return ;
}

void    Contact::add_one(void)
{
	std::cout << "First name : ";
	std::cin >> this->f_name;
    if (this->f_name == NULL)
        return (this->add_error());
	std::cout << "Last name : ";
	std::cin >> this->l_name;
    if (this->l_name == NULL)
        return (this->add_error());
	std::cout << "Nickname : ";
	std::cin >> this->n_name;
    if (this->n_name == NULL)
        return (this->add_error());
	std::cout << "Phone number : ";
	std::cin >> this->phone;
    if (this->phone == NULL)
        return (this->add_error());
	std::cout << "Darkest secret : ";
	std::cin >> this->secret;
    if (this->secret == NULL)
        return (this->add_error());
	std::cout << "All Successfully Saved" << std::endl;
}

std::string    Contact::short_n_align(std::string str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (std::string(10 - str.size()) + str);
}

void    Contact::print_short(void)
{
    std::cout << "|" << short_n_align(this->idx);
    std::cout << "|" << short_n_align(this->f_name);
    std::cout << "|" << short_n_align(this->l_name);
    std::cout << "|" << short_n_align(this->n_name) << std::endl;
}

void    Contact::print_whole(void)
{
    std::cout << this->f_name << std::endl;
    std::cout << this->l_name << std::endl;
    std::cout << this->n_name << std::endl;
    std::cout << this->phone << std::endl;
    std::cout << this->secret << std::endl;
}