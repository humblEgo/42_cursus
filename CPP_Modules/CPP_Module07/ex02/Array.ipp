/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:44:17 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/28 15:21:14 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
: _length(0)
{
    this->_array = new T[0];
}

template <typename T>
Array<T>::Array(size_t n)
: _length(n), _array(nullptr)
{
    this->_array = new T[this->_length];
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->_array;
}

template <typename T>
Array<T>::Array(Array const& other)
: _length(0)
{
    this->_array = new T[0];  // 이걸 넣었어야했다.
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    delete[] (this->_array);
    this->_length = other.getLength();
    this->_array = new T[other.getLength()];
    for (size_t i = 0; i < other.getLength(); i++)
        this->_array[i] = other._array[i];
    return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t idx) throw (std::exception)
{
    if (!this->_array || idx >= this->_length)
		throw std::out_of_range("ArrayIdxError: out of range.");
	return (this->_array[idx]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->_length);
}

template <typename T>
size_t Array<T>::getLength() const
{
    return (this->_length);
}