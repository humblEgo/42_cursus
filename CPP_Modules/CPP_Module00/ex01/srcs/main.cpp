/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:23:22 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/17 12:00:38 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook   phonebook;
    bool        run;
    std::string command;

    std::cout<<"\033[36m";
    run = true;
    while (run)
    {
        run = phonebook.input_command();
    }
    return (0);
}