/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 22:09:27 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 12:00:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::fields_name[11] = {
    "first_name", 
    "last_name", 
    "nickname", 
    "login",
    "postal_address",
    "email_address",
    "phone_number",
    "birthday_date",
    "favorite_meal",
    "underwear_color",
    "darkest_secret"               //10
};

Contact::Contact(void)
{
    for (int i = first_name; i <= darkest_secret; i++)
        this->person_info[i] = std::string();
    this->is_empty = true;
}

Contact::~Contact()
{
}

bool    Contact::is_empty_contact(void)
{
    return (this->is_empty);
}

void    Contact::set_information(int idx)
{
    int len;

    this->idx = idx;
    len = 0;
    for (int i = first_name; i <= darkest_secret; i++)
    {
        std::cout<<std::setw(20)<<std::left<<fields_name[i]<<": ";
        std::getline(std::cin, this->person_info[i]); 
        len += (int)this->person_info[i].length();
    }
    if (len > 0)
        this->is_empty = false;
}

void    Contact::show_information(void)
{
    for (int i = first_name; i <= darkest_secret; i++)
    {
        std::cout<<std::setw(20)<<std::left<<this->fields_name[i]<<": ";
        std::cout<<person_info[i]<<std::endl;
    }
}

void    Contact::show_preview_info(void)
{
    std::cout<<"|";
    std::cout.width(10);
    std::cout.fill(' ');
    std::cout<<std::right<<this->idx;
    for (int i = first_name; i <= nickname; i++)
    {
        std::cout<<"|";
        if (person_info[i].length() > 10)
        {
            std::cout.width(9);
            std::cout<<std::right<<this->person_info[i].substr(0, 9)<<".";
        }
        else
        {
            std::cout.width(10);
            std::cout<<std::right<<this->person_info[i];
        }
    }
    std::cout<<"|"<<std::endl;
}