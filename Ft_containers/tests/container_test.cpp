#include "container_test.hpp"


void printTest(std::string test_name)
{
    std::cout << "\033[1;36;40m" << std::setw(50);
    std::cout << std::left << test_name << "\033[0m";
}

void printResult(bool result)
{ 
    if (result)
    {
        std::cout << "\033[1;32;40m" << "success" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[1;31;40m" << "fail" << "\033[0m" << std::endl;
    }
}

bool checkResultManually(void)
{
    std::string input;
    bool ret;

    while (true)
    {
        std::cout<<"Is it success? Input y or n! : ";
        std::cin >> input;
        if (input == "y")
        {
            ret = true;
            break;
        }
        else if (input == "n")
        {
            ret = false;
            break;
        }
        else
            std::cout<<"Invalid input"<<std::endl;
    }
    std::cout << "\033[1;36;40m" << std::setw(50);
    std::cout << " " << "\033[0m";
    return (ret);
}
