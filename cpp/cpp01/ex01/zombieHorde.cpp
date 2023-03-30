#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *horde;
    int     i;

    if (N <= 0)
        return (NULL);
    horde = new Zombie[N];
    i = 0;
    while (i < N)
    {
        horde[i].set_name(name);
        i++;
    }
    return (horde);
}