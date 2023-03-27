#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (av[i])
        {
            int j = 0;
            while (av[i][j])
            {
                std::cout << (char)toupper(av[i][j]); //왜 되지 ..? 이게맛냐 ?
                j++;
            }
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}