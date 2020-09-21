#include "SampleClass.hpp"
#include "container_test.hpp"
#include <list>
#include "List.hpp"

static bool comparator(SampleClass first, SampleClass second)
{
    return (first.getName() < second.getName());
}

static bool unary_predicator(SampleClass target)
{
    return (target.getName() == "five");
}

static bool binary_predicate(SampleClass first, SampleClass second)
{
    return (first.getName() == second.getName());
}


void listTest()
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
    std::cout<<"\033[1;37;41m"<<"List test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/

    printTest("[List] Constructor test");
    {

        printCase("List<SampleCalss> my_list");
        ft::List<SampleClass> my_list;
        std::cout<<my_list<<std::endl;

        printCase("List<SampleCalss> my_list(5, SampleClass(\"Wow\")");
        ft::List<SampleClass> my_list2(5, SampleClass("Wow"));
        std::cout<<my_list2<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    /*==========================================================*/
    /*####################  Iterator tests  ####################*/
    /*==========================================================*/
    
    printTest("[List] begin test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;
        for (int i = 0; i < 5; i++)
            my_list.insert(my_list.end(), SampleClass(data[i]));
        
        for (int i = 0; i < 5; i++)
            std_list.insert(std_list.end(), SampleClass(data[i]));
        
        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();
        for (size_t i = 0; i < 5; i++)
        {
            if (*my_itr != *std_itr)
            {
                res = false;
                break;
            }
            res = true;
            ++my_itr;
            ++std_itr;
        }
        printResult(res);
    }

    printTest("[List] end test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;
        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        
        ft::List<SampleClass>::Iterator my_itr = my_list.end();
        std::list<SampleClass>::iterator std_itr = std_list.end();
        for (size_t i = 0; i < 5; i++)
        {
            --my_itr;
            --std_itr;
            if (*my_itr != *std_itr)
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] rbegin && rend test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;
        for (int i = 0; i < 5; i++)
            my_list.push_back(data[i]);
        
        for (int i = 0; i < 5; i++)
            std_list.push_back(data[i]);
        
        ft::List<SampleClass>::reverse_iterator my_ritr = my_list.rbegin();
        std::list<SampleClass>::reverse_iterator std_ritr = std_list.rbegin();
        for (; my_ritr != my_list.rend() && std_ritr != std_list.rend(); ++my_ritr, ++std_ritr)
        {
            if (*my_ritr != *std_ritr)
            {
                res = false;
                break;
            }
            res = true;
        }
        if (my_list.size() != std_list.size())
            res = false;
        printResult(res);
    }
    
    /*==========================================================*/
    /*###################  Capacity tests  #####################*/
    /*==========================================================*/
    
    printTest("[List] size test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;
        for (int i = 0; i < 5; i++)
            my_list.insert(my_list.end(), SampleClass(data[i]));
        
        for (int i = 0; i < 5; i++)
            std_list.insert(std_list.end(), SampleClass(data[i]));
        
        if (my_list.size() == std_list.size())
            res = true;
        else
            res = false;

        printResult(res);
    }

    printTest("[List] max_size test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        if (my_list.max_size() == std_list.max_size())
            res = true;
        else
            res = false;

        printResult(res);
    }
    
    printTest("[List] empty test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        if (my_list.empty() == std_list.empty())
            res = true;
        else
            res = false;

        printResult(res);
    }

    /*==========================================================*/
    /*####################  Element test  ######################*/
    /*==========================================================*/
    
    printTest("[List] front test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        if (my_list.front() == std_list.front())
            res = true;
        else
            res = false;
        
        printResult(res);
    }

    printTest("[List] back test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        if (my_list.back() == std_list.back())
            res = true;
        else
            res = false;
        
        printResult(res);
    }

    /*==========================================================*/
    /*####################  Assign test  #######################*/
    /*==========================================================*/
    
    printTest("[List] Assign test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        my_list.assign(5, SampleClass("iwoo!"));
        std_list.assign(5, SampleClass("iwoo!"));
        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        if (my_list.size() != std_list.size())
            res = false;
        printResult(res);
    }

    printTest("[List] Assign(begin, end) test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        ft::List<SampleClass> new_my_list;
        std::list<SampleClass> new_std_list;
        new_my_list.assign(my_list.begin(), my_list.end());
        new_std_list.assign(std_list.begin(), std_list.end());
        ft::List<SampleClass>::Iterator my_itr = new_my_list.begin();
        std::list<SampleClass>::iterator std_itr = new_std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }


    /*==========================================================*/
    /*####################  Modifier test  #####################*/
    /*==========================================================*/
    
    printTest("[List] Insert(itr, data) test");
    {
        ft::List<SampleClass> my_list;
        for (int i = 0; i < 5; i++)
            my_list.insert(my_list.end(), SampleClass(data[i]));
        std::cout<<std::endl;
        printCase("Insert(end(), SampleClass(one ~ five))");
        std::cout<<my_list<<std::endl;

        printCase("Insert(p = begin(), b= ++begin(), e= --end())");

        my_list.insert(my_list.begin(), ++(my_list.begin()), --(my_list.end()));

        std::cout<<my_list<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    printTest("[List] push_front test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_front(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_front(SampleClass(data[i]));

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < 5; i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        
        printResult(res);
    }

    printTest("[List] push_back test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < 5; i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] pop_front test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        // 비어있는 list를 pop_front하면? segfault 나야한다!
        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        my_list.pop_front();
        std_list.pop_front();
        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] pop_back test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        // 비어있는 list를 pop_back하면? segfault 나야한다!
        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        my_list.pop_back();
        std_list.pop_back();
        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] resize test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        
        my_list.resize(3, SampleClass("iwoo"));
        std_list.resize(3, SampleClass("iwoo"));
        // printCase("Resize(3, SampleClass(\"iwoo\")");
        // std::cout<<my_list<<std::endl;

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }

        if (res)
        {
            my_list.resize(10, SampleClass("iwoo"));
            std_list.resize(10, SampleClass("iwoo"));
            // printCase("Resize(10, SampleClass(\"iwoo\")");
            // std::cout<<my_list<<std::endl;

            my_itr = my_list.begin();
            std_itr = std_list.begin();
            for (size_t i = 0; i < std_list.size(); i++)
            {
                if (*(my_itr++) != *(std_itr++))
                {
                    res = false;
                    break;
                }
                res = true;
            }
        }
        printResult(res);
    }

    printTest("[List] swap test");
    {
        ft::List<SampleClass> my_list;
        ft::List<SampleClass> my_list2;

        for (int i = 0; i < 5; i++)
            my_list.push_front(SampleClass(data[i]));
        for (int i = 0; i < 3; i++)
            my_list2.push_back(SampleClass(data[i]));
        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        ft::List<SampleClass>::Iterator my_itr2 = my_list2.begin();

        std::cout<<std::endl;
        std::cout<<"[my_list]"<<std::endl;
        std::cout<<my_list<<std::endl;

        std::cout<<"[my_list2]"<<std::endl;
        std::cout<<my_list2<<std::endl;
               
        printCase("my_list.swap(std_list)");
        my_list.swap(my_list2);
        std::cout<<"[my_list]"<<std::endl;
        std::cout<<my_list<<std::endl;
        std::cout<<"[std_list]"<<std::endl;
        std::cout<<my_list2<<std::endl;

        res = checkResultManually();
        printResult(res);
    }


    /*==========================================================*/
    /*####################  Operations  #######################*/
    /*==========================================================*/
    
    printTest("[List] merge test");
    {
        ft::List<SampleClass> my_list;
        ft::List<SampleClass> my_list2;
        std::list<SampleClass> std_list;
        std::list<SampleClass> std_list2;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            my_list2.push_back(SampleClass(data[i]));

        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            std_list2.push_back(SampleClass(data[i]));

        my_list.merge(my_list2);
        std_list.merge(std_list2);

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] merge(list& other, Compare comp) test");
    {
        ft::List<SampleClass> my_list;
        ft::List<SampleClass> my_list2;
        std::list<SampleClass> std_list;
        std::list<SampleClass> std_list2;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            my_list2.push_back(SampleClass(data[i]));

        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            std_list2.push_back(SampleClass(data[i]));

        my_list.merge(my_list2, comparator);
        std_list.merge(std_list2, comparator);

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] splice(p, other) test");
    {
        ft::List<SampleClass> my_list;
        ft::List<SampleClass> my_list2;
        std::list<SampleClass> std_list;
        std::list<SampleClass> std_list2;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            my_list2.push_back(SampleClass("!>splice-" + data[i] + "<!"));

        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            std_list2.push_back(SampleClass("!>splice-" + data[i] + "<!"));


        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        my_list.splice(++my_itr, my_list2);
        std_list.splice(++std_itr, std_list2);

        my_itr = my_list.begin();
        std_itr = std_list.begin();
        // std::cout<<my_list<<std::endl;
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        if (my_list2.size() != std_list2.size())
            res = false;
        printResult(res);
    }

    printTest("[List] splice(p, other, itr) test");
    {
        ft::List<SampleClass> my_list;
        ft::List<SampleClass> my_list2;
        std::list<SampleClass> std_list;
        std::list<SampleClass> std_list2;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            my_list2.push_back(SampleClass("!>splice-" + data[i] + "<!"));

        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            std_list2.push_back(SampleClass("!>splice-" + data[i] + "<!"));


        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        my_list.splice(++my_itr, my_list2, my_list2.begin());
        std_list.splice(++std_itr, std_list2, std_list2.begin());

        my_itr = my_list.begin();
        std_itr = std_list.begin();
        // std::cout<<my_list<<std::endl;
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        if (my_list2.size() != std_list2.size())
            res = false;
        printResult(res);
    }

    printTest("[List] splice(p, other, first, last) test");
    {
        ft::List<SampleClass> my_list;
        ft::List<SampleClass> my_list2;
        std::list<SampleClass> std_list;
        std::list<SampleClass> std_list2;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            my_list2.push_back(SampleClass("!>splice-" + data[i] + "<!"));

        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        for (int i = 5; i < 8; i++)
            std_list2.push_back(SampleClass("!>splice-" + data[i] + "<!"));


        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        my_list.splice(++my_itr, my_list2, my_list2.begin(), --(my_list2.end()));
        std_list.splice(++std_itr, std_list2, std_list2.begin(), --(std_list2.end()));

        my_itr = my_list.begin();
        std_itr = std_list.begin();
        // std::cout<<my_list<<std::endl;
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        if (my_list2.size() != std_list2.size())
            res = false;
        printResult(res);
    }

    printTest("[List] remove test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        my_list.push_back(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        std_list.push_back(SampleClass("five"));
        std_list.push_back(SampleClass("five"));
        std_list.push_back(SampleClass("five"));

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();

        // remove 'five'
        my_list.remove(SampleClass(data[4]));
        std_list.remove(SampleClass(data[4]));
        
        // remove no memeber which is not in list.
        my_list.remove(SampleClass("Non_Member"));
        std_list.remove(SampleClass("Non_member"));

        my_itr = my_list.begin();
        std_itr = std_list.begin();
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] remove_if test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        my_list.push_back(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        std_list.push_back(SampleClass("five"));
        std_list.push_back(SampleClass("five"));
        std_list.push_back(SampleClass("five"));

        // remove 'five'
        my_list.remove_if(unary_predicator);
        std_list.remove_if(unary_predicator);
        
        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] reverse test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));

        // std::cout<<my_list<<std::endl;
        // std::cout<<"After reverse"<<std::endl;
        my_list.reverse();
        std_list.reverse();
        // std::cout<<my_list<<std::endl;

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] unique test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        my_list.push_front(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        std_list.push_front(SampleClass("five"));
        std_list.push_back(SampleClass("five"));
        std_list.push_back(SampleClass("five"));

        my_list.unique();
        std_list.unique();

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] unique test");
    {
        ft::List<SampleClass> my_list;
        std::list<SampleClass> std_list;

        for (int i = 0; i < 5; i++)
            my_list.push_back(SampleClass(data[i]));
        my_list.push_front(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        my_list.push_back(SampleClass("five"));
        for (int i = 0; i < 5; i++)
            std_list.push_back(SampleClass(data[i]));
        std_list.push_front(SampleClass("five"));
        std_list.push_back(SampleClass("five"));
        std_list.push_back(SampleClass("five"));

        my_list.unique(binary_predicate);
        std_list.unique(binary_predicate);

        ft::List<SampleClass>::Iterator my_itr = my_list.begin();
        std::list<SampleClass>::iterator std_itr = std_list.begin();
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

    printTest("[List] sort test");
    {
        ft::List<int> my_list;
        std::list<int> std_list;
        
        my_list.push_back(1);
        std_list.push_back(1);
        my_list.push_back(5);
        std_list.push_back(5);
        my_list.push_back(42);
        std_list.push_back(42);
        my_list.push_back(-42);
        std_list.push_back(-42);
        my_list.push_back(777);
        std_list.push_back(777);

        my_list.sort();
        std_list.sort();
        ft::List<int>::Iterator my_itr = my_list.begin();
        std::list<int>::iterator std_itr = std_list.begin();
        for (size_t i = 0; i < std_list.size(); i++)
        {
            if (*(my_itr++) != *(std_itr++))
            {
                res = false;
                break;
            }
            res = true;
        }
        printResult(res);
    }

}