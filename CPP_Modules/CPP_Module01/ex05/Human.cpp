/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:35:51 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/19 18:47:43 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
}

Human::~Human()
{
}

std::string Human::identify(void)
{
    return (this->brain.identify());
}

const Brain &Human::getBrain(void) const
{
    return (this->brain);
}