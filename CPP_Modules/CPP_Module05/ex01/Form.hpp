/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:13:37 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 15:13:40 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
    std::string const   _name;
    bool                _signed;
    int const           _signable_grade;
    int const           _executable_grade;
    Form();
public:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class AlreadySignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    Form(std::string name, int signable_grade, int executable_grade) throw (Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
    virtual ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);

    std::string getName() const;
    bool isSigned() const;
    int getSignableGrade() const;
    int getExecutableGrade() const;

    void beSigned(Bureaucrat& bureaucrat) throw (Form::GradeTooLowException, Form::AlreadySignedException);
};

std::ostream& operator<<(std::ostream& out, Form& other);

#endif