#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->value = 0;
}

Fixed::Fixed(const int& a)
{
    this->value = a << this->fractional_bits;
}

Fixed::Fixed(const float& f)
{
    this->value = roundf(f * (1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& a)
{
    *this = a;
}

Fixed& Fixed::operator=(const Fixed &a)
{
    if (this != &a)
        this->value = a.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
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
}

int Fixed::toInt(void) const
{
    return (this->value >> this->fractional_bits);
}

bool	Fixed::operator>(const Fixed& ref) const
{
    return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(const Fixed& ref) const
{
    return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(const Fixed& ref) const
{
    return (!(*this < ref));
}

bool	Fixed::operator<=(const Fixed& ref) const
{
    return (!(*this > ref));
}

bool	Fixed::operator==(const Fixed& ref) const
{
    return (this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator!=(const Fixed& ref) const
{
    return (!(*this == ref));
}

Fixed	Fixed::operator+(const Fixed& ref) const
{
    Fixed   ret(this->toFloat() + ref.toFloat());
    return (ret);
}

Fixed	Fixed::operator-(const Fixed& ref) const
{
    Fixed   ret(this->toFloat() - ref.toFloat());
    return (ret);
}

Fixed	Fixed::operator*(const Fixed& ref) const
{
    Fixed   ret(this->toFloat() * ref.toFloat());
    return (ret);
}

Fixed	Fixed::operator/(const Fixed& ref) const
{
    Fixed   ret(this->toFloat() / ref.toFloat());
    return (ret);
}

Fixed&	Fixed::operator++(void)
{
    ++this->value;
    return (*this);
}

const Fixed	Fixed::operator++(int)
{
    const Fixed ret(*this);

    ++this->value;
    return (ret);
}

Fixed&	Fixed::operator--(void)
{
    --this->value;
    return (*this);
}

const Fixed	Fixed::operator--(int)
{
    const Fixed ret(*this);

    --this->value;
    return (ret);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a <= b)
        return (a);
    else
        return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a >= b)
        return (a);
    else
        return (b);
}