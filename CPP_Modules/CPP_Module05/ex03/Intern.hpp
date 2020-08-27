/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 22:29:48 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/26 17:07:48 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Intern
{
public:
    class NoFormPatternException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    Intern();
    virtual ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    std::string stringToLower(std::string const source) const;

    Form* makeShrubberyCreationForm(std::string target);
    Form* makeRobotomyRequestForm(std::string target);
    Form* makePresidentialPardonForm(std::string target);
    Form* makeForm(std::string form_type, std::string target) throw(NoFormPatternException);
};

#endif