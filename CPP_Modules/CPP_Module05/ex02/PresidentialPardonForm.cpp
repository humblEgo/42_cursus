/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:40:45 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/29 16:26:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: Form(other.getName(), 25, 5), _target(other.getTarget())
{
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void)other;
    return (*this);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

void PresidentialPardonForm::execute(Bureaucrat const& bureaucrat) const
{
    Form::execute(bureaucrat);
    this->action();
}

void PresidentialPardonForm::action() const
{
    std::string msg;

    msg = this->getTarget() + " has been pardoned by Zafod Beeblebrox.";
    std::cout<<msg<<std::endl;
}