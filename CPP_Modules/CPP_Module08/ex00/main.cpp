#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include "easyfind.hpp"

int main()
{
    int can_found_num = 2;
    int target_num = can_found_num;

    // int cannot_found_num = 99;
    // int target_num = cannot_found_num;
    std::cout<<"=========================================Vector case!"<<std::endl;
    std::vector<int> vec(5, 5);
    for (int i = 0; i < 5; i++)
        vec[i] = i;
    try
    {
        std::vector<int>::iterator found = easyfind(vec, target_num);
        std::cout<<"Success to find "<<*found<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"=========================================Deque case!"<<std::endl;
    std::deque<int> deq(5, 5);
    for (int i = 0; i < 5; i++)
        deq[i] = i;
    try
    {
        std::deque<int>::iterator found = easyfind(deq, target_num);
        std::cout<<"Success to find "<<*found<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"=========================================list case!"<<std::endl;
    std::list<int> lst;
    for (int i = 0; i < 5; i++)
        lst.push_back(i);
    try
    {
        std::list<int>::iterator found = easyfind(lst, target_num);
        std::cout<<"Success to find "<<*found<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"=========================================set case!"<<std::endl;
    std::set<int> set;
    for (int i = 0; i < 5; i++)
        set.insert(i);
    try
    {
        std::set<int>::iterator found = easyfind(set, target_num);
        std::cout<<"Success to find "<<*found<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout<<"=========================================map case!"<<std::endl;
    std::map<int, int> map;
    for (int i = 0; i < 5; i++)
        map[i] = i+42;
    try
    {
        std::cout<<"key: "<<target_num<<" value: "<<"? Let me check :)"<<std::endl;
        auto found = easyfind(map, target_num);
        std::cout<<"Success to find "<<found->second<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}