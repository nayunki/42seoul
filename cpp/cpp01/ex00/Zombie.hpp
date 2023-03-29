#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class   Zombie
{
    private :
        std::string name;
    public :
        Zombie(std::string name); //생성자 만들어야 할까 ?
        ~Zombie(void); //소멸자
        void    announce(void);
};

Zombie  *newZombie(std::string name); // 좀비 생성, 이름 붙이고 리턴 ?
void    randomChump(std::string name); // 좀비 생성, 이름 붙이고 자기가 .. 어나운스

//좀비를 스택에 할당 힙에 할당 ?
//쓸모 없어지면 좀비 파괴

#endif