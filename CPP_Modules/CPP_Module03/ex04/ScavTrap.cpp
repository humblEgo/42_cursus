#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string  name)
 : ClapTrap(name)
{
    setMaxHitPoints(100);
    setHitPoints(100);
    setMaxEnergyPoints(50);
    setEnergyPoints(50);
    melee_attack_damage_ = 20;
    range_attack_damage_ = 15;
    armor_damage_reduction_ = 3;
    std::cout<<name_<<"(ScavTrap) has been summoned!"<<std::endl;
    std::cout<<name_<<": The time of man has come to an end."<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
: ClapTrap(copy.name_)
{
    this->copy(copy);
}

ScavTrap& ScavTrap::operator=(const ScavTrap& assign)
{
    this->copy(assign);
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout<<name_<<"(ScavTrap) died"<<std::endl;
    std::cout<<name_<<": Bone is a poor alternative."<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void ScavTrap::challengeNewcomer(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> pick(0, 7);

    std::string challenges[8] = {
        "Metal is harder than flesh.",
        "Bone is a poor alternative.",
        "Look. You're leaking.",
        "Your steam is escaping.",
        "Quake in fear, fleshling.",
        "Exterminate, Exterminate.",
        "HA HA HA HA.",
        "I put the 'go' in 'golem'. That was humor. Other golems find that to be appropriately funny."
    };
    std::cout<<name_<<": ";
    std::cout<<challenges[pick(gen)]<<std::endl;
}

void ScavTrap::rangedAttack(std::string const& target)
{
    std::cout<<name_<<": Static field."<<std::endl;
    ClapTrap::rangedAttack(target);
}

void ScavTrap::meleeAttack(std::string const& target)
{
    std::cout<<name_<<": Rocket grab."<<std::endl;
    ClapTrap::meleeAttack(target);
}