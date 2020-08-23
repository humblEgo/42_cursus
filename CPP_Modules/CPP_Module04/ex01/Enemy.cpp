#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const& type)
: hp_(hp), type_(type)
{
}

Enemy::~Enemy()
{
}

std::string const& Enemy::getType() const
{
    return (this->type_);
}

int Enemy::getHP() const
{
    return (this->hp_);
}

void Enemy::takeDamage(int damage)
{
    if (this->hp_ > damage)
        this->hp_ -= damage;
    else
        this->hp_ = 0;
}