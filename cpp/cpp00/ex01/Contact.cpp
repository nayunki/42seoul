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
	while (!std::cin.eof())
    {
        std::cout << "First name : ";
        std::getline(std::cin, this->f_name);
        if (std::cin.eof())
        {
            this->add_error();
            exit (0);
        }
        if (!(this->f_name.empty()))
            break;
        this->add_error();
    }
	while (!std::cin.eof())
    {
        std::cout << "Last name : ";
        std::getline(std::cin, this->l_name);
        if (std::cin.eof())
        {
            this->add_error();
            exit (0);
        }
        if (!(this->l_name.empty()))
            break;
        this->add_error();
    }
	while (!std::cin.eof())
    {
        std::cout << "Nickname : ";
        std::getline(std::cin, this->n_name);
        if (std::cin.eof())
        {
            this->add_error();
            exit (0);
        }
        if (!(this->n_name.empty()))
            break;
        this->add_error();
    }
	while (!std::cin.eof())
    {
        std::cout << "Phone number : ";
        std::getline(std::cin, this->phone);
        if (std::cin.eof())
        {
            this->add_error();
            exit (0);
        }
        if (!(this->phone.empty()))
            break;
        this->add_error();
    }
	while (!std::cin.eof())
    {
        std::cout << "Darkest secret : ";
        std::getline(std::cin, this->secret);
        if (std::cin.eof())
        {
            this->add_error();
            exit (0);
        }
        if (!(this->secret.empty()))
            break;
        this->add_error();
    }
	std::cout << "All Successfully Saved" << std::endl;
}

std::string    Contact::shorten(std::string str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void    Contact::print_short(void)
{
    std::cout << std::right;
    std::cout << std::setw(10) << this->idx << "|";
    std::cout << std::setw(10) << shorten(this->f_name) << "|";
    std::cout << std::setw(10) << shorten(this->l_name) << "|";
    std::cout << std::setw(10) << shorten(this->n_name) << "|";
    std::cout << std::left << std::endl;
}

void    Contact::print_whole(void)
{
    std::cout << this->f_name << std::endl;
    std::cout << this->l_name << std::endl;
    std::cout << this->n_name << std::endl;
    std::cout << this->phone << std::endl;
    std::cout << this->secret << std::endl;
}

int Contact::is_empty(void)
{
    if (this->f_name.empty())
        return (1);
    else
        return (0);
}
