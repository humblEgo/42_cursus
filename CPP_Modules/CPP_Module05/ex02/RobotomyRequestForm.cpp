#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form(other.getName(), 72, 45), _target(other.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    (void)other;
    return (*this);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

/*==========================================================*/
/*# Actions                                                #*/
/*==========================================================*/

void RobotomyRequestForm::execute(Bureaucrat const& bureaucrat) const
{
    if (this->isSigned() == false)
        throw NotSignedFormException();
    if (this->isExecutableGrade(bureaucrat) == false)
        throw Form::GradeTooLowException();
    this->action();
}

void RobotomyRequestForm::action() const
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 1);
    std::string msg;

    if (dis(gen))
        msg = "* RIZZZZZ, BZZZZZZZZZZ *\n" + this->getTarget() + " has been robotomized successfully!";
    else
        msg = "Failed to robotomize " + this->getTarget();
    std::cout<<msg<<std::endl;
}

/*==========================================================*/
/*#####################  Exceptions  #######################*/
/*==========================================================*/

const char *RobotomyRequestForm::NotSignedFormException::what() const throw ()
{
    return "NotSignedFormException: Form must be signed first";
}