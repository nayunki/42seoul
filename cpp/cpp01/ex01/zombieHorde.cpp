#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie  *horde;
    int     i;

    horde = new Zombie[N];
    if (N <= 0)
        return (NULL);
    i = 0;
    while (i < N)
    {
        horde[i].set_name(name);
        i++;
    }
    return (horde);
}