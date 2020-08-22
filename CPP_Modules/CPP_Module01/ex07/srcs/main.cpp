#include "Replace.hpp"

int error_msg(const char *msg)
{
    std::cerr<<msg<<std::endl;
    return (1);
}

int main(int argc, char const *argv[])
{
    if (argc != 4)
        return (error_msg("Error: Invalid argument"));
    try
    {
        Replace::sed(argv[1], argv[2], argv[3]);
    }
    catch(char const *e)
    {
        std::cerr<<"Error: "<<e<< std::endl;
    }
    
    return (0);
}