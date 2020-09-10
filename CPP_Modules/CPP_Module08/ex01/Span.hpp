/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 01:09:16 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/10 10:57:56 by iwoo             ###   ########.fr       */
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
    explicit Span(unsigned int value);
    explicit Span(int value);
    virtual ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    class NoEmptySpaceException : public std::exception
    {
    public:
        NoEmptySpaceException() throw();
        virtual ~NoEmptySpaceException() throw();
        NoEmptySpaceException(const NoEmptySpaceException &) throw();
        NoEmptySpaceException &operator=(const NoEmptySpaceException &) throw();
        virtual const char *what() const throw();
    };
    class NoSpanToFindException : public std::exception
    {
    public:
        NoSpanToFindException() throw();
        virtual ~NoSpanToFindException() throw();
        NoSpanToFindException(const NoSpanToFindException &) throw();
        NoSpanToFindException &operator=(const NoSpanToFindException &) throw();
        virtual const char *what() const throw();
    };
    class InvalidRangeException : public std::exception
    {
    public:
        InvalidRangeException() throw();
        virtual ~InvalidRangeException() throw();
        InvalidRangeException(const InvalidRangeException &) throw();
        InvalidRangeException &operator=(const InvalidRangeException &) throw();
        virtual const char *what() const throw();
    };
    class NegativeSizeException : public std::exception
    {
    public:
        NegativeSizeException() throw();
        virtual ~NegativeSizeException() throw();
        NegativeSizeException(const NegativeSizeException &) throw();
        NegativeSizeException &operator=(const NegativeSizeException &) throw();
        virtual const char *what() const throw();
    };


    size_t getLimitSize() const;
    size_t getCurrentSize() const;
    long long getShortestSpan() const;
    std::list<int> &getList();

    void addNumber(int num) throw(NoEmptySpaceException);
    void addNumber(int begin, int end) throw(InvalidRangeException, NoEmptySpaceException);
    void addNumberOfRange(size_t range) throw(InvalidRangeException, NoEmptySpaceException);

    long long shortestSpan() throw(NoSpanToFindException);
    long long longestSpan() throw(NoSpanToFindException);
};

#endif
