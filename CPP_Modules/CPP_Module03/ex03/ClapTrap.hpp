/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:14:03 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:14:03 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <random>

class ClapTrap
{
private:
    unsigned int    hit_points_;
    unsigned int    max_hit_points_;
    unsigned int    energy_points_;
    unsigned int    max_energy_points_;

protected:
    std::string     name_;
    unsigned int    level_;
    unsigned int    melee_attack_damage_;
    unsigned int    range_attack_damage_;
    unsigned int    armor_damage_reduction_;

    void copy(const ClapTrap& copy);

public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& copy);
    ClapTrap& operator=(const ClapTrap& assign);
    ~ClapTrap(void);

    void setMaxHitPoints(unsigned int max_hit_point);
    void setHitPoints(unsigned int hit_point);
    unsigned int getHitPoints(void) const;
    void raiseHitPoints(unsigned int point);
    void reduceHitPoints(unsigned int point);
    
    void setMaxEnergyPoints(unsigned int max_energy_point);
    void setEnergyPoints(unsigned int energy_point);
    unsigned int getEnergyPoints(void) const;
    void raiseEnergyPoints(unsigned int point);
    void reduceEnergyPoints(unsigned int point);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif