#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int value_;
    static const int bits_ = 8;
public:
    Fixed(void);
    Fixed(int const value);
    Fixed(float const value);
    Fixed(const Fixed& copy);
    Fixed&  operator=(const Fixed& other);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int     toInt(void) const;
    float   toFloat(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif