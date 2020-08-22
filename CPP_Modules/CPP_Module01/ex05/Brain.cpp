/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:35:54 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 18:48:53 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain::~Brain(void)
{
}

std::string Brain::identify(void) const
{
    const long address = (long)this;

    std::stringstream res;
    res << "0x" << std::uppercase << std::hex << address;
    return (res.str());
}