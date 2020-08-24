/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:15:41 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:15:42 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
: Enemy(80, "RadScorpion")
{
    std::cout<<"* click click click *"<<std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout<<"* SPROTCH *"<<std::endl;
}

void RadScorpion::takeDamage(int damage)
{
    damage = damage > 3 ? damage - 3 : 0;
    Enemy::takeDamage(damage);
}