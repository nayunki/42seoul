#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    cat->makeSound(); //will output the cat sound!
    dog->makeSound();
    meta->makeSound();

    delete dog;
    delete cat;
    delete meta;

    const WrongAnimal* wrongmeta = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();

    std::cout << wrongcat->getType() << " " << std::endl;
    std::cout << wrongmeta->getType() << " " << std::endl;
    wrongcat->makeSound();
    wrongmeta->makeSound();

    delete wrongcat;
    delete wrongmeta;

    return (0);
}