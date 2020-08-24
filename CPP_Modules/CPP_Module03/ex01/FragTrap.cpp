/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:13:24 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:13:24 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string  name)
:hit_points_(100), max_hit_points_(100), energy_points_(100),
 max_energy_points_(100), level_(1), name_(name), melee_attack_damage_(30),
 range_attack_damage_(20), armor_damage_reduction_(5)
{
    std::cout<<"==========================Constructor"<<std::endl;
    std::cout<<name_<<" has been summoned!"<<std::endl;
    std::cout<<"Let's get in the fight!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
    std::cout<<"==========================copy"<<std::endl;
    *this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& assign)
{
    std::cout<<"==========================assign"<<std::endl;
    hit_points_ = assign.hit_points_;
    max_hit_points_ = assign.max_hit_points_;
    energy_points_ = assign.energy_points_;
    max_energy_points_ = assign.max_energy_points_;
    level_ = assign.level_;
    melee_attack_damage_ = assign.melee_attack_damage_;
    range_attack_damage_ = assign.range_attack_damage_;
    armor_damage_reduction_ = assign.armor_damage_reduction_;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout<<"======================Destructor"<<std::endl;
    std::cout<<name_<<" died"<<std::endl;
    std::cout<<name_<<": Ahaaaaaaaaaaaaaa~"<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void FragTrap::rangedAttack(std::string const& target)
{
    std::cout<<name_<<": Equalizer missile lunch!"<<std::endl;
    std::cout<<name_<<" attacks "<<target<<" at range, ";
    std::cout<<"causing "<<range_attack_damage_;
    std::cout<<" points of damage!"<<std::endl;
}

void FragTrap::meleeAttack(std::string const& target)
{
    std::cout<<name_<<": Facial explosion rays!"<<std::endl;
    std::cout<<name_<<" attacks "<<target<<" at melee, ";
    std::cout<<"causing "<<melee_attack_damage_;
    std::cout<<" points of damage!"<<std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    amount = (amount > armor_damage_reduction_) ? amount - armor_damage_reduction_ : 0;
    hit_points_ = (hit_points_ <= amount) ? 0 : hit_points_ - amount;
    std::cout<<name_<<" is attacked, taking ";
    std::cout<<amount<<" points of damage!";
    std::cout<<"(HP: "<<hit_points_<<")"<<std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    hit_points_ = (hit_points_ + amount > max_hit_points_) ? max_hit_points_ : hit_points_ += amount;
    std::cout<<name_<<" is repaired, recovering ";
    std::cout<<amount<<" points of hit_points!";
    std::cout<<"(HP: "<<hit_points_<<")"<<std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const& target)
{
    if (energy_points_ < 25)
    {
        std::cout<<"Not enough energy!"<<std::endl;
    }
    else
    {
        energy_points_ -= 25;

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
        std::cout<<"(EP: "<<energy_points_<<")"<<std::endl;
    }
}