#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
private:
    std::string name_;
    int         apcost_;
    int         damage_;
public:
    AWeapon(std::string const& name, int apcost, int damage);
    virtual ~AWeapon();
    std::string const& getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;
};

#endif