#include "container_test.hpp"

int main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        std::cerr<<"Error invalid input"<<std::endl;
        return (1);
    }

    std::string container_type(argv[1]);
    if (container_type == "vector")
        vector_test();
    else
    {
        std::cerr<<"No match with container"<<std::endl;
    }
    
    return (0);
}