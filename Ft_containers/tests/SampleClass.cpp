#include "SampleClass.hpp"

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

SampleClass::SampleClass() : _name("default name") {}
SampleClass::SampleClass(const std::string& name): _name(name) {}

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

SampleClass::~SampleClass() {}

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

SampleClass::SampleClass(const SampleClass& other) : _name(other._name) {}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

SampleClass& SampleClass::operator=(const SampleClass& other)
{
    this->_name = other._name;
    return (*this);
}

std::string&        SampleClass::operator*()
{
    return (this->_name);
}

const std::string&  SampleClass::operator*() const
{
    return (this->_name);
}

bool                SampleClass::operator!=(const SampleClass& other) const
{
    return (this->_name != other._name);
}

bool                SampleClass::operator==(const SampleClass& other) const
{
    return (this->_name == other._name);
}

bool                SampleClass::operator<(const SampleClass& other) const
{
    return (this->_name < other._name);
}

bool                SampleClass::operator<=(const SampleClass& other) const
{
    return (this->_name <= other._name);
}

bool                SampleClass::operator>(const SampleClass& other) const
{
    return (this->_name > other._name);
}

bool                SampleClass::operator>=(const SampleClass& other) const
{
    return (this->_name >= other._name);
}

/*==========================================================*/
/*################    Member functions    ##################*/
/*==========================================================*/

const std::string& SampleClass::getName() const
{
    return (this->_name);
}