/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:57 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/29 12:25:10 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

Bureaucrat::Bureaucrat(std::string const& name, int grade)
throw (Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_name = name;
    this->_grade = grade;
}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

Bureaucrat::~Bureaucrat()
{
}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

Bureaucrat::Bureaucrat(const Bureaucrat& other)
throw (Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    if (other.getGrade() > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else if (other.getGrade() < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_name = other.getName();
    this->_grade = other.getGrade();
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->_name = other.getName();
    this->_grade = other.getGrade();
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out<<other.getName()<<", bureaucrat grade "<<other.getGrade()<<std::endl;
    return (out);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string const& Bureaucrat::getName() const
{
    return (this->_name);
}

int const& Bureaucrat::getGrade() const
{
    return (this->_grade);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

void Bureaucrat::incrementGrade() 
throw (Bureaucrat::GradeTooHighException)
{
    if (this->getGrade() == HIGHEST_GRADE)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade() 
throw (Bureaucrat::GradeTooLowException)
{
    if (this->getGrade() == LOWEST_GRADE)
        throw GradeTooLowException();
    this->_grade += 1;
}

void Bureaucrat::signForm(Form* form)
throw (CannotSignToNullptr)
{
    try
    {
        if (form == nullptr)
            throw CannotSignToNullptr();
        form->beSigned(*this);
        std::cout<<this->getName();
        std::cout<<" signs form("<<form->getName()<<")."<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::string form_name;

        if (form == nullptr)
            form_name = "* NULL *";
        else
            form_name = form->getName();
        std::cerr<<this->getName();
        std::cerr<<" cannot sign form("<<form_name<<")."<<std::endl;
        throw;
    }
}

void Bureaucrat::executeForm(Form const& form)
throw ()
{
    std::string msg;
    form.execute(*this);

    msg = this->getName() + " executes form(" + form.getName() + ")";
    std::cout<<msg<<std::endl;
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
    return "BureaucrateException: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
    return "BureaucrateException: Grade too low";
}

const char* Bureaucrat::CannotSignToNullptr::what() const throw ()
{
    return "BureaucrateException: Can't sign to nullptr";
}
