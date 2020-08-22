#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name)
: ClapTrap(name)
{
    setMaxHitPoints(60);
    setHitPoints(60);
    setMaxEnergyPoints(120);
    setEnergyPoints(120);
    melee_attack_damage_ = 60;
    range_attack_damage_ = 5;
    armor_damage_reduction_ = 0;
    std::cout<<name_<<"(NinjaTrap) has been summoned!"<<std::endl;
    std::cout<<name_<<": The eyes never lie."<<std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& copy)
: ClapTrap(copy.name_)
{
    this->copy(copy);
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& assign)
{
    name_ = assign.name_;
    this->copy(assign);
    return (*this);
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout<<this->name_<<"(NinjaTrap) died"<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap& target)
{
    std::cout<<name_<<": ClapTrap..? die!"<<std::endl;
    std::cout<<name_<<": From the shadows!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap& target)
{
    std::cout<<name_<<": FragTrap..? die!"<<std::endl;
    std::cout<<name_<<": Haaayaaaa!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap& target)
{
    std::cout<<name_<<": ScavTrap..? die!"<<std::endl;
    std::cout<<name_<<": Time to strike!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap& target)
{
    std::cout<<name_<<": NinjaTrap..? die!"<<std::endl;
    std::cout<<name_<<": A silent death!"<<std::endl;
}

void NinjaTrap::rangedAttack(std::string const& target)
{
    std::cout<<name_<<": Slicing Maelstrom!!!"<<std::endl;
    ClapTrap::rangedAttack(target);
}

void NinjaTrap::meleeAttack(std::string const& target)
{
    std::cout<<name_<<": Thundering shuriken!"<<std::endl;
    ClapTrap::meleeAttack(target);
}