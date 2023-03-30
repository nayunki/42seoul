#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int& a)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = a << this->fractional_bits;
}

Fixed::Fixed(const float& f)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f * (1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
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

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    return (out << obj.toFloat());
}

float Fixed::toFloat(void) const
{
    return ((float)this->value / (1 << this->fractional_bits));
} //value 값은 같더라도, 자료형을 float으로 바꾸면 나눴을 때 나머지 살아있음 .! ! ! 

int Fixed::toInt(void) const
{
    return (this->value >> this->fractional_bits);
}