/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:13:37 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/26 17:02:08 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Form;
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
    class NotSignedFormException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    Form(std::string name, int signable_grade, int executable_grade) throw (GradeTooHighException, GradeTooLowException);
    virtual ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);

    std::string getName() const;
    bool isSigned() const;
    int getSignableGrade() const;
    int getExecutableGrade() const;

    void beSigned(Bureaucrat& bureaucrat) throw (GradeTooLowException, AlreadySignedException);
    bool isSignableGrade(Bureaucrat const& bureaucrat) const;
    bool isExecutableGrade(Bureaucrat const& bureaucrat) const;

    virtual void execute(Bureaucrat const &bureaucrat) const throw (NotSignedFormException, GradeTooLowException) = 0;
};

std::ostream& operator<<(std::ostream& out, Form& other);

#endif