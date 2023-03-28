#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (i < ac)
        {
            int j = 0;
            while (av[i][j])
            {
                std::cout << (char)toupper(av[i][j]);
                j++;
            }
            std::cout << " ";
            i++;
        }
    }
    std::cout << std::endl;
}

//함수 사용법, 쉬프트 연산자 사용 이유, 개행 없어도 되는지