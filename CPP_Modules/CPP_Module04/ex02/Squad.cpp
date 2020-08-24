/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:16:10 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:16:10 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad()
: count_(0), units_(NULL)
{
}

Squad::Squad(const Squad& other)
: count_(other.getCount())
{
    if (this->units_)
        deleteCurrentUnits();
    this->units_ = new ISpaceMarine*[other.getCount()];
    for (int i = 0; i < other.getCount(); i++)
        *this->units_[i] = *(other.getUnit(i));
}

Squad& Squad::operator=(const Squad& other)
{
    if (this->units_)
        deleteCurrentUnits();
    this->units_ = new ISpaceMarine*[other.getCount() + 1];
    for (int i = 0; i < other.getCount(); i++)
        this->units_[i] = other.getUnit(i)->clone();
    this->count_ = other.getCount();
    return (*this);
}

Squad::~Squad()
{
    if (this->units_)
        deleteCurrentUnits();
}

int Squad::getCount() const
{
    return (this->count_);
}

ISpaceMarine* Squad::getUnit(int idx) const
{
    if (idx >= this->getCount() || idx < 0)
        return (NULL);
    return (this->units_[idx]);
}

int Squad::push(ISpaceMarine *unit)
{
    if (!unit || isAlreadyIn(unit))
        return (this->count_);
    if (this->units_)
    {
        ISpaceMarine **new_squad = new ISpaceMarine*[this->getCount() + 1];
        for (int i = 0; i < this->getCount(); i++)
            new_squad[i] = this->units_[i];
        new_squad[this->getCount()] = unit;
        delete[] this->units_;
        this->units_ = new_squad;
    }
    else
    {
        this->units_ = new ISpaceMarine*[1];
        this->units_[0] = unit;
    }
    this->count_ += 1;
    return (this->count_);
}

void Squad::deleteCurrentUnits()
{
    for (int i = 0; i < this->getCount(); i++)
        delete this->getUnit(i);
    delete[] this->units_;
}

bool Squad::isAlreadyIn(ISpaceMarine *unit) const
{
    for (int i = 0; i < this->getCount(); i++)
    {
        if (this->getUnit(i) == unit)
            return (true);
    }
    return (false);
}