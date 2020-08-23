#include "Cure.hpp"

Cure::Cure()
: AMateria("cure")
{
}

Cure::Cure(const Cure& other)
: AMateria(other) //TODO: check is it okay
{
}

Cure& Cure::operator=(const Cure& other)
{
    this->AMateria::operator=(other);
    return (*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout<<"Cure: \"* heals ";
    std::cout<<target.getName()<<"'s wounds *"<<std::endl;
    AMateria::use(target);
}