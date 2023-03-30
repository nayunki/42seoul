#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private :
        int value;
        static const int    fractional_bits = 8;

    public :
        Fixed(void);
        Fixed(const Fixed &a);
        Fixed& operator=(const Fixed &a);
        ~Fixed(void);
        int getRawBits(void) const; // 함수 const -> 함수 내에서 어떤 값도 변경 x
        void setRawBits(int const raw);
};

#endif