#include "SampleClass.hpp"
#include "container_test.hpp"
#include <map>
#include "Pair.hpp"
#include "Map.hpp"

template <typename Key, typename T>
void print_stdmap(std::map<Key, T>& m)
{
    typename std::map<Key, T>::iterator iter;

    std::cout<<"\033[1;31m"<<"std_map = { ";
    for(iter = m.begin(); iter != m.end(); iter++)
        std::cout<<iter->first<<" : "<<iter->second<<", ";
    std::cout<<"} \033[0m"<<std::endl;
}

template <typename Key, typename T>
void print_mymap(typename ft::Map<Key, T>& m)
{
    typename ft::Map<Key, T>::Iterator iter;

    std::cout<<"\033[1;34m"<<"my_map = { ";
    for(iter = m.begin(); iter != m.end(); iter++)
        std::cout<<iter->first<<" : "<<iter->second<<", ";
    std::cout<<"} \033[0m"<<std::endl;
}

void mapTest()
{
    std::pair<SampleClass, int>  std_pair[] = {
        std::make_pair(SampleClass("iwoo"), 1),
        std::make_pair(SampleClass("42seoul"), 2),
        std::make_pair(SampleClass("learner"), 3),
        std::make_pair(SampleClass("humblEgo"), 4),
        std::make_pair(SampleClass("business"), 5)
    };

    ft::pair<SampleClass, int>  ft_pair[] = {
        ft::make_pair(SampleClass("iwoo"), 1),
        ft::make_pair(SampleClass("42seoul"), 2),
        ft::make_pair(SampleClass("learner"), 3),
        ft::make_pair(SampleClass("humblEgo"), 4),
        ft::make_pair(SampleClass("business"), 5)
    };

    bool res;
    std::cout<<"\033[1;37;41m"<<"Map test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################      Pair test     ##################*/
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
    
    /*==========================================================*/
    /*####################  Canonical test   ###################*/
    /*==========================================================*/
    
    // print_mymap에서 begin, end를 테스트할 수 있다.
    printTest("[Map] Constructor, begin, end test");
    {
        printCase("std::map<SampleClass, int> std_map");
        std::map<SampleClass, int> std_map;
        print_stdmap(std_map);

        printCase("ft::Map<SampleClass, int> my_map");
        ft::Map<SampleClass, int> my_map;
        print_mymap(my_map);

        printCase("std::map<SampleClass, int> std_map(std_pair, std_pair + 5)");
        std::map<SampleClass, int> std_map2(std_pair, std_pair + 5);
        print_stdmap(std_map2);
        printCase("ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5)");
        ft::Map<SampleClass, int> my_map2(ft_pair, ft_pair + 5);
        print_mymap(my_map2);

        res = checkResultManually();
        printResult(res);
    }

    printTest("[Map] Copy constructor && operator[] test");
    {
        printCase("original --> ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5)");
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        print_mymap(my_map);

        printCase("copy --> ft::Map<SampleClass, int> copy_map(my_map) and insert \"new\"");
        ft::Map<SampleClass, int> copy_map(my_map);
        copy_map[SampleClass("new")] = 42;
        print_mymap(copy_map);

        printCase("SampleClass(\"new\") should not be in original");
        print_mymap(my_map);

        res = checkResultManually();
        printResult(res);
    }

    printTest("[Map] Assign operator test");
    {
        printCase("original --> ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5)");
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        print_mymap(my_map);

        printCase("assign --> ft::Map<SampleClass, int> copy_map = my_map and insert \"new\"");
        ft::Map<SampleClass, int> copy_map = my_map;
        copy_map[SampleClass("new")] = 42;
        print_mymap(copy_map);

        printCase("SampleClass(\"new\") should not be in original");
        print_mymap(my_map);

        res = checkResultManually();
        printResult(res);
    }

    /*==========================================================*/
    /*####################    Capacity   #######################*/
    /*==========================================================*/
    
    printTest("[Map] clear and empty test");
    {
        printCase("my_map(ft_pair, ft_pair+5) and clear and check empty");
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        my_map.clear();
        print_mymap(my_map);

        if (my_map.empty())
            res = true;
        else
            res = false;

        printResult(res);
    }

    printTest("[Map] size test");
    {
        printCase("std_map(std_pair, std_pair+5) and check size");
        std::map<SampleClass, int> std_map(std_pair, std_pair + 5);
        print_stdmap(std_map);
        std::cout<<"size : "<<std_map.size()<<std::endl;

        printCase("my_map(ft_pair, ft_pair+5) and check size");
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        print_mymap(my_map);
        std::cout<<"size : "<<my_map.size()<<std::endl;

        std_map.clear();
        my_map.clear();
        if (my_map.size() == std_map.size())
            res = true;
        else
            res = false;

        printResult(res);
    }

    printTest("[Map] max_size test");
    {
        printCase("my_map(ft_pair, ft_pair+5) and check size");
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        print_mymap(my_map);
        std::cout<<"max_size : "<<my_map.max_size()<<std::endl;

        res = true;
        printResult(res);
    }

    /*==========================================================*/
    /*####################   Modifiers   #######################*/
    /*==========================================================*/

    //clear <- already tested

    printTest("[Map] insert test");
    {
        printCase("insert 'pair(SampleClass(\"iwoo\"), 1)");
        std::map<SampleClass, int> std_map;
        std_map.insert(std::make_pair(SampleClass("iwoo"), 1));
        ft::Map<SampleClass, int> my_map;
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 1));
        print_stdmap(std_map);
        print_mymap(my_map);

        printCase("insert already exist key");
        std_map.insert(std::make_pair(SampleClass("iwoo"), 1));
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 1));
        print_stdmap(std_map);
        print_mymap(my_map);

        printCase("insert new");
        std_map.insert(std::make_pair(SampleClass("42seoul"), 1));
        my_map.insert(ft::make_pair(SampleClass("42seoul"), 1));
        print_stdmap(std_map);
        print_mymap(my_map);

        res = checkResultManually();
        printResult(res);
    }

    //TODO: 잘 안됨. 제대로 처리해야함.
    printTest("[Map] erase test");
    {
        printCase("construct with pair 1 to pair 5");
        std::map<SampleClass, int> std_map(std_pair, std_pair + 5);
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        print_stdmap(std_map);
        print_mymap(my_map);

        printCase("erase pair 'iwoo'");
        std_map.erase(SampleClass("iwoo"));
        my_map.erase(SampleClass("iwoo"));
        print_stdmap(std_map);
        print_mymap(my_map);

        printCase("erase pair 'no_exist_key'");
        std_map.erase(SampleClass("no_exist_key"));
        my_map.erase(SampleClass("no_exist_key"));
        print_stdmap(std_map);
        print_mymap(my_map);

        res = checkResultManually();
        printResult(res);
    }

    printTest("[Map] swap test");
    {
        std::cout<<std::endl;
        std::map<SampleClass, int> std_map1(std_pair, std_pair + 5);
        ft::Map<SampleClass, int> my_map1(ft_pair, ft_pair + 5);
        std::cout<<"\033[1;33m"<<"std_map1: "<<"\033[0m";
        print_stdmap(std_map1);
        std::cout<<"\033[1;34m"<<"my_map1: "<<"\033[0m";
        print_mymap(my_map1);

        std::map<SampleClass, int> std_map2(std_pair, std_pair + 1);
        ft::Map<SampleClass, int> my_map2(ft_pair, ft_pair + 1);
        std::cout<<"\033[1;35m"<<"std_map2: "<<"\033[0m";
        print_stdmap(std_map2);
        std::cout<<"\033[1;36m"<<"my_map2: "<<"\033[0m";
        print_mymap(my_map2);

        std_map1.swap(std_map2);
        my_map1.swap(my_map2);
        printCase("after swap\n");

        std::cout<<"\033[1;33m"<<"std_map1: "<<"\033[0m";
        print_stdmap(std_map1);
        std::cout<<"\033[1;34m"<<"my_map1: "<<"\033[0m";
        print_mymap(my_map1);

        std::cout<<"\033[1;35m"<<"std_map2: "<<"\033[0m";
        print_stdmap(std_map2);
        std::cout<<"\033[1;36m"<<"my_map2: "<<"\033[0m";
        print_mymap(my_map2);

        res = checkResultManually();
        printResult(res);
    }

    /*==========================================================*/
    /*####################    Lookup     #######################*/
    /*==========================================================*/
    
    printTest("[Map] find test");
    {
        printCase("construct with pair 1 to pair 5");
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        print_mymap(my_map);

        std::cout<<"\033[1;33m"<<"and find key 'iwoo'"<<"\033[0m"<<std::endl;
        ft::Map<SampleClass, int>::Iterator it = my_map.find(SampleClass("humblEgo"));
        std::cout<<"Find {"<<it->first<<" : "<<it->second<<"}"<<std::endl;

        std::cout<<"\033[1;33m"<<"and find no exist key"<<"\033[0m"<<std::endl;
        ft::Map<SampleClass, int>::Iterator it2 = my_map.find(SampleClass("wonie"));
        // it = my_map.find(SampleClass("iwoo"));
        std::cout<<"Find {"<<it2->first<<" : "<<it2->second<<"}"<<std::endl;

        res = checkResultManually();
        printResult(res);
    }
    
    printTest("[Map] count test");
    {
        std::map<SampleClass, int> std_map(std_pair, std_pair + 5);
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);

        res = false;
        if (std_map.count(SampleClass("iwoo")) == my_map.count(SampleClass("iwoo")))
            res = true;
        if (res)
            if (std_map.count(SampleClass("no_exist")) == my_map.count(SampleClass("no_exit")))
                res = true;
        printResult(res);
    }

    printTest("[Map] lower_bound && upper_bound test");
    {
        std::map<SampleClass, int> std_map(std_pair, std_pair + 5);
        printCase("std_map.equal_range(SampleClass(\"iwoo\"))");
        print_stdmap(std_map);

        std::cout<<"\033[1;32m"<<"[std_map] lower_bound(SampleClass(\"iwoo\") : ["<<(std_map.lower_bound(SampleClass("iwoo")))->first<<" : "<<std_map.lower_bound(SampleClass("iwoo"))->second<<"] \033[0m"<<std::endl;
        std::cout<<"\033[1;32m"<<"[std_map] upper_bound(SampleClass(\"iwoo\") : ["<<(std_map.upper_bound(SampleClass("iwoo")))->first<<" : "<<std_map.upper_bound(SampleClass("iwoo"))->second<<"] \033[0m"<<std::endl;
        for (std::map<SampleClass, int>::iterator it =  std_map.lower_bound(SampleClass("iwoo")); it != std_map.upper_bound(SampleClass("iwoo")); it++)
            std::cout<<"["<<it->first<<","<<it->second<<"]";
        std::cout<<std::endl;
        
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        printCase("my_map.equal_range(SampleClass(\"iwoo\"))");
        print_mymap(my_map);

        std::cout<<"\033[1;35m"<<"[my_map] lower_bound(SampleClass(\"iwoo\") : ["<<(my_map.lower_bound(SampleClass("iwoo")))->first<<" : "<<my_map.lower_bound(SampleClass("iwoo"))->second<<"] \033[0m"<<std::endl;
        std::cout<<"\033[1;35m"<<"[my_map] upper_bound(SampleClass(\"iwoo\") : ["<<(my_map.upper_bound(SampleClass("iwoo")))->first<<" : "<<my_map.upper_bound(SampleClass("iwoo"))->second<<"] \033[0m"<<std::endl;
        for (ft::Map<SampleClass, int>::Iterator it =  my_map.lower_bound(SampleClass("iwoo")); it != my_map.upper_bound(SampleClass("iwoo")); it++)
            std::cout<<"["<<it->first<<","<<it->second<<"]";
        std::cout<<std::endl;

        printResult(res);
    }

    // lower_bound() <-- 범위 내에서 찾으려는 값 이상의 원소들 중 처음 나오는 Iterator
    // upper_bound() <-- 범위 내에서 찾으려는 값 초과의 원소들 중 처음 나오는 Iterator
    // lower_bound()와 upper_bound() 결과를 쌍으로 반환함(결과적으로 범위를 반환).
    printTest("[Map] equl_range test");
    {
        std::map<SampleClass, int> std_map(std_pair, std_pair + 5);
        std_map.insert(std::make_pair(SampleClass("iwoo"), 42));
        std_map.insert(std::make_pair(SampleClass("iwoo"), 43));
        std_map.insert(std::make_pair(SampleClass("iwoo"), 44));
        std_map.insert(std::make_pair(SampleClass("iwoo"), 45));
        printCase("std_map.equal_range(SampleClass(\"iwoo\"))");
        print_stdmap(std_map);

        for (std::map<SampleClass, int>::iterator it =  std_map.equal_range(SampleClass("iwoo")).first; it != std_map.equal_range(SampleClass("iwoo")).second; it++)
        {
            std::cout<<"["<<it->first<<","<<it->second<<"]";
        }
        std::cout<<std::endl;
        
        ft::Map<SampleClass, int> my_map(ft_pair, ft_pair + 5);
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 42));
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 42));
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 43));
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 44));
        my_map.insert(ft::make_pair(SampleClass("iwoo"), 45));
        printCase("my_map.equal_range(SampleClass(\"iwoo\"))");
        print_mymap(my_map);

        for (ft::Map<SampleClass, int>::Iterator it =  my_map.equal_range(SampleClass("iwoo")).first; it != my_map.equal_range(SampleClass("iwoo")).second; it++)
        {
            std::cout<<"["<<it->first<<","<<it->second<<"]";
        }
        std::cout<<std::endl;

        printResult(res);
    }

    /*==========================================================*/
    /*###################  Observers test  #####################*/
    /*==========================================================*/
  
    printTest("[Map] key_comp test");
    {
        std::map<char, int> std_map;
        printCase("check key compare object of std::map<char, int> std_map");
        print_stdmap(std_map);
        
        std::map<char, int>::key_compare std_comp = std_map.key_comp();

        if (std_comp('a', 'b'))
            std::cout<<"\033[1;37m"<<"std key_compare works!"<<"\033[0m"<<std::endl;
        else
            std::cout<<"\033[1;37m"<<"std key_compare doesn't works.."<<"\033[0m"<<std::endl;
        
        
        ft::Map<char, int> my_map;
        printCase("check key compare object of ft::Map<char, int> my_map");

        ft::Map<char, int>::key_compare my_comp = my_map.key_comp();

        if (my_comp('a', 'b'))
            std::cout<<"\033[1;32m"<<"my key_compare works!"<<"\033[0m"<<std::endl;
        else
            std::cout<<"\033[1;32m"<<"my key_compare doesn't works.."<<"\033[0m"<<std::endl;
 
        printResult(res);
    }

    printTest("[Map] value_comp test");
    {
        printCase("check value compare object of std::map<char, int> std_map");
        std::map<char, int> std_map;
        std::map<char, int>::value_compare std_comp = std_map.value_comp();

        if (std_comp(std::make_pair('a', 1), std::make_pair('b', 2)))
            std::cout<<"\033[1;37m"<<"std key_compare works!"<<"\033[0m"<<std::endl;
        else
            std::cout<<"\033[1;37m"<<"std key_compare doesn't works.."<<"\033[0m"<<std::endl;
        
        
        printCase("check value compare object of ft::Map<char, int> my_map");
        ft::Map<char, int> my_map;
        ft::Map<char, int>::value_compare my_comp = my_map.value_comp();

        if (my_comp(ft::make_pair('a', 1), ft::make_pair('b', 2)))
            std::cout<<"\033[1;32m"<<"my key_compare works!"<<"\033[0m"<<std::endl;
        else
            std::cout<<"\033[1;32m"<<"my key_compare doesn't works.."<<"\033[0m"<<std::endl;
 
        printResult(res);
    }

}