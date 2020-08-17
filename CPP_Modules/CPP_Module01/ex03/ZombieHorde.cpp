/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 22:30:01 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 23:34:32 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
    std::cout<<"ZombieHorde summon minions!"<<std::endl;
    this->zombie_array = new Zombie[N];
}

ZombieHorde::~ZombieHorde(void)
{
    std::cout<<"ZombieHorde go back!"<<std::endl;
    delete[] this->zombie_array;
}

std::string ZombieHorde::MakeRandomName(void)
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