/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:28 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 21:33:29 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
: name_(name), weapon_(weapon)
{
}

HumanA::~HumanA()
{
    std::cout<<name_<<" died"<<std::endl;
}

void    HumanA::attack(void)
{
    std::cout<<name_<<" attacks with his ";
    std::cout<<weapon_.getType()<<std::endl;
}

void    HumanA::printWeaponAddr(void)
{   
    long addr;

    addr = (long)(&weapon_);
    std::cout<<std::hex<<addr<<std::endl;
}