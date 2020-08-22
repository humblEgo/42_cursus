#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& assign);
    ~ScavTrap(void);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void challengeNewcomer(void);
};

#endif