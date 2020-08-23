#ifndef PowerFist_HPP
# define PowerFist_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
    PowerFist(void);
    virtual ~PowerFist(void);
    virtual void attack() const;
};

#endif