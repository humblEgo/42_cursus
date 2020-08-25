#include "ShrubberyCreationForm.hpp"

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

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

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
/*# Actions                                                #*/
/*==========================================================*/

void ShrubberyCreationForm::execute(Bureaucrat const& bureaucrat) const
{
    if (this->isSigned() == false)
        throw NotSignedFormException();
    if (this->isExecutableGrade(bureaucrat) == false)
        throw Form::GradeTooLowException();
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

const char *ShrubberyCreationForm::NotSignedFormException::what() const throw ()
{
    return "NotSignedFormException: Form must be signed first";
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw ()
{
    return "OpenFileException: Cannot open file";
}

const char *ShrubberyCreationForm::WriteFileException::what() const throw ()
{
    return "OpenFileException: Cannot write to file";
}