#include "Zombie.hpp"

int main(void)
{
    Zombie  *horde;
    int num;

    std::cout << "How many zombies?" << std::endl;
    std::cin >> num;
    horde = zombieHorde(num, "zomb");
    int i = 0;
    while (i < num)
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;
    return (0);
}