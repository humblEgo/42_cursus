/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:53 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 20:24:54 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

    if (kangmin != nullptr)
        delete (kangmin);
    
    return (0); 
}