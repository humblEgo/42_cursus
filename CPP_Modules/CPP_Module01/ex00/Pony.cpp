/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:03:39 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 16:10:47 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name)
{
    name_ = name;
    age_ = 1;
    color_ = "Brown";
    std::cout<<this->name_<<" is constructed"<<std::endl;
}

Pony::~Pony()
{
    std::cout<<this->name_<<" is destroied"<<std::endl;
    std::cout<<"Rest in peace "<<this->name_<<".."<<std::endl;
}

void    Pony::show_info(void)
{
    std::cout<<"--------------------------"<<std::endl;
    std::cout<<std::setw(10)<<std::left<<"| name"<<": "<<this->name_<<std::endl;
    std::cout<<std::setw(10)<<std::left<<"| age"<<": "<<this->age_<<std::endl;
    std::cout<<std::setw(10)<<std::left<<"| color"<<": "<<this->color_<<std::endl;
    std::cout<<"--------------------------"<<std::endl;
}

void    Pony::eat(void)
{
    std::cout<<this->name_<<" is eating weed"<<std::endl;
}

void    Pony::run(void)
{
    std::cout<<this->name_<<" is running!"<<std::endl;
}

void    Pony::sleep(void)
{
    std::cout<<this->name_<<" is sleeping"<<std::endl;
}
