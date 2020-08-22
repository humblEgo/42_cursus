/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:34 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 21:33:35 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const name)
: name_(name), weapon_(NULL)
{
}

HumanB::~HumanB()
{
    std::cout<<this->name_<<" died"<<std::endl;
}

void    HumanB::attack(void) const
{
    std::cout<<this->name_<<" attacks with his ";
    std::cout<<this->weapon_->getType()<<std::endl;
}

void    HumanB::setWeapon(const Weapon& weapon)
{
    this->weapon_ = &weapon;
}