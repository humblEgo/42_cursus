/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:35:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 18:46:56 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
    Human   bob;

    std::cout<<bob.identify()<<std::endl;
    std::cout<<bob.getBrain().identify()<<std::endl;

    return (0);
}