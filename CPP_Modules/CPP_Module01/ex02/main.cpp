/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:50:47 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 22:25:59 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(int argc, char *argv[])
{
    ZombieEvent intp;
    ZombieEvent infj;
    ZombieEvent isfp;
    ZombieEvent isfj;
    Zombie      *intp_zombie;
    Zombie      *infj_zombie;
    Zombie      *isfp_zombie;

    intp.setZombieType("intp");
    infj.setZombieType("infj");
    isfp.setZombieType("isfp");

    intp_zombie = intp.newZombie("iwoo");
    infj_zombie = infj.newZombie("Goethe");
    isfp_zombie = isfp.randomChump();

    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"Umm.. maybe they can't stand this."<<std::endl;
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"You, INTP! Let's talk about my friend's brother's friend's hobby!"<<std::endl;
    delete intp_zombie;
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"You, INFJ! You should kill people and eat it!"<<std::endl;
    delete infj_zombie;
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"You, ISFP! Wake up 6 a.m. on Saturday."<<std::endl;
    delete isfp_zombie;
    std::cout<<"----------------------------------"<<std::endl;
    std::cout<<"Yay! I survived! :)"<<std::endl;
    return (0);
}