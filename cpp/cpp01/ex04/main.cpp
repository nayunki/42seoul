#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    // std::ifstream
    // std::ofstream
    if (ac != 4)
        return (1);
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    int f_len = filename.size();
    int s1_len = s1.size();
    int s2_len = s2.size();
    if (f_len == 0  || s1_len == 0 || s2_len == 0)
        return (1);
    if (av[1])
    //file open 실패 시 예외처리
    // av[1] open 후, av[i].replace에 복사
    // 이 과정에서, 등장하는 모든 s1을 s2로 대치

    //file close
}
// c함수 금지. 테스트 만들어서 제출