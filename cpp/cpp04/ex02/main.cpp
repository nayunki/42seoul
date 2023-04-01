#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const AAnimal *meta[6];

    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
            meta[i] = new Cat();
        else
            meta[i] = new Dog();
    }

    for (int i = 0; i < 6; i++)
        delete meta[i];

    Cat a;

	a.getBrain()->setIdea(0, "happy");
	std::cout << "Cat a's first idea is "<< a.getBrain()->getIdea(0) << std::endl;

    Cat b1(a);
    Cat b2 = a;
    Cat c;
    c = a;

	std::cout << "Cat b1's first idea is "<< b1.getBrain()->getIdea(0) << std::endl;
 	std::cout << "Cat b2's first idea is "<< b2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat c's first idea is "<< c.getBrain()->getIdea(0) << std::endl;

	a.getBrain()->setIdea(0, "bad");
    std::cout << "Cat a's first idea CHANGED!!!" << std::endl;
	std::cout << "Cat a's first idea is "<< a.getBrain()->getIdea(0) << std::endl;

	std::cout << "Cat b1's first idea is "<< b1.getBrain()->getIdea(0) << std::endl;
 	std::cout << "Cat b2's first idea is "<< b2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat c's first idea is "<< c.getBrain()->getIdea(0) << std::endl;

    // AAnimal x;

    return (0);
}