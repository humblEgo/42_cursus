/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:12:37 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:12:37 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
private:
    size_t _length;
    T *_array;

public:
    Array();
    Array(size_t n);
    virtual ~Array();
    Array(Array const &other);

    Array &operator=(const Array &other);
    T &operator[](size_t idx) throw(std::exception);

    size_t getLength() const;
    size_t size() const;
};

#endif