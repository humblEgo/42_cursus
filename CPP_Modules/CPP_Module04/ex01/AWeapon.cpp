#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const& name, int apcost, int damage)
: name_(name), apcost_(apcost), damage_(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string const& AWeapon::getName(void) const
{
    return (this->name_);
}

int AWeapon::getAPCost(void) const
{
    return (this->apcost_);
}

int AWeapon::getDamage(void) const
{
    return (this->damage_);
}