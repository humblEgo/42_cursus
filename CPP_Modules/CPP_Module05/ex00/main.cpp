/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:53 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 11:08:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout<<"=======================================Constructer test"<<std::endl;
    try
    {
        std::cout<<"============normal case"<<std::endl;
        std::string name = "kangmin";
        Bureaucrat* kangmin = new Bureaucrat(name, 1);
        std::cout <<*kangmin<<std::endl;
        delete kangmin;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"============too low case"<<std::endl;
    try
    {
        Bureaucrat* too_low = new Bureaucrat("too_low", 0);
        delete too_low;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"============too high case"<<std::endl;
    try
    {
        Bureaucrat* too_high = new Bureaucrat("too_high", 151);
        delete too_high;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"=======================================grade handler test"<<std::endl;
    Bureaucrat* max_high = nullptr;
    try
    {
        std::cout<<"============decrementGrade"<<std::endl;
        max_high = new Bureaucrat("max_high", 150);
        max_high->decrementGrade();
        max_high->decrementGrade();
        max_high->decrementGrade();
        max_high->incrementGrade();
        std::cout<<*max_high<<std::endl;
        max_high->incrementGrade();
        max_high->incrementGrade();
        max_high->incrementGrade();
        std::cout<<*max_high<<std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (max_high != nullptr)
        delete max_high;
    Bureaucrat* max_low = nullptr;
    try
    {
        std::cout<<"============incrementGrade"<<std::endl;
        max_low = new Bureaucrat("max_low", 1);
        max_low->incrementGrade();
        max_low->incrementGrade();
        max_low->incrementGrade();
        max_low->decrementGrade();
        std::cout<<*max_low<<std::endl;
        max_low->decrementGrade();
        max_low->decrementGrade();
        max_low->decrementGrade();
        std::cout<<*max_low<<std::endl;
    }
    catch(Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (max_low != nullptr)
        delete (max_low);

    
    return (0);
}