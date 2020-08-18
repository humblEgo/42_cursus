/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 01:01:02 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/18 01:04:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str;
    std::string *ptr;

    str = "HI THIS IS BRAIN";
    ptr = &str;
    const std::string& ref = str;

    std::cout<<str<<std::endl;
    std::cout<<*ptr<<std::endl;
    std::cout<<ref<<std::endl;

    return (0);
}