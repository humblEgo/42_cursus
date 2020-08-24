/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:14:12 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:14:12 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name)
: ClapTrap(name)
{
    std::cout<<"==========================Constructor"<<std::endl;
    setMaxHitPoints(60);
    setHitPoints(60);
    setMaxEnergyPoints(120);
    setEnergyPoints(120);
    melee_attack_damage_ = 60;
    range_attack_damage_ = 5;
    armor_damage_reduction_ = 0;
    std::cout<<name_<<" has been summoned!"<<std::endl;
    std::cout<<name_<<": The eyes never lie."<<std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& copy)
: ClapTrap(copy.name_)
{
    std::cout<<"==========================copy"<<std::endl;
    this->copy(copy);
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& assign)
{
    std::cout<<"==========================assign"<<std::endl;
    name_ = assign.name_;
    this->copy(assign);
    return (*this);
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout<<"======================Destructor"<<std::endl;
    std::cout<<this->name_<<" died"<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap& target)
{
    (void)target;
    std::cout<<name_<<": ClapTrap..? die!"<<std::endl;
    std::cout<<name_<<": From the shadows!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap& target)
{
    (void)target;
    std::cout<<name_<<": FragTrap..? die!"<<std::endl;
    std::cout<<name_<<": Haaayaaaa!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap& target)
{
    (void)target;
    std::cout<<name_<<": ScavTrap..? die!"<<std::endl;
    std::cout<<name_<<": Time to strike!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap& target)
{
    (void)target;
    std::cout<<name_<<": NinjaTrap..? die!"<<std::endl;
    std::cout<<name_<<": A silent death!"<<std::endl;
}