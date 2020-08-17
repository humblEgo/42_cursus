/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:31:00 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 12:01:11 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "limits"

class Phonebook
{
    private:
        Contact contact[8];
        int     amount;
    public:
        Phonebook();
        ~Phonebook();
        void    display_prompt(void);
        void    add_contact(void);
        void    search_contact(void);
        void    display_search_header(void);
        bool    input_command(void);
};

#endif