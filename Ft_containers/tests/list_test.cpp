#include "SampleClass.hpp"
#include "container_test.hpp"
#include <list>
#include "List.hpp"

void listTest()
{
    bool res;
    std::cout<<"\033[1;37;41m"<<"List test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/

    printTest("[List] Constructor test");
    std::list<int> std_list;
    std::cout<<std::endl;
    std_list.push_back(1);
    std_list.push_back(2);
    std_list.push_back(3);
    std_list.push_back(4);
    std_list.push_back(5);

    std::list<int>::iterator iter;

    for (iter = std_list.begin(); iter != std_list.end(); iter++)
        std::cout<<*iter<<std::endl;
    std::cout<<std::endl;
    res = true;
    printResult(res);
}