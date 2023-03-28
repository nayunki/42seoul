#include "PhoneBook.hpp"

void    PhoneBook::add(void)
{    //앞부터 채우고, 매번 한 개씩 밀어주며 채우기
    int i = 0;
    while (i < 8)
    {
        if (this->contacts[i] != NULL) // 이미 값이 있는 만큼 넘김
            i++;
        else
            break ;
    }
    while (i > 0)
    {
        this->contacts[i] = this->contacts[i - 1]; // 이미 있는 값들을 뒤로 밀기
        this->contacts[i].set_index(i);
        i--;
    }
    this->contacts[0].add_one(); // 0번째에 새로운 값을 채운다
    this->contacts[0].set_index(0);
    return ;
}

void    PhoneBook::search(void)
{
    int     i;
    char    idx;
    int     int_idx;

    if (this->contacts[0] == NULL)
    {
        std::cout << "There is nothing to display" << std::endl;
        return ;
    }
    i = 0;
    while (i < 8 && this->contacts[i])
    {
        this->contacts[i].print_short();
        i++;
    }
    std::cout << "Select the index of the entry to display" << std::endl;
    std::cin >> idx;
    if (idx < '0' && i + '0' - 1 < idx)
    {
        std::count << "Try again. Put the valid index." << std::endl;
        return ;
    }
    int_idx = idx - '0';
    this->contacts[int_idx].print_whole();
    return ;
}