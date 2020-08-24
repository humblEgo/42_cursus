#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define MAX_GRADE 150
# define MIN_GRADE 1

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

    Bureaucrat(std::string& name, int grade) throw (GradeTooLowException, GradeTooHighException);
    Bureaucrat(const Bureaucrat& other) throw (GradeTooLowException, GradeTooHighException);
    Bureaucrat& operator=(const Bureaucrat& other);
    virtual ~Bureaucrat();

    std::string const& getName() const;
    int const& getGrade() const;

    void increaseGrade(void) throw (GradeTooHighException);
    void decreaseGrade(void) throw (GradeTooLowException);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

#endif