/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:15:46 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:15:47 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
: Enemy(170, "Super Mutant")
{
    std::cout<<"Gaaah. Me want smash heads!"<<std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout<<"Aaargh..."<<std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    damage = damage > 3 ? damage - 3 : 0;
    Enemy::takeDamage(damage);
}