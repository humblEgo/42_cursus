/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:12:44 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:12:44 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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