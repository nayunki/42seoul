#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);
    
    std::string beforename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (beforename.length() == 0  || s1.length() == 0 || s2.length() == 0)
        return (1);
    
    std::ifstream    infile;
    infile.open(beforename);
    if (infile.fail())
        return (1);
    
    std::string aftername = av[1];
    aftername.append(".replace");
    std::ofstream   outfile(aftername);
    if (outfile.fail())
        return (1);
    
    std::string line;
    while (std::getline(infile, line))
    {
        size_t  i = 0;
        while (1)
        {
            i = line.find(s1, i);
            if (i == std::string::npos)
                break ;
            line.erase(i, s1.length());
            line.insert(i, s2);
            i += s2.length();
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return (0);
}