/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:50:18 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 23:24:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
        :name_(this->MakeRandomName()), type_("minion")
{
    this->announce();
}

Zombie::Zombie(std::string name, std::string type)
        :name_(name), type_(type)
{
    this->announce();
}

Zombie::~Zombie(void)
{
    std::cout<<"<"<<this->name_<<" ("<<this->type_<<")> ";
    std::cout<<"Byebye~ :)"<<std::endl;
}

void    Zombie::announce(void)
{
    std::cout<<"<"<<this->name_<<" ("<<this->type_<<")> ";
    std::cout<<" Braiiiiiiinnnssss..."<<std::endl;
}

std::string Zombie::MakeRandomName(void)
{
    static  std::string chrs = 
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ _";
    std::random_device rd;      // 시드값을 얻기 위한 random_device 생성
    std::mt19937 gen(rd());     // random_device를 통해 난수 생성 엔진을 초기화
    std::uniform_int_distribution<int> pick(0,chrs.length());   // 0부터 chrs길이까지 균등하게 나타나는 난수열을 생성하기 위해 균등분포 정의.
    std::string name;

    for (int i = 0; i < 10; i++)
        name += chrs[pick(gen)];
    return (name);
}