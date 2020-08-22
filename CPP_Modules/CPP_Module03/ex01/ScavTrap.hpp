#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <random>

class ScavTrap
{
private:
    int             hit_points_;
    int             max_hit_points_;
    unsigned int    energy_points_;
    int             max_energy_points_;
    int             level_;
    std::string     name_;
    int             melee_attack_damage_;
    int             range_attack_damage_;
    int             armor_damage_reduction_;

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