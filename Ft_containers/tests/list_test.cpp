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
    {
        ft::List<SampleClass> my_list;
        ft::List<int> my_list1;
        // std::list<SampleClass> std_list;

        res = true;
        printResult(res);
    }

}