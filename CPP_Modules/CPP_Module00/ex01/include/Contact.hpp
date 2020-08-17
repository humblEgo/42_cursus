/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:57:52 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 01:33:50 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

class Contact
{
private:
    int                 idx;
    std::string         person_info[11];
    static std::string  fields_name[11];
    bool                is_empty;
    enum Field {
        first_name = 0,
        last_name,
        nickname,
        login,
        postal_address,
        email_address,
        phone_number,
        birthday_date,
        favorite_meal,
        underwear_color,
        darkest_secret                  //10
    };
public:
    Contact();
    ~Contact();

    bool    is_empty_contact(void);
    void    set_information(int idx);
    void    show_information(void);
    void    show_preview_info(void);
};

#endif