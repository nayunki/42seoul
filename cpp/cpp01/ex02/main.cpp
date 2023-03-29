#include <iostream>
#include <string>

int main(void)
{
    std::string a = "HI THIS IS BRAIN";
    std::string *stringPTR = &a;
    std::string &stringREF = a;

    std::cout << "memory address of the string variable : " << &a << std::endl;
    std::cout << "memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "memory address held by stringREF : " << &stringREF << std::endl;

    std::cout << "value of the string variable : " << a << std::endl;
    std::cout << "value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF : " << stringREF << std::endl;
    return (0);
}