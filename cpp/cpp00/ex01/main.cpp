#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book;
    std::string option;

    book.set_idx();
    while (!std::cin.eof())
    {
        std::cout << "Select your option : ADD, SEARCH, EXIT" << std::endl;
        std::getline(std::cin, option);
        if (std::cin.eof())
            return (0);
        if (option == "EXIT")
            return (0);
        else if (option == "ADD")
            book.add();
        else if (option == "SEARCH")
            book.search();
        else
            std::cout << "Please select the right option : ADD, SEARCH, EXIT" << std::endl;
    }
    return (0);
}