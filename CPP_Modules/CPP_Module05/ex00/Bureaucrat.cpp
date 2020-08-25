/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 11:27:57 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& name, int grade) throw (Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_name = name;
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) throw (Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    if (other.getGrade() > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else if (other.getGrade() < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_name = other.getName();
    this->_grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->_name = other.getName();
    this->_grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
    return "BureaucrateException: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "BureaucrateException: Grade too low";
}


std::string const& Bureaucrat::getName() const
{
    return (this->_name);
}

int const& Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out<<other.getName()<<", bureaucrat grade "<<other.getGrade();
    return (out);
}

void Bureaucrat::incrementGrade() throw (Bureaucrat::GradeTooHighException)
{
    if (this->getGrade() == HIGHEST_GRADE)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade() throw (Bureaucrat::GradeTooLowException)
{
    if (this->getGrade() == LOWEST_GRADE)
        throw GradeTooLowException();
    this->_grade += 1;
}