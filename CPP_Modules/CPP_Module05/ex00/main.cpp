#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        std::cout<<"============normal case"<<std::endl;
        std::string name = "kangmin";
        Bureaucrat* kangmin = new Bureaucrat(name, 150);
        delete kangmin;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // std::cout<<"============too low case"<<std::endl;
    // Bureaucrat* too_low = new Bureaucrat("too_low", 0);

    // std::cout<<"============too high case"<<std::endl;
    // Bureaucrat* too_high = new Bureaucrat("too_high", 151);

    // delete too_low;
    // delete too_high;

    return (0);
}