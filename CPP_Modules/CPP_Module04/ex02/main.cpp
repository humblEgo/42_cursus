/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 22:16:06 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/24 22:16:07 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
    std::cout<<"=============================================Subject example"<<std::endl;
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
    ISpaceMarine* cur = vlc->getUnit(i);
    cur->battleCry();
    cur->rangedAttack();
    cur->meleeAttack();
    }
    delete vlc;

//    std::cout<<"=============================================Custom example"<<std::endl;
//    ISpaceMarine* jin = new TacticalMarine;
//    ISpaceMarine* suga = new TacticalMarine;
//    ISpaceMarine* j_hope = new TacticalMarine;
//    ISpaceMarine* rm = new TacticalMarine;
//    ISpaceMarine* jimin = new AssaultTerminator;
//    ISpaceMarine* v = new AssaultTerminator;
//    ISpaceMarine* jungkook = new AssaultTerminator;
//    ISquad* bangtanboys = new Squad;
//    bangtanboys->push(jin);
//    bangtanboys->push(suga);
//    bangtanboys->push(j_hope);
//    bangtanboys->push(rm);
//    bangtanboys->push(jimin);
//    bangtanboys->push(v);
//    bangtanboys->push(jungkook);
//
//    std::cout<<"=============================================push valid check"<<std::endl;
//    bangtanboys->push(jungkook);
//    bangtanboys->push(NULL);
//
//    for (int i = 0; i < bangtanboys->getCount(); i++)
//    {
//        ISpaceMarine* cur = bangtanboys->getUnit(i);
//        cur->battleCry();
//        cur->rangedAttack();
//        cur->meleeAttack();
//    }
//
//    std::cout<<"=============================================deep copy"<<std::endl;
//    ISquad* bts = new Squad;
//    *(Squad *)bts = *(Squad *)bangtanboys;
//
//    for (int i = 0; i < bts->getCount(); i++)
//    {
//        ISpaceMarine* cur = bts->getUnit(i);
//        cur->battleCry();
//        cur->rangedAttack();
//        cur->meleeAttack();
//    }
//    delete bts;
//    delete bangtanboys;
//
    return 0;
}
