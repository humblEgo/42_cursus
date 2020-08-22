#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string  name)
:hit_points_(100), max_hit_points_(100), energy_points_(50),
 max_energy_points_(50), level_(1), name_(name), melee_attack_damage_(20),
 range_attack_damage_(15), armor_damage_reduction_(3)
{
    std::cout<<"==========================Constructor"<<std::endl;
    std::cout<<name_<<" has been summoned!"<<std::endl;
    std::cout<<"The time of man has come to an end."<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
    std::cout<<"==========================copy"<<std::endl;
    *this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& assign)
{
    std::cout<<"==========================assign"<<std::endl;
    hit_points_ = assign.hit_points_;
    max_hit_points_ = assign.max_hit_points_;
    energy_points_ = assign.energy_points_;
    max_energy_points_ = assign.max_energy_points_;
    level_ = assign.level_;
    melee_attack_damage_ = assign.melee_attack_damage_;
    range_attack_damage_ = assign.range_attack_damage_;
    armor_damage_reduction_ = assign.armor_damage_reduction_;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout<<"======================Destructor"<<std::endl;
    std::cout<<name_<<" died"<<std::endl;
    std::cout<<name_<<": Bone is a poor alternative."<<std::endl;
    std::cout<<"An ally has been slain"<<std::endl;
}

void ScavTrap::rangedAttack(std::string const& target)
{
    std::cout<<name_<<": Static Field."<<std::endl;
    std::cout<<name_<<" attacks "<<target<<" at range, ";
    std::cout<<"causing "<<range_attack_damage_;
    std::cout<<" points of damage!"<<std::endl;
}

void ScavTrap::meleeAttack(std::string const& target)
{
    std::cout<<name_<<": Rocket grab."<<std::endl;
    std::cout<<name_<<" attacks "<<target<<" at melee, ";
    std::cout<<"causing "<<melee_attack_damage_;
    std::cout<<" points of damage!"<<std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    amount = (amount > armor_damage_reduction_) ? amount - armor_damage_reduction_ : 0;
    hit_points_ = (hit_points_ <= amount) ? 0 : hit_points_ - amount;
    std::cout<<name_<<" is attacked, taking ";
    std::cout<<amount<<" points of damage!";
    std::cout<<"(HP: "<<hit_points_<<")"<<std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    hit_points_ = (hit_points_ + amount > max_hit_points_) ? max_hit_points_ : hit_points_ += amount;
    std::cout<<name_<<" is repaired, recovering ";
    std::cout<<amount<<" points of hit_points!";
    std::cout<<"(HP: "<<hit_points_<<")"<<std::endl;
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