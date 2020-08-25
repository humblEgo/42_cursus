/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:48:52 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/25 15:15:04 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define HIGHEST_GRADE 1        // grade 1 is the highest grade.
# define LOWEST_GRADE 150      // grade 150 is the lowest grade.

class Bureaucrat
{
private:
    std::string _name;
    int         _grade;
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

    Bureaucrat(std::string const& name, int grade) throw (GradeTooHighException, GradeTooLowException);
    Bureaucrat(const Bureaucrat& other) throw (GradeTooHighException, GradeTooLowException);
    Bureaucrat& operator=(const Bureaucrat& other);
    virtual ~Bureaucrat();

    std::string const& getName() const;
    int const& getGrade() const;

    void incrementGrade(void) throw (Bureaucrat::GradeTooHighException);
    void decrementGrade(void) throw (Bureaucrat::GradeTooLowException);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif