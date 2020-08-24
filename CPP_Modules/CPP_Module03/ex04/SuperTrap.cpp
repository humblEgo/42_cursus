/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:14:54 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:14:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name)
: ClapTrap(name), FragTrap("temp"), NinjaTrap("temp")
{
    setMaxHitPoints(100);
    setHitPoints(100);
    setMaxEnergyPoints(120);
    setEnergyPoints(120);
    melee_attack_damage_ = 60;
    range_attack_damage_ = 20;
    armor_damage_reduction_ = 5;
    std::cout<<name_<<"(SuperTrap) has been summoned!"<<std::endl;
    std::cout<<name_<<": No more cages!"<<std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& copy)
: ClapTrap(copy.name_), FragTrap(copy.name_), NinjaTrap(copy.name_)
{
    this->copy(copy);
}

SuperTrap& SuperTrap::operator=(const SuperTrap& assign)
{
    name_ = assign.name_;
    this->copy(assign);
    return (*this);
}

SuperTrap::~SuperTrap(void)
{
    std::cout<<this->name_<<"(SuperTrap) died"<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void SuperTrap::rangedAttack(std::string const& target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const& target)
{
    NinjaTrap::meleeAttack(target);
}