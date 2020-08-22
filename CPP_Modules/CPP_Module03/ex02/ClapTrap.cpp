#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
: name_(name), hit_points_(100), max_hit_points_(100), level_(1),
energy_points_(0), max_energy_points_(0), melee_attack_damage_(0),
range_attack_damage_(0), armor_damage_reduction_(0)
{
    std::cout<<"ClapTrap created."<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
: ClapTrap(copy.name_)
{
    std::cout<<"ClapTrap copied."<<std::endl;
    ClapTrap::copy(copy);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& assign)
{
    std::cout<<"ClapTrap assign operator called."<<std::endl;
    name_ = assign.name_;
    ClapTrap::copy(assign);
    return (*this);
}

void ClapTrap::copy(const ClapTrap& other)
{
    hit_points_ = other.hit_points_;
    max_hit_points_ = other.max_hit_points_;
    energy_points_ = other.energy_points_;
    max_energy_points_ = other.max_energy_points_;
    level_ = other.level_;
    melee_attack_damage_ = other.melee_attack_damage_;
    range_attack_damage_ = other.range_attack_damage_;
    armor_damage_reduction_ = other.armor_damage_reduction_;
}

ClapTrap::~ClapTrap()
{
    std::cout<<"ClapTrap destroyed."<<std::endl;
}

void ClapTrap::raiseHitPoints(unsigned int point)
{
    hit_points_ += point;
    if (hit_points_ > max_hit_points_)
        hit_points_ = max_hit_points_;
}

void ClapTrap::reduceHitPoints(unsigned int point)
{
    if (hit_points_ < point)
        hit_points_ = 0;
    else
        hit_points_ -= point;
}

void ClapTrap::setMaxEnergyPoints(unsigned int max_energy_point)
{
    max_energy_points_ = max_energy_point;
}

void ClapTrap::setEnergyPoints(unsigned int energy_point)
{
    if (energy_point > max_energy_points_)
    {
        std::cout<<"Energy point cannot exceed max_energy_point.";
        std::cout<<"Energy_point is adjusted to max_energy_point."<<std::endl;
    }
    raiseEnergyPoints(energy_point);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (energy_points_);
}

void ClapTrap::raiseEnergyPoints(unsigned int point)
{
    energy_points_ += point;
    if (energy_points_ > max_energy_points_)
        energy_points_ = max_energy_points_;
}

void ClapTrap::reduceEnergyPoints(unsigned int point)
{
    if (energy_points_ < point)
        energy_points_ = 0;
    else
        energy_points_ -= point;
}

void ClapTrap::rangedAttack(std::string const& target)
{
    std::cout<<name_<<" attacks "<<target<<" at range, ";
    std::cout<<"causing "<<range_attack_damage_;
    std::cout<<" points of damage!"<<std::endl;
}

void ClapTrap::meleeAttack(std::string const& target)
{
    std::cout<<name_<<" attacks "<<target<<" at melee, ";
    std::cout<<"causing "<<melee_attack_damage_;
    std::cout<<" points of damage!"<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    amount = (amount > armor_damage_reduction_) ? amount - armor_damage_reduction_ : 0;
    reduceHitPoints(amount);
    std::cout<<name_<<" is attacked, taking ";
    std::cout<<amount<<" points of damage!";
    std::cout<<"(HP: "<<hit_points_<<")"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    raiseHitPoints(amount);
    std::cout<<name_<<" is repaired, recovering ";
    std::cout<<amount<<" points of hit_points!";
    std::cout<<"(HP: "<<hit_points_<<")"<<std::endl;
}
