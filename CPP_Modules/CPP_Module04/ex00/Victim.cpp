/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:28:33 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/23 00:28:34 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(std::string name)
: name_(name)
{
    std::cout<<"Some random victim called "<<this->name_;
    std::cout<<" just appeared!"<<std::endl;
}

Victim::Victim(const Victim& other)
: name_(other.name_)
{
}

Victim& Victim::operator=(const Victim& other)
{
    this->name_ = other.name_;
    return (*this);
}

Victim::~Victim()
{
    std::cout<<"Victim "<<this->name_;
    std::cout<<" just died for no apparent reason!"<<std::endl;
}

std::string Victim::introduce(void) const
{
    std::string message;

    message = "I'm " + this->getName() + " and I like otters!";
    return (message);
}

std::string Victim::getName(void) const
{
    return (this->name_);
}

void Victim::getPolymorphed(void) const
{
    std::cout<<this->getName()<<" has been turned into";
    std::cout<<" a cute little sheep!"<<std::endl;
}

std::ostream& operator<<(std::ostream& out, Victim& victim)
{
    return (out << victim.introduce() << std::endl);
}