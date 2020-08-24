#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <random>

class FragTrap
{
private:
    unsigned int    hit_points_;
    unsigned int    max_hit_points_;
    unsigned int    energy_points_;
    unsigned int    max_energy_points_;
    unsigned int    level_;
    std::string     name_;
    unsigned int    melee_attack_damage_;
    unsigned int    range_attack_damage_;
    unsigned int    armor_damage_reduction_;

public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& assign);
    ~FragTrap(void);
    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void vaulthunter_dot_exe(std::string const& target);
};

#endif