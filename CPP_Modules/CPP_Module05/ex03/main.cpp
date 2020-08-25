/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:53 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 22:27:20 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat* kangmin = nullptr;
    try
    {
        std::cout<<"\n==========================Create bureaucrat "<<std::endl;
        kangmin = new Bureaucrat("kangmin", 20);
        std::cout<<*kangmin<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Form *shrubbery_form;    
    try
    {
        std::cout<<"\n==========================Shrubbery case"<<std::endl;
        std::cout<<*kangmin<<std::endl;
        shrubbery_form = new ShrubberyCreationForm("target");
        kangmin->signForm(shrubbery_form);
        std::cout<<*shrubbery_form;
        kangmin->executeForm(*shrubbery_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (shrubbery_form != nullptr)
        delete (shrubbery_form);

    Form *robotomy_form;
    try
    {
        std::cout<<"\n==========================Robotomy case"<<std::endl;
        std::cout<<*kangmin<<std::endl;
        robotomy_form = new RobotomyRequestForm("target");
        kangmin->signForm(robotomy_form);
        std::cout<<*robotomy_form;
        kangmin->executeForm(*robotomy_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (robotomy_form != nullptr)
        delete (robotomy_form);

    Form *presidential_form;
    try
    {
        std::cout<<"\n==========================Presidential case"<<std::endl;

        std::cout<<*kangmin<<std::endl;
        std::cout<<"Increment to no.1!"<<std::endl;
        for (int i = 0; i < 19; i++)
            kangmin->incrementGrade();
        std::cout<<*kangmin<<std::endl;

        presidential_form = new PresidentialPardonForm("target");
        kangmin->signForm(presidential_form);
        std::cout<<*presidential_form;
        kangmin->executeForm(*presidential_form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (presidential_form != nullptr)
        delete (presidential_form);
    if (kangmin != nullptr)
        delete (kangmin);

    Intern someRandomIntern;
    Form* form = nullptr;
    try
    {
        std::cout<<"\n==========================Intern case"<<std::endl;
        /*
            You can use below form_type as the makeForm functions's first argument regardless of the case of alphabet.
            "ShrubberyCreation",
            "Shrubbery Creation",
            "RobotomyRequest",
            "Robotomy Request",
            "PresidentialPardon",
            "Presidential Pardon"
        */
        form = someRandomIntern.makeForm("Presidential pardon", "Home");
        std::cout<<*form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if  (form != nullptr)
        delete (form);
    
    return (0); 
}