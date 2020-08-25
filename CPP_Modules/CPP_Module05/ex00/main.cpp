/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:53 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 15:15:30 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout<<"=======================================Constructer test"<<std::endl;
    Bureaucrat* kangmin = nullptr;
    try
    {
        std::cout<<"============normal case"<<std::endl;
        std::string name = "kangmin";
        kangmin = new Bureaucrat(name, 1);
        std::cout <<*kangmin<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (kangmin != nullptr)
        delete kangmin;

    std::cout<<"============too high case"<<std::endl;

    Bureaucrat* too_high = nullptr;
    try
    {
        too_high = new Bureaucrat("too_high", 0);
        delete too_high;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (too_high != nullptr)
        delete too_high;

    std::cout<<"============too low case"<<std::endl;
    Bureaucrat* too_low = nullptr;
    try
    {
        too_low = new Bureaucrat("too_low", 151);
        delete too_low;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (too_low != nullptr)
        delete too_low;

    std::cout<<"=======================================grade handler test"<<std::endl;
    Bureaucrat* max_low = nullptr;
    try
    {
        std::cout<<"============decrementGrade"<<std::endl;
        max_low = new Bureaucrat("max_low", 150);
        max_low->decrementGrade();
        max_low->decrementGrade();
        max_low->decrementGrade();
        max_low->incrementGrade();
        std::cout<<*max_low<<std::endl;
        max_low->incrementGrade();
        max_low->incrementGrade();
        max_low->incrementGrade();
        std::cout<<*max_low<<std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (max_low != nullptr)
        delete max_low;
    Bureaucrat* max_high = nullptr;
    try
    {
        std::cout<<"============incrementGrade"<<std::endl;
        max_high = new Bureaucrat("max_high", 1);
        max_high->incrementGrade();
        max_high->incrementGrade();
        max_high->incrementGrade();
        max_high->decrementGrade();
        std::cout<<*max_high<<std::endl;
        max_high->decrementGrade();
        max_high->decrementGrade();
        max_high->decrementGrade();
        std::cout<<*max_high<<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (max_high != nullptr)
        delete (max_high);

    
    return (0);
}