/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:16:28 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:16:29 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
: _name(name)
{
    for (int i = 0; i < SLOT_SIZE; i++)
        this->_inventory[i] = nullptr;
}

Character::Character(const Character& other)
: _name(other.getName())
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (other._inventory[i] == nullptr)
            this->_inventory[i] = nullptr;
        else
            this->_inventory[i] = other._inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& other)
{
    this->_name = other.getName();
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (other._inventory[i] == nullptr)
            this->_inventory[i] = nullptr;
        else
            this->_inventory[i] = other._inventory[i]->clone();
    }
    return (*this);
}

Character::~Character()
{
}

std::string const& Character::getName() const 
{
    return (this->_name);
}

void Character::equip(AMateria* materia)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (this->_inventory[i] == nullptr)
        {
            this->_inventory[i] = materia;
            return ;
        }
    }
    std::cout<<"Inventory is full!"<<std::endl;
}

void Character::unequip(int idx)
{
    if (idx > SLOT_SIZE - 1 || idx < 0)
    {
        std::cout<<"Invalid idx!"<<std::endl;
        return ;
    }
    this->_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= SLOT_SIZE || idx < 0)
    {
        std::cout<<"Invalid idx!"<<std::endl;
        return ;
    }
    if (this->_inventory[idx] == nullptr)
    {
        std::cout<<"Can't use mataria, Inventory["<<idx<<"] is empty!"<<std::endl;
        return ;
    }
    this->_inventory[idx]->use(target);
}