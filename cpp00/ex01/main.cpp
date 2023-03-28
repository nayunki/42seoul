#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook book; // 인스턴스화
    std::string option;

    while (1)
    {
        std::cout << "Select your option : ADD, SEARCH, EXIT" << std::endl;
        std::cin >> option;
        if (option == "ADD")
            book.add(); //왜 여긴 점 ? 그야 인스턴스니까요 ..
        else if (option == "SEARCH")
            book.search();
        else if (option == "EXIT")
            return (0);
        else
            std::cout << "Please select the right option : ADD, SEARCH, EXIT" << std::endl;
    }
    return (0);
}