/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:53 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/29 16:24:22 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat* kangmin = nullptr;
    try
    {
        std::cout<<"\033[1;37;41m"<<"Handle Grade"<<"\033[0m"<<std::endl;
        kangmin = new Bureaucrat("kangmin", 1);
        kangmin->decrementGrade();
        kangmin->decrementGrade();
        kangmin->decrementGrade();
        kangmin->incrementGrade();
        std::cout<<*kangmin<<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Form* form1 = nullptr;
    try
    {
        std::cout<<"\033[1;37;41m"<<"Signable form"<<"\033[0m"<<std::endl;
        form1 = new Form("Income audit", 3, 3);
        std::cout<<*form1;

        kangmin->signForm(form1);

        std::cout<<*form1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout<<"\033[1;37;41m"<<"Already signed"<<"\033[0m"<<std::endl;
        std::cout<<*form1;
        kangmin->signForm(form1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (form1 != nullptr)
        delete (form1);

    Form* form2 = nullptr;
    try
    {
        std::cout<<"\033[1;37;41m"<<"Grade too low"<<"\033[0m"<<std::endl;

        std::cout<<*kangmin;

        form2 = new Form("Support fund increase plan", 2, 2);
        std::cout<<*form2;

        kangmin->signForm(form2);
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.Form::GradeTooLowException::what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (form2 != nullptr)
        delete (form2);

    Form* form3 = nullptr;
    try
    {
        std::cout<<"\033[1;37;41m"<<"Cannot sign to nullptr"<<"\033[0m"<<std::endl;

        std::cout<<*kangmin;
        std::cout<<form3<<std::endl;

        kangmin->signForm(form3);
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.Form::GradeTooLowException::what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    if (kangmin != nullptr)
        delete (kangmin);
    
    return (0); 
}