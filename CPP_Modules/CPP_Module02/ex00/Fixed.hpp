#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int value_;
    static const int bits_ = 8;
public:
    Fixed(void);
    Fixed(const Fixed& copy);
    Fixed& operator=(const Fixed& assign);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif