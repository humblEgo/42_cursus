#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include <fstream>
# include <random>

class RobotomyRequestForm : public Form
{
private:
    std::string const _target;
public:
    class NotSignedFormException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    std::string getTarget() const;
    virtual void execute(Bureaucrat const &bureaucrat) const;

    void action() const;
};

#endif