#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <random>

class FragTrap
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