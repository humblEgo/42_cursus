/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:13:30 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 22:29:17 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signable_grade, int executable_grade)  throw (Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
: _name(name), _signed(false), _signable_grade(signable_grade), _executable_grade(executable_grade)
{
    if (this->_signable_grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_signable_grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form& other)
: _name(other.getName()), _signed(other.isSigned()), 
_signable_grade(other.getSignableGrade()), _executable_grade(other.getExecutableGrade())
{
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

Form& Form::operator=(const Form& other)
{
    this->_signed = other.isSigned();
    return (*this);
}

std::ostream& operator<<(std::ostream& out, Form& other)
{
    out<<"|==========\n";
    out<<"| Form info\n";
    out<<"| - Name              : "<<other.getName()<<"\n";
    out<<"| - Signed            : "<<other.isSigned()<<"\n";
    out<<"| - Signable grade    : "<<other.getSignableGrade()<<"\n";
    out<<"| - Executable grade  : "<<other.getExecutableGrade()<<"\n";
    out<<"|==========";
    return (out<<std::endl);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::isSigned() const
{
    return (this->_signed);
}

int Form::getSignableGrade() const
{
    return (this->_signable_grade);
}

int Form::getExecutableGrade() const
{
    return (this->_executable_grade);
}

/*==========================================================*/
/*###################  Setter functions  ###################*/
/*==========================================================*/

void Form::beSigned(Bureaucrat& bureaucrat) throw (Form::GradeTooLowException, Form::AlreadySignedException)
{
    if (bureaucrat.getGrade() > this->getSignableGrade())
        throw Form::GradeTooLowException();
    if (this->isSigned() == true)
        throw Form::AlreadySignedException();
    _signed = true;
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

const char *Form::GradeTooHighException::what() const throw()
{
    return "FormException: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "FormException: Grade too low";
}

const char *Form::AlreadySignedException::what() const throw()
{
    return "FormException: Already signed";
}