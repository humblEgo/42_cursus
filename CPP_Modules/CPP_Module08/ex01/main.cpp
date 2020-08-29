#include <iostream>
#include "Span.hpp"

int main()
{
    std::cout<<"\033[1;37;41m"<<"subject example"<<"\033[0m"<<std::endl;
    try
    {
        Span sp = Span(5);

        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // std::list<int>& list = sp.getList();
        // for (std::list<int>::iterator itr = list.begin(); itr != list.end(); itr++)
        //     std::cout<<*itr<<std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout<<"\033[1;37;41m"<<"Span(0) case"<<"\033[0m"<<std::endl;
    try
    {
        Span sp2 = Span(0);
        sp2.addNumber(2147483647);
        sp2.addNumber(-2147483648);
        sp2.addNumber(17);
        sp2.addNumber(9);
        sp2.addNumber(11);

        // std::list<int>& list2 = sp2.getList();
        // for (std::list<int>::iterator itr = list2.begin(); itr != list2.end(); itr++)
        //     std::cout<<*itr<<std::endl;
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\033[1;37;41m"<<"int max, min case"<<"\033[0m"<<std::endl;
    try
    {
        Span sp3 = Span(10);
        sp3.addNumber(2147483647);
        sp3.addNumber(-2147483648);
        sp3.addNumber(17);
        sp3.addNumber(9);
        sp3.addNumber(11);

        // std::list<int>& list2 = sp3.getList();
        // for (std::list<int>::iterator itr = list2.begin(); itr != list2.end(); itr++)
        //     std::cout<<*itr<<std::endl;
        std::cout << sp3.shortestSpan() << std::endl;
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\033[1;37;41m"<<"same num case"<<"\033[0m"<<std::endl;
    try
    {
        Span sp4 = Span(5);
        sp4.addNumber(1);
        sp4.addNumber(1);
        sp4.addNumber(1);
        sp4.addNumber(1);
        sp4.addNumber(1);

        // std::list<int>& list2 = sp4.getList();
        // for (std::list<int>::iterator itr = list2.begin(); itr != list2.end(); itr++)
        //     std::cout<<*itr<<std::endl;
        std::cout << sp4.shortestSpan() << std::endl;
        std::cout << sp4.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"\033[1;37;41m"<<"assign case"<<"\033[0m"<<std::endl;
    try
    {
        Span sp5 = Span(5);
        sp5.addNumber(-21474836);
        sp5.addNumber(50);
        sp5.addNumber(23);
        sp5.addNumber(-50);

        Span sp6 = Span(0);
        sp6 = sp5;
        sp6.addNumber(49);
        std::cout<<"========49 should not added"<<std::endl;
        std::list<int>& list5 = sp5.getList();
        for (std::list<int>::iterator itr = list5.begin(); itr != list5.end(); itr++)
            std::cout<<*itr<<std::endl;
        std::cout<<"========49 should added"<<std::endl;
        std::list<int>& list6 = sp6.getList();
        for (std::list<int>::iterator itr = list6.begin(); itr != list6.end(); itr++)
            std::cout<<*itr<<std::endl;
        std::cout<<"========shortestSpan must be diff"<<std::endl;
        std::cout << sp5.shortestSpan() << std::endl;
        std::cout << sp5.longestSpan() << std::endl;

        std::cout << sp6.shortestSpan() << std::endl;
        std::cout << sp6.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return (0);
}