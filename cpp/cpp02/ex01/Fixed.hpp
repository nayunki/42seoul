#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private :
        int value;
        static const int    fractional_bits = 8;

    public :
        Fixed(void);
        Fixed(const int a);
        Fixed(const float f);
        Fixed(const Fixed& a);
        Fixed& operator=(const Fixed& a);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif