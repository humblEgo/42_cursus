/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:40:54 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 20:58:20 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form(other.getName(), 72, 45), _target(other.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void)other;
    return (*this);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

/*==========================================================*/
/*# Actions                                                #*/
/*==========================================================*/

void RobotomyRequestForm::execute(Bureaucrat const& bureaucrat) const
{
    Form::execute(bureaucrat);
    this->action();
}

void RobotomyRequestForm::action() const
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    std::string msg;

    msg = "* RIZZZZZ, BZZZZZZZZZZ *\n";
    if (dis(gen))
        msg = msg + this->getTarget() + " has been robotomized successfully!";
    else
        msg = msg + "Failed to robotomize " + this->getTarget();
    std::cout<<msg<<std::endl;
}