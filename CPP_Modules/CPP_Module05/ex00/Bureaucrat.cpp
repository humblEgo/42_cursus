#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string& name, int grade) throw (Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    this->_name = name;
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) throw (Bureaucrat::GradeTooLowException, Bureaucrat::GradeTooHighException)
{
    if (other.getGrade() < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (other.getGrade() > 150)
        throw Bureaucrat::GradeTooHighException();
    this->_name = other.getName();
    this->_grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->_name = other.getName();
    this->_grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string const& Bureaucrat::getName() const
{
    return (this->_name);
}

int const& Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
    out<<other.getName()<<", bureaucrat grade "<<other.getGrade()<<std::endl;
    return (out);
}

void Bureaucrat::increaseGrade() throw(Bureaucrat::GradeTooHighException)
{
    if (this->getGrade() == MAX_GRADE)
        throw GradeTooHighException();
    this->_grade += 1;
}

void Bureaucrat::decreaseGrade() throw (Bureaucrat::GradeTooLowException)
{
    if (this->getGrade() == MIN_GRADE)
        throw GradeTooLowException();
    this->_grade -= 1;
}