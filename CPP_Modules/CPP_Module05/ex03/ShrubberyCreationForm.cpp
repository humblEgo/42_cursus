/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:41:11 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/29 12:24:00 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137), _target(target)
{
    this->_tree =  "      /\\      \n";
    this->_tree += "     /\\*\\     \n";
    this->_tree += "    /\\O\\*\\    \n";
    this->_tree += "   /*/\\/\\/\\   \n";
    this->_tree += "  /\\O\\/\\*\\/\\  \n";
    this->_tree += " /\\*\\/\\*\\/\\/\\ \n";
    this->_tree += "/\\O\\/\\/*/\\/O/\\ \n";
    this->_tree += "      ||      \n";
    this->_tree += "      ||      \n";
    this->_tree += "      ||      \n";
}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: Form(other.getName(), 145, 137), _target(other.getTarget())
{
    this->_tree =  "      /\\      \n";
    this->_tree += "     /\\*\\     \n";
    this->_tree += "    /\\O\\*\\    \n";
    this->_tree += "   /*/\\/\\/\\   \n";
    this->_tree += "  /\\O\\/\\*\\/\\  \n";
    this->_tree += " /\\*\\/\\*\\/\\/\\ \n";
    this->_tree += "/\\O\\/\\/*/\\/O/\\n";
    this->_tree += "      ||      \n";
    this->_tree += "      ||      \n";
    this->_tree += "      ||      \n";
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    this->_tree = other.getTree();
    return (*this);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

std::string ShrubberyCreationForm::getTree() const
{
    return (this->_tree);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

void ShrubberyCreationForm::execute(Bureaucrat const& bureaucrat) const
throw (NotSignedFormException, GradeTooLowException)
{
    Form::execute(bureaucrat);
    this->action();
}

void ShrubberyCreationForm::action() const
{
    std::string file_name;
    std::ofstream file;
    
    file_name = this->getTarget() + "_shrubbery";
    file.open(file_name, std::ios::out | std::ios::app);
    if (file.is_open() == false)
        throw OpenFileException();
    file << this->getTree();
    if (file.bad())
    {
        file.close();
        throw WriteFileException();
    }
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

const char *ShrubberyCreationForm::OpenFileException::what() const throw ()
{
    return "OpenFileException: Cannot open file";
}

const char *ShrubberyCreationForm::WriteFileException::what() const throw ()
{
    return "OpenFileException: Cannot write to file";
}