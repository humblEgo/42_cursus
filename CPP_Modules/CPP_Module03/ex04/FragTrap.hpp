#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& assign);
    virtual ~FragTrap(void);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
    void vaulthunter_dot_exe(std::string const& target);
};

#endif