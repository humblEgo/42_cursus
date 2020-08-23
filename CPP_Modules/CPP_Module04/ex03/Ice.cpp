#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{
}

Ice::Ice(const Ice& other)
: AMateria(other) //TODO: check is it okay
{
}

Ice& Ice::operator=(const Ice& other)
{
    this->AMateria::operator=(other);
    return (*this);
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout<<"Ice: \"* shoots an ice bolt at ";
    std::cout<<target.getName()<<" *"<<std::endl;
    AMateria::use(target);
}