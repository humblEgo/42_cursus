/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:15:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:15:18 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const& name)
: name_(name), ap_(40), current_weapon_(NULL)
{
}

Character::Character(const Character& other)
: name_(other.getName()), ap_(other.getAP()), current_weapon_(other.getCurrentWeapon())
{
}

Character& Character::operator=(const Character& other)
{
    this->name_ = other.getName();
    this->ap_ = other.getAP();
    this->current_weapon_ = other.getCurrentWeapon();
    return (*this);
}

Character::~Character()
{
}

void Character::attack(Enemy *enemy)
{
    if (!current_weapon_)
        return ;
    int apcost = current_weapon_->getAPCost();
    if (this->ap_ < apcost)
    {
        std::cout<<"Not enough AP!"<<std::endl;
        return ;
    }
    this->ap_ -= apcost;
    std::cout<<this->getName()<<" attacks "<<enemy->getType();
    std::cout<<" with a "<<this->current_weapon_->getName()<<std::endl;
    this->current_weapon_->attack();
    enemy->takeDamage(current_weapon_->getDamage());
    if (enemy->getHP() <= 0)
        delete (enemy);
}

std::string const& Character::getName() const
{
    return (this->name_);
}

int const& Character::getAP() const
{
    return (this->ap_);
}

std::string const Character::getCurrentWeaponName() const
{
    if (!this->current_weapon_)
    {
        const std::string res = "";
        return (res);
    }
    return (this->current_weapon_->getName());
}

AWeapon *Character::getCurrentWeapon() const
{
    return (this->current_weapon_);
}

void Character::recoverAP()
{
    if (this->ap_ >= 30)
        this->ap_ = 40;
    else
        this->ap_ += 10;
}

void Character::equip(AWeapon *weapon)
{
    this->current_weapon_ = weapon;
}

std::ostream const& operator<<(std::ostream& out, Character& character)
{
    out<<character.getName()<<" has ";
    out<<character.getAP()<<" AP and ";
    std::string weapon_name = character.getCurrentWeaponName();
    if (weapon_name.length() == 0)
        out<<"is unarmed";
	else
    	out<<"wields a "<<weapon_name;
    return (out<<std::endl);
}
