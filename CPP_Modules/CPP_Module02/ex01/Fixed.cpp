/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:12:27 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:12:28 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout<<"Default constructor called"<<std::endl;
    this->value_ = 0;
}

Fixed::Fixed(int const value)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->value_ = (value << Fixed::bits_);
}

Fixed::Fixed(float const value)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->value_ = roundf(value * (1 << Fixed::bits_));
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout<<"Assignation operator called"<<std::endl;
    this->value_ = other.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return (out);
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->value_);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    this->value_ = raw;
}

int Fixed::toInt(void) const
{
    return (this->value_ >> this->bits_);
}

float Fixed::toFloat(void) const
{
    return ((float)this->value_ / (float)(1 << this->bits_));
}