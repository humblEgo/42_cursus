/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 01:09:16 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:12:27 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <list>
#include <cstdlib>

class Span
{
private:
    std::list<int> _list_of_nums;
    size_t _limit_size;
    size_t _current_size;
    long long _shortest_span;

public:
    Span(unsigned int value);
    virtual ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    class NoEmptySpaceException : public std::exception
    {
        virtual const char *what() const throw();
    };
    class NoSpanToFindException : public std::exception
    {
        virtual const char *what() const throw();
    };

    size_t getLimitSize() const;
    size_t getCurrentSize() const;
    long long getShortestSpan() const;
    std::list<int> &getList();

    void addNumber(int num) throw(NoEmptySpaceException);

    long long shortestSpan() throw(NoSpanToFindException);
    long long longestSpan() throw(NoSpanToFindException);
};

#endif