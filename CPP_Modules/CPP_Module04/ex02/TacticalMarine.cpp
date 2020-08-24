/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:16:15 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:16:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    std::cout<<"Tactical Marine ready for battle!"<<std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine& other)
{
    (void)other;
    std::cout<<"Tactical Marine ready for battle!"<<std::endl;
}

TacticalMarine& TacticalMarine::operator=(const TacticalMarine& other)
{
    (void)other;
    return (*this);
}

TacticalMarine::~TacticalMarine()
{
    std::cout<<"Aaargh..."<<std::endl;
}

ISpaceMarine *TacticalMarine::clone() const 
{
    TacticalMarine *clone = new TacticalMarine(*this);
    return (clone);
}

void TacticalMarine::battleCry() const
{
    std::cout<<"For the holy PLOT!"<<std::endl;
}

void TacticalMarine::rangedAttack() const
{
    std::cout<<"* attacks with a bolter *"<<std::endl;
}

void TacticalMarine::meleeAttack() const
{
    std::cout<<"* attacks with a chainsword *"<<std::endl;
}
