/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:42 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 21:33:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
: type_(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) const
{
    return (this->type_);
}

void    Weapon::setType(std::string type)
{
    this->type_ = type;
}

void    Weapon::printAddr()
{
    long addr;

    addr = (long)this;
    std::cout<<std::hex<<addr<<std::endl;
}