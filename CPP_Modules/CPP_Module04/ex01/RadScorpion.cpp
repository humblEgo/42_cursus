#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
: Enemy(80, "RadScorpion")
{
    std::cout<<"* click click click *"<<std::endl;
}

RadScorpion::~RadScorpion()
{
    std::cout<<"* SPROTCH *"<<std::endl;
}

void RadScorpion::takeDamage(int damage)
{
    damage = damage > 3 ? damage - 3 : 0;
    Enemy::takeDamage(damage);
}