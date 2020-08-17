/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:01:56 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 17:08:36 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    ponyOnTheHeap(void)
{
    Pony *pony;

    pony = new Pony("heapPony");
    pony->show_info();
    pony->eat();
    pony->run();
    pony->sleep();
    delete(pony);
}

void    ponyOnTheStack(void)
{
    Pony pony("stackPony");

    pony.show_info();
    pony.eat();
    pony.run();
    pony.sleep();
}

int main(void)
{
    std::cout<<"=================================="<<std::endl;
    std::cout<<"Let's meet stackPony!"<<std::endl;
    ponyOnTheStack();
    std::cout<<"=================================="<<std::endl;
    std::cout<<"Let's meet heapPony!"<<std::endl;
    ponyOnTheHeap();
    return (0);
}