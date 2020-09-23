#include "SampleClass.hpp"
#include "container_test.hpp"
#include <map>
#include "Pair.hpp"
// #include "Map.hpp"

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

// template <typename T, typename A>
// std::ostream& operator<<(std::ostream& out, const ft::Map<T, A>& li)
// {
//     std::cout<<"============================================="<<std::endl;
//     out<<"size    : "<<li.size()<<"\n";
//     std::cout<<"member: [ ";
//     for (typename ft::List<T, A>::ConstIterator it = li.begin(); it != li.end(); ++it)
//         std::cout<<*it<<" ";
//     std::cout<<"]"<<std::endl;
//     std::cout<<"=============================================";
//     return (out);
// }


void mapTest()
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
    std::cout<<"\033[1;37;41m"<<"Map test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/

    printTest("[Map] Pair test");
    {
        std::pair<int, float> std_p1;

        std::cout<<std::endl;
        std::cout<<"\033[1;33m"<<"Std pair"<<"\033[0m"<<std::endl;
        std::cout<<"Value_init ["<<std_p1.first<<", "<<std_p1.second<<"]"<<std::endl;
        std::pair<int, double> std_p2(42, 0.242);
        std::cout<<"Value_init with two values ["<<std_p2.first<<", "<<std_p2.second<<"]"<<std::endl;

        std::pair<char, int> std_p3(std_p2);
        std::cout<<"Convert ["<<std_p3.first<<", "<<std_p3.second<<"]"<<std::endl;

        std::cout<<"\033[1;33m"<<"my pair"<<"\033[0m"<<std::endl;
        ft::pair<int, float> my_p1;
        std::cout<<"Value_init ["<<my_p1.first<<", "<<my_p1.second<<"]"<<std::endl;
        std::pair<int, double> my_p2(42, 0.242);
        std::cout<<"Value_init with two values ["<<my_p2.first<<", "<<my_p2.second<<"]"<<std::endl;

        std::pair<char, int> my_p3(my_p2);
        std::cout<<"Convert ["<<my_p3.first<<", "<<my_p3.second<<"]"<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    
}