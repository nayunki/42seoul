#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private :
		std::string name;
		unsigned int	Hit_points; // 0 됐을 때 동작 보기 && 음수일 때 예외처리 ?
		unsigned int	Energy_points;
		unsigned int	Attack_damage; //0으로 초기화 후 바꾸질 않는데 ?
	public :
		ClapTrap(void);
		ClapTrap(const std::string& nm);
		ClapTrap(const ClapTrap& a);
		ClapTrap& operator=(const ClapTrap& a);
		~ClapTrap(void);
		void attack(const std::string& target); // target을 this->Ad만큼 공격한다는 메시지 출력. 근데 출력만 하잖아
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
        unsigned int    GetAttackDmg(void);
};

#endif