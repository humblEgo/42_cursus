/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:13:34 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:13:34 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <random>

class ScavTrap
{
private:
    unsigned int        hit_points_;
    unsigned int        max_hit_points_;
    unsigned int        energy_points_;
    unsigned int        max_energy_points_;
    unsigned int        level_;
    std::string         name_;
    unsigned int        melee_attack_damage_;
    unsigned int        range_attack_damage_;
    unsigned int        armor_damage_reduction_;

public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& assign);
    ~ScavTrap(void);
    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void challengeNewcomer(void);
};

#endif