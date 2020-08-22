#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
    NinjaTrap(std::string name);
    NinjaTrap(const NinjaTrap& copy);
    NinjaTrap& operator=(const NinjaTrap& assign);
    ~NinjaTrap(void);
    void ninjaShoebox(ClapTrap& target);
    void ninjaShoebox(FragTrap& target);
    void ninjaShoebox(ScavTrap& target);
    void ninjaShoebox(NinjaTrap& target);
};

#endif