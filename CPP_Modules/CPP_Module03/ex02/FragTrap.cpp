/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:13:44 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:13:44 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
    std::cout<<"==========================Constructor"<<std::endl;
    this->setMaxEnergyPoints(100);
    this->setEnergyPoints(100);
    this->melee_attack_damage_ = 30;
    this->range_attack_damage_ = 20;
    this->armor_damage_reduction_ = 5;
    std::cout<<name_<<" has been summoned!"<<std::endl;
    std::cout<<name_<<": Let's get in the fight!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
: ClapTrap(copy.name_)
{
    std::cout<<"==========================copy"<<std::endl;
    this->copy(copy);
}

FragTrap& FragTrap::operator=(const FragTrap& assign)
{
    std::cout<<"==========================assign"<<std::endl;
    name_ = assign.name_;
    this->copy(assign);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout<<"======================Destructor"<<std::endl;
    std::cout<<this->name_<<" died"<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const& target)
{
    if (getEnergyPoints() < 25)
        std::cout<<"Not enough energy!"<<std::endl;
    else
    {
        reduceEnergyPoints(25);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> pick(0, 4);

        std::string attack[5] = {
            "normal attack",
            "Overheating attack",
            "Flamespitter",
            "Electro Harpoon",
            "The Equalizer"
        };
        int         damage[5] = {
            10,
            30,
            60,
            40,
            80
        };
        int random_idx = pick(gen);
        std::cout<<name_<<" attacks "<<target<<" by "<<attack[random_idx];
        std::cout<<", causing "<<damage[random_idx];
        std::cout<<" points of damage!";
        std::cout<<"(EP: "<<getEnergyPoints()<<")"<<std::endl;
    }
}