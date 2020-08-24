/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:12:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:12:47 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout<<a.getRawBits()<<std::endl;
    std::cout<<b.getRawBits()<<std::endl;
    std::cout<<c.getRawBits()<<std::endl;

    return (0);
}