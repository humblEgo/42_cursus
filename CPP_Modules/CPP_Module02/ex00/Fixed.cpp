/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:12:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:12:42 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<<std::endl;
    this->value_ = 0;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout<<"Copy constructor called"<<std::endl;
    this->value_ = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& assign)
{
    std::cout<<"Assignation operator called"<<std::endl;
    this->value_ = assign.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->value_);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    this->value_ = raw;
}