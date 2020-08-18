#include "Brain.hpp"

Brain::Brain(void)
{
}

Brain::~Brain(void)
{
}

std::string identify(void)
{
    const long address = (long)this;

    std::stringstream res;
    res << "0x" << std::uppercase << std::hex << address;
    return (res.str());
}