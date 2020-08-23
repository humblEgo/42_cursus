#include "AMateria.hpp"

AMateria::AMateria(std::string const& type)
:_type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria& other)
:_type(other.getType()), _xp(other.getXP())
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
    this->_type = other.getType();
    this->_xp = other.getXP();
    return (*this);
}

AMateria::~AMateria()
{
}

std::string const& AMateria::getType() const
{
    return (this->_type);
}

unsigned int AMateria::getXP() const
{
    return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    this->_xp += 10;
}