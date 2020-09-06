/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:12:11 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/07 01:01:26 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int value)
    : _limit_size(value), _current_size(0), _shortest_span(-42)
{
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
    *this = other;
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

Span &Span::operator=(const Span &other)
{
    this->_limit_size = other.getLimitSize();
    this->_current_size = other.getCurrentSize();
    this->_shortest_span = other.getShortestSpan();
    this->_list_of_nums = other._list_of_nums; //Don't worry, it's deep copy
    return (*this);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

size_t Span::getLimitSize() const
{
    return (this->_limit_size);
}

size_t Span::getCurrentSize() const
{
    return (this->_current_size);
}

long long Span::getShortestSpan() const
{
    return (this->_shortest_span);
}

std::list<int> &Span::getList()
{
    return (this->_list_of_nums);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

void Span::addNumber(int num) throw(NoEmptySpaceException)
{
    std::list<int> &list = this->_list_of_nums;
    if (this->getLimitSize() == this->getCurrentSize())
        throw(NoEmptySpaceException());
    if (this->getCurrentSize() == 0)
        list.push_back(num);
    else
    {
        std::list<int>::iterator itr;
        for (itr = list.begin(); itr != list.end(); itr++)
        {
            if (this->getShortestSpan() < 0 || std::abs((long long)*itr - (long long)num) < this->getShortestSpan())
                this->_shortest_span = std::abs((long long)*itr - (long long)num);
            if (num <= *itr)
            {
                list.insert(itr, num);
                this->_current_size += 1;
                return;
            }
        }
        list.push_back(num);
    }
    this->_current_size += 1;
}

void Span::addNumber(int begin, int end) throw(InvalidRangeException, NoEmptySpaceException)
{
    if (begin > end)
        throw(InvalidRangeException());
    for (int i = begin; i < end; i++)
        Span::addNumber(i);
}

void Span::addNumberOfRange(size_t range) throw(InvalidRangeException, NoEmptySpaceException)
{
    if (range > this->getLimitSize())
        throw(InvalidRangeException());
    for (int i = 0; i < static_cast<int>(range); i++)
        Span::addNumber(i);
}

long long Span::shortestSpan() throw(NoSpanToFindException)
{
    size_t cur_size = this->getCurrentSize();
    if (cur_size == 0 || cur_size == 1)
        throw(Span::NoSpanToFindException());
    return (this->_shortest_span);
}

long long Span::longestSpan() throw(NoSpanToFindException)
{
    size_t cur_size = this->getCurrentSize();
    if (cur_size == 0 || cur_size == 1)
        throw(Span::NoSpanToFindException());
    return ((long long)(this->getList().back()) - (long long)(this->getList().front()));
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

Span::NoEmptySpaceException::NoEmptySpaceException() throw() {}
Span::NoEmptySpaceException::~NoEmptySpaceException() throw() {}
Span::NoEmptySpaceException::NoEmptySpaceException(const NoEmptySpaceException &) throw() {}
Span::NoEmptySpaceException &Span::NoEmptySpaceException::operator=(const NoEmptySpaceException &) throw() { return (*this); }
const char *Span::NoEmptySpaceException::what() const throw()
{
    return ("Span: Error: Cannot add number since there is no empty space");
}

Span::NoSpanToFindException::NoSpanToFindException() throw() {}
Span::NoSpanToFindException::~NoSpanToFindException() throw() {}
Span::NoSpanToFindException::NoSpanToFindException(const NoSpanToFindException &) throw() {}
Span::NoSpanToFindException &Span::NoSpanToFindException::operator=(const NoSpanToFindException &) throw() { return (*this); }
const char *Span::NoSpanToFindException::what() const throw()
{
    return ("Span: Error: No span to find since list is empty or has one integer");
}

Span::InvalidRangeException::InvalidRangeException() throw() {}
Span::InvalidRangeException::~InvalidRangeException() throw() {}
Span::InvalidRangeException::InvalidRangeException(const InvalidRangeException &) throw() {}
Span::InvalidRangeException &Span::InvalidRangeException::operator=(const InvalidRangeException &) throw() { return (*this); }
const char *Span::InvalidRangeException::what() const throw()
{
    return ("Span: Error: Invalid range");
}
