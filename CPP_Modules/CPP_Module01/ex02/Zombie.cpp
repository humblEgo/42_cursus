/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:50:18 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 22:25:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
        :name_("NoNamed"), type_("ground")
{
    this->announce();
}

Zombie::Zombie(std::string name, std::string type)
        :name_(name), type_(type)
{
    this->announce();
}

Zombie::~Zombie(void)
{
    std::cout<<"<"<<this->name_<<" ("<<this->type_<<")> ";
    std::cout<<"What the..?"<<std::endl;
    std::cout<<this->name_<<" returned to the ground."<<std::endl;
}

void    Zombie::announce(void)
{
    std::cout<<"<"<<this->name_<<" ("<<this->type_<<")> ";
    std::cout<<" Braiiiiiiinnnssss..."<<std::endl;
}