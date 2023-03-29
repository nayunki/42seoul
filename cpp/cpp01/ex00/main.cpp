#include "Zombie.hpp"

int main()
{
    std::cout << "test stack memory" << std::endl << std::endl;
    randomChump("a");
    randomChump("b");
    std::cout << std::endl << std::endl;

    std::cout << "test heap memory" << std::endl <<std::endl;
    Zombie *c = newZombie("c");
    Zombie *d = newZombie("d");
    c->announce();
    d->announce();
    std::cout << std::endl << std::endl;

    delete c;
    delete d;

    return (0);
}