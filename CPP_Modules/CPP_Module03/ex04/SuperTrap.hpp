#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
private:
    /* data */
public:
    SuperTrap(std::string name);
    SuperTrap(const SuperTrap& copy);
    SuperTrap& operator=(const SuperTrap& assign);
    virtual ~SuperTrap(void);

    void rangedAttack(std::string const& target);
    void meleeAttack(std::string const& target);
};

#endif