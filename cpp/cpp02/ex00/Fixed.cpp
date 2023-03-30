#include "Fixed.hpp"

// 내부에 들어온 인자를 인자로 받는 생성자를 호출함 (자동)
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &a)
{
    *this = a;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &a) // (=연산자) 초기화 후 대입. 자기 자신이 아닐때만 실행
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a)
        this->value = a.value;
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}