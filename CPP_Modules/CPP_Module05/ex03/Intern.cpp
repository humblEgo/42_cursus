/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 22:29:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/29 12:24:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

Intern::Intern()
{
}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

Intern::~Intern()
{
}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

Intern::Intern(const Intern& other)
{
    (void)other;
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

std::string Intern::stringToLower(std::string const source) const
{
    std::string ret;
    
    ret = "";
    for (int i = 0; i < (int)source.length(); i++)
        ret += tolower(source[i]);
    return (ret);
}

Form* Intern::makeShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form* Intern::makeRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form* Intern::makePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form* Intern::makeForm(std::string form_type, std::string target)
throw (NoFormPatternException)
{
    std::string form_pattern[6] = {
        "ShrubberyCreation",
        "Shrubbery Creation",
        "RobotomyRequest",
        "Robotomy Request",
        "PresidentialPardon",
        "Presidential Pardon",
    };

    Form* (Intern::*funcArray[6])(std::string) = {
        &Intern::makeShrubberyCreationForm,
        &Intern::makeShrubberyCreationForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm,
        &Intern::makePresidentialPardonForm
    };

    for (int i = 0; i < 6; i++)
    {
        if (stringToLower(form_pattern[i]) == stringToLower(form_type))
        {
            std::cout<<"Intern creates "<<form_type<<"."<<std::endl;
            return ((this->*funcArray[i])(target));
        }
    }
    throw NoFormPatternException();
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

const char* Intern::NoFormPatternException::what() const throw ()
{
    return "InternException: There is no matching form pattern.";
}

