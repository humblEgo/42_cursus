#include "SampleClass.hpp"
#include "container_test.hpp"
#include "Stack.hpp"
#include <stack>


// static bool comparator(SampleClass first, SampleClass second)
// {
//     return (first.getName() < second.getName());
// }

// static bool unary_predicator(SampleClass target)
// {
//     return (target.getName() == "five");
// }

// static bool binary_predicate(SampleClass first, SampleClass second)
// {
//     return (first.getName() == second.getName());
// }

template <typename T>
std::ostream& operator<<(std::ostream& out, const ft::Stack<T>& li)
{
    std::cout<<"============================================="<<std::endl;
    (void)li;
    // out<<"size    : "<<li.size()<<"\n";
    std::cout<<"member: [ ";
    // for (typename ft::Stack<T>::Iterator it = li.begin(); it != li.end(); ++it)
    //     std::cout<<*it<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"=============================================";
    return (out);
}

void stackTest()
{
    std::string data[10] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten"
    };

    bool res;
    std::cout<<"\033[1;37;41m"<<"Stack test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/

    printTest("[Stack] Constructor test");
    {
        printCase("Stack<SampleCalss> my_stack");
        ft::Stack<SampleClass> my_stack;
        ft::Stack<int> my_stack2;
        std::cout<<my_stack<<std::endl;

        std::stack<SampleClass> std_stack;
        std::stack<int> std_stack2;

        res = checkResultManually();
        printResult(res);
    }
}