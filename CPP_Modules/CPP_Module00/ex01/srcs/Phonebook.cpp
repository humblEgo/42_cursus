/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:05:59 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 12:00:46 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->amount = 0;
}

Phonebook::~Phonebook(void)
{
}

void    Phonebook::display_prompt(void)
{
    std::cout<<"===================================="<<std::endl;
    std::cout<<"|         Your PhoneBook!          |"<<std::endl;
    std::cout<<"|Valid commands:[add, search, exit]|"<<std::endl;
    std::cout<<"===================================="<<std::endl;
    std::cout<<"Enter your command: ";
}

void    Phonebook::add_contact(void)
{
    if (this->amount == 8)
    {
        std::cout<<"There is no space to save more contacts."<<std::endl;
        return ;
    }
    this->contact[this->amount].set_information(this->amount);
    if (this->contact[this->amount].is_empty_contact() == 0)
    {
        std::cout<<"=======> Contact added!"<<std::endl;
        this->amount += 1;
    }
    else
        std::cout<<"=======> Empty contact cannot be added!"<<std::endl;
}

void    Phonebook::display_search_header(void)
{
    std::cout<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;
    std::cout<<"|     index|first_name| last_name|  nickname|"<<std::endl;  
    std::cout<<"---------------------------------------------"<<std::endl;
    for (int i = 0; i < this->amount; i++)
        this->contact[i].show_preview_info();
    std::cout<<"---------------------------------------------"<<std::endl;
}

void    Phonebook::search_contact(void)
{
    int idx;

    if (this->amount == 0)
        std::cout<<"The Phonebook is empty now"<<std::endl;
    else
    {
        this->display_search_header();
        std::cout<<"Choose index(only number): ";
        if (!(std::cin>>idx) || idx < 0 || idx >= this->amount)
            std::cout<<"Invalid index"<<std::endl;
        else
            this->contact[idx].show_information();
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
    }
}

bool    Phonebook::input_command(void)
{
    std::string command;

    this->display_prompt(); 
    std::getline(std::cin, command);
    for (int i = 0; i < (int)command.length(); i++)
        command[i] = toupper(command[i]);
    if (!command.compare("ADD"))
        this->add_contact();
    else if (!command.compare("SEARCH"))
        this->search_contact();
    else if (!command.compare("EXIT"))
    {
        std::cout<<"Book closed!"<<std::endl;
        return (false);
    }
    else
        std::cout<<std::setw(36)<<std::right<<"Invalid command"<<std::endl;
    return (true);
}