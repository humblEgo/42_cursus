/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:53 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/29 16:30:46 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat* kangmin = nullptr;
    try
    {
        std::cout<<"\033[1;37;41m"<<"Create bureaucrat"<<"\033[0m"<<std::endl;
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
        std::cout<<"\033[1;37;41m"<<"Shrubbery case"<<"\033[0m"<<std::endl;
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
        std::cout<<"\033[1;37;41m"<<"Robotomy case"<<"\033[0m"<<std::endl;
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
        std::cout<<"\033[1;37;41m"<<"Presiential case"<<"\033[0m"<<std::endl;

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
    
    return (0); 
}