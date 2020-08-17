/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:09:54 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 22:12:41 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
}

ZombieEvent::~ZombieEvent()
{
}

void    ZombieEvent::setZombieType(std::string type)
{
    this->type_ = type;
}

Zombie*  ZombieEvent::newZombie(std::string name)
{
    try
    {
        Zombie* zombie = new Zombie(name, this->type_);
        return (zombie);
    }
    catch (std::bad_alloc e)
    {
        std::cout<<e.what()<<std::endl;
        std::cout<<"failed to make new zombie(name: "<<name<<")"<<std::endl;
        return (NULL);
    }
}

Zombie* ZombieEvent::randomChump(void)
{
    Zombie      *zombie;
    std::string name;
    std::string name_array[8] = {
        "Avril Lavigne",
        "Michael Jackson",
        "Britney Spears",
        "Jessica Alba",
        "Frida Kahlo",
        "Eowyn",
        "Beatrix kiddo",
        "Kate Austen"
    };

    srand(time(NULL));
    name = name_array[rand() % 8];
    try
    {
        zombie = new Zombie(name, this->type_);
        return (zombie);
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
        std::cout<<"failed to make new zombie(name: "<<name<<")"<<std::endl;
        return (NULL);
    }
}