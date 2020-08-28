#include <iostream>
#include "Span.hpp"

int main()
{
    std::cout<<"==============================subject example"<<std::endl;
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
    
    
    std::cout<<"==============================Span(0) case"<<std::endl;
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

    std::cout<<"==============================int max, min case"<<std::endl;
    try
    {
        Span sp2 = Span(10);
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

    std::cout<<"==============================same num case"<<std::endl;
    try
    {
        Span sp2 = Span(5);
        sp2.addNumber(1);
        sp2.addNumber(1);
        sp2.addNumber(1);
        sp2.addNumber(1);
        sp2.addNumber(1);

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

    return (0);
}