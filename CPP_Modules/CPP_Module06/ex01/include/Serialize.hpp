/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:13:20 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:13:20 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <random>
#include <cstdlib>
#include <limits>

typedef struct Data
{
    std::string s1;
    int n;
    std::string s2;
} Data;

void *serialize(void);
Data *deserialize(void *raw);

#endif