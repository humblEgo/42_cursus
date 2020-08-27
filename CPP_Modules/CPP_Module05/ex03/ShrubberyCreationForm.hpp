/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:41:15 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/26 17:07:15 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
private:
    std::string const _target;
    std::string _tree;
public:
    class OpenFileException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class WriteFileException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    std::string getTarget() const;
    std::string getTree() const;

    virtual void execute(Bureaucrat const &bureaucrat) const throw (NotSignedFormException, GradeTooLowException);
    void action() const;
};

#endif