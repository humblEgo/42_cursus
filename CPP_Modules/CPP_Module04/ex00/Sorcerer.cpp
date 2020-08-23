/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:28:21 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/23 00:28:24 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
: name_(name), title_(title)
{
    std::cout<<this->name_<<", "<<this->title_<<", is born!"<<std::endl;
}

Sorcerer::Sorcerer(const Sorcerer& other)
: name_(other.name_), title_(other.title_)
{
}

Sorcerer& Sorcerer::operator=(const Sorcerer& other)
{
    this->name_ = other.name_;
    this->title_ = other.title_;
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Sorcerer& sorcerer)
{
    return (out << sorcerer.introduce() << std::endl);
}

Sorcerer::~Sorcerer()
{
    std::cout<<this->name_<<", "<<this->title_<<", is dead.";
    std::cout<<" Consequences will never be the same!"<<std::endl;
}

std::string Sorcerer::getName(void) const
{
    return (this->name_);
}

std::string Sorcerer::getTitle(void) const
{
    return (this->title_);
}

std::string Sorcerer::introduce(void) const
{
    std::string message;

    message = "I am " + this->getName() + ", " + this->getTitle() +
                ", and I like ponies!";
    return (message);
}

void Sorcerer::polymorph(Victim const& victim) const
{
    victim.getPolymorphed();
}

void Sorcerer::polymorph(std::string& something) const
{
    std::cout<<this->getName()<<" used a polymorphic spell!"<<std::endl;
    std::cout<<this->getTitle()<<" has been turned into";
    std::cout<<" the(a) "<<something<<"!"<<std::endl;
}   