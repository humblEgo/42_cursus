/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 00:28:31 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/23 00:28:31 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name)
: Victim(name)
{
    std::cout<<"Zog zog."<<std::endl;
}

Peon::Peon(const Peon& other)
: Victim(other)
{
    std::cout<<"Zog zog."<<std::endl;
}

Peon& Peon::operator=(const Peon& other)
{
    Victim::operator=(other);
    return (*this);
}

Peon::~Peon()
{
    std::cout<<"Bleuark..."<<std::endl;
}

std::string Peon::getName(void) const
{
    return (Victim::getName());
}

void Peon::getPolymorphed(void) const
{
    std::cout<<this->getName()<<" has been turned into";
    std::cout<<" a pink pony!"<<std::endl;
}

std::ostream& operator<<(std::ostream& out, Peon& peon)
{
    return (out << peon.introduce() << std::endl);
}