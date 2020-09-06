/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:12:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:12:22 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <map>
#include <algorithm>

class NotFoundException : public std::exception
{
    virtual const char *what() const throw()
    {
        return ("easyFind: Error: target not founded");
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value) throw(NotFoundException)
{
    typename T::iterator ret;

    ret = std::find(container.begin(), container.end(), value);
    if (ret == container.end())
        throw(NotFoundException());
    return (ret);
}

template <typename key_type, typename value_type>
typename std::map<key_type, value_type>::iterator easyfind(std::map<key_type, value_type> &container, int value) throw(NotFoundException)
{
    typename std::map<key_type, value_type>::iterator ret = container.find(value);
    if (ret == container.end())
        throw(NotFoundException());
    return (ret);
}

#endif
