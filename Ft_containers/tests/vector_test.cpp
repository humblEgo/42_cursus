#include "SampleClass.hpp"
#include "container_test.hpp"
#include <vector>
#include "Vector.hpp"

template <typename T, typename A>
std::ostream& operator<<(std::ostream& out, const ft::Vector<T, A>& vec)
{
    std::cout<<"===============    my_vec    ================"<<std::endl;
    out<<"size    : "<<vec.size()<<"\n";
    out<<"capacity: "<<vec.capacity()<<"\n";
    std::cout<<"member: [ ";
    for (typename ft::Vector<T, A>::ConstIterator it = vec.begin(); it != vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"]"<<std::endl;
    return (out);
}

template <typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T, A>& vec)
{
    std::cout<<"===============    std_vec    ================"<<std::endl;
    out<<"size    : "<<vec.size()<<"\n";
    out<<"capacity: "<<vec.capacity()<<"\n";
    std::cout<<"member: [ ";
    for (typename std::vector<T, A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"]"<<std::endl;
    return (out);
}


void vectorTest()
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
    std::cout<<"\033[1;37;41m"<<"Vector test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/
    
    printTest("default constructor");
    {
        ft::Vector<SampleClass> my_vec;
        ft::Vector<int> my_vec2(5);

        my_vec.insert(my_vec.begin(), SampleClass("iwoo"));
        my_vec.insert(my_vec.begin(), SampleClass("humblego"));
        ft::Vector<int> my_vec3(5, 42);
        ft::Vector<int> my_vec4(my_vec3.begin(), my_vec3.end());
        ft::Vector<SampleClass> my_vec5(my_vec.begin(), my_vec.end());

        // std::cout<<std::endl;
        // std::cout<<my_vec<<std::endl;
        // std::cout<<my_vec2<<std::endl;
        // std::cout<<my_vec3<<std::endl;
        // std::cout<<my_vec4<<std::endl;
        // std::cout<<my_vec5<<std::endl;

        res = true;
        printResult(res);
    }

    printTest("copy constructor && assign operator");
    { 
        ft::Vector<SampleClass> orignial_vec;
        orignial_vec.insert(orignial_vec.begin(), SampleClass(data[0]));
        orignial_vec.insert(orignial_vec.begin(), SampleClass(data[1]));
        orignial_vec.insert(orignial_vec.begin(), SampleClass(data[2]));
        orignial_vec.insert(orignial_vec.begin(), SampleClass(data[3]));

        std::cout<<std::endl;
        std::cout<<"\033[1;31m"<<"👇 original vec👇"<<std::endl;
        std::cout<<orignial_vec<<"\033[0m"<<std::endl;

        ft::Vector<SampleClass> copy_vec(orignial_vec);
        std::cout<<"\033[1;34m"<<"👇 copy vec 👇"<<std::endl;
        std::cout<<copy_vec<<"\033[0m"<<std::endl;
        
        ft::Vector<SampleClass> assign_vec;
        assign_vec = orignial_vec;
        std::cout<<"\033[1;36m"<<"👇 assign vec 👇"<<std::endl;
        std::cout<<assign_vec<<"\033[0m"<<std::endl;

        copy_vec.clear();
        assign_vec.clear();

        printCase("After copy_vec && assign_vec clear");
        std::cout<<"\033[1;31m"<<"👇 original vec👇"<<std::endl;
        std::cout<<orignial_vec<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;34m"<<"👇 copy vec 👇"<<std::endl;
        std::cout<<copy_vec<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;36m"<<"👇 assign vec 👇"<<std::endl;
        std::cout<<assign_vec<<"\033[0m"<<std::endl;
        
        res = checkResultManually();
        printResult(res);
    }

    
    /*==========================================================*/
    /*############### Iterator functions  tests ################*/
    /*==========================================================*/

    printTest("[Vector]begin test");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);
        ft::Vector<int>::Iterator itr;

        itr = my_vec.begin();
        *(my_vec.begin()) = 42;
        if (itr[0] == 42)
            res = true;
        else
            res = false;
        printResult(res);
    }

    /*==========================================================*/
    /*####################  Capacity tests  ####################*/
    /*==========================================================*/
    
    printTest("[Vector]size test");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);
        // std::cout<<std_vec.size()<<" ";
        // std::cout<<my_vec.size()<<" ";
        if (std_vec.size() == my_vec.size())
            res = true;
        else
            res = false;

        res = true;
        printResult(res);
    }

    printTest("[Vector]max_size test");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);

        if (std_vec.max_size() == my_vec.max_size())
            res = true;
        else
            res = false;
        
        printResult(res);
    }

        printTest("[Vector]empty test");
    {
        ft::Vector<int> empty_vec;
        ft::Vector<int> noempty_vec(5);

        if (empty_vec.empty() && !noempty_vec.empty())
            res = true;
        else
            res = false;
        printResult(res);
    }

    printTest("[Vector]capacity test");
    {
        ft::Vector<int> empty_vec;
        ft::Vector<int> noempty_vec(5);

        if (empty_vec.capacity() == 0 && noempty_vec.capacity() == 5)
            res = true;
        else
            res = false;
        printResult(res);
    }

    /*==========================================================*/
    /*#################  Element Access tests ##################*/
    /*==========================================================*/

    printTest("[Vector]operator[] test");
    {
        ft::Vector<int> int_vec(1);

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = int_vec.begin();
            int_vec.insert(itr, 42 + i);
        }
        res = true;
        for (int i = 0; i < 5; i++)
        {
            if (int_vec[i] != 42 + 4 - i)
            {
                res = false;
                break;
            }
        }
        if (res)
        {
            ft::Vector<SampleClass> class_vec(1);

            for (size_t i = 0; i < 5; i++)
            {
                ft::Vector<SampleClass>::Iterator itr = class_vec.begin();
                class_vec.insert(itr, SampleClass(data[i]));
            }
            std::string tmp[5];
            for (size_t i = 0; i < 5; i++)
                tmp[i] = data[4 - i];
            for (size_t i = 0; i < 5; i++)
            {
                // std::cout<<" "<<class_vec[i].getName()<<" ";
                // std::cout<<tmp[i];
                if (class_vec[i].getName() != tmp[i])
                {
                    res = false;
                    break;
                }
            }
        }
        printResult(res);
    }

    printTest("[Vector]at test");
    {
        ft::Vector<int> int_vec(1);

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = int_vec.begin();
            itr = int_vec.insert(itr, 42 + i);
        }
        res = true;
        for (int i = 0; i < 5; i++)
        {
            if (int_vec.at(i) != 42 + 4 - i)
            {
                res = false;
                break;
            }
        }
        if (res)
        {
            ft::Vector<SampleClass> class_vec(1);

            for (size_t i = 0; i < 5; i++)
            {
                ft::Vector<SampleClass>::Iterator itr2 = class_vec.begin();
                class_vec.insert(itr2, SampleClass(data[i]));
            }
            std::string tmp[5];
            for (size_t i = 0; i < 5; i++)
                tmp[i] = data[4 - i];
            for (size_t i = 0; i < 5; i++)
            {
                // std::cout<<" "<<class_vec[i].getName()<<" ";
                // std::cout<<tmp[i];
                if (class_vec.at(i).getName() != tmp[i])
                {
                    res = false;
                    break;
                }
            }
        }
        printResult(res);
    }

    printTest("[Vector]front test");
    {
        ft::Vector<SampleClass> my_vec(1);
        std::vector<SampleClass> std_vec(1);

        for (size_t i = 0; i < 5; i++)
        {
            ft::Vector<SampleClass>::Iterator itr = my_vec.begin();
            my_vec.insert(itr, SampleClass(data[i]));
        }
        for (size_t i = 0; i < 5; i++)
        {
            std::vector<SampleClass>::iterator itr2 = std_vec.begin();
            std_vec.insert(itr2, SampleClass(data[i]));
        }

        if (my_vec.front().getName() == std_vec.front().getName())
            res = true;
        else
            res = false;
        printResult(res);
    }

    printTest("[Vector]back test");
    {
        ft::Vector<SampleClass> my_vec(1);
        std::vector<SampleClass> std_vec(1);

        for (size_t i = 0; i < 5; i++)
        {
            ft::Vector<SampleClass>::Iterator itr = my_vec.begin();
            my_vec.insert(itr, SampleClass(data[i]));
        }
        for (size_t i = 0; i < 5; i++)
        {
            std::vector<SampleClass>::iterator itr2 = std_vec.begin();
            std_vec.insert(itr2, SampleClass(data[i]));
        }

        if (my_vec.back().getName() == std_vec.back().getName())
            res = true;
        else
            res = false;
        printResult(res);
    }
    
     /*==========================================================*/
    /*####################  Modifiers tests  ###################*/
    /*==========================================================*/
    
    printTest("[Vector]reserve and insert test");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);

        std::cout<<std::endl;
        std::cout<<my_vec<<std::endl;
        my_vec.reserve(100);
        std_vec.reserve(100);
        printCase("after reserve(100)");
        std::cout<<my_vec<<std::endl;
        ft::Vector<int>::Iterator itr;
        std::vector<int>::iterator std_itr;

        itr = my_vec.begin();
        std::cout<<std::endl;
        for (int i = 0; i < 5; i++)
            itr = my_vec.insert(itr, 42 + i);
        std::cout<<"\033[1;34m"<<my_vec<<"\033[0m"<<std::endl;

        std_itr = std_vec.begin();
        for (int i = 0; i < 5; i++)
            std_itr = std_vec.insert(std_itr, 42 + i);
        std::cout<<"\033[1;36m"<<std_vec<<"\033[0m"<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

   printTest("[Vector]erase test");
    {
        ft::Vector<int> vec;
        ft::Vector<int>::Iterator itr = vec.begin();

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = vec.begin();
            itr = vec.insert(itr, 42 + i);
        }
        std::cout<<std::endl;
        std::cout<<vec<<std::endl;
        vec.erase(vec.begin());
        printCase("After erase begin itr");
        std::cout<<vec<<std::endl;
        vec.erase(vec.begin(), (vec.begin()) + 1);
        printCase("After erase begin itr to next of begin itr");
        std::cout<<vec<<std::endl;
        
        res = checkResultManually();
        printResult(res);
    }

    printTest("[Vector]swap test");
    {
        ft::Vector<int> vec1(1);
        ft::Vector<int> vec2(1);

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = vec1.begin();
            vec1.insert(itr, 42 + i);
        }

        for (int i = 0; i < 3; i++)
        {
            ft::Vector<int>::Iterator itr = vec2.begin();
            vec2.insert(itr, i);
        }

        std::cout<<std::endl;
        std::cout<<"\033[1;31m"<<"👇 vec1 👇"<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;31m"<<vec1<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;34m"<<"👇 vec2 👇"<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;34m"<<vec2<<"\033[0m"<<std::endl;

        printCase("After swap");
        vec1.swap(vec2);
        std::cout<<"\033[1;31m"<<"👇 vec1 👇"<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;31m"<<vec1<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;34m"<<"👇 vec2 👇"<<"\033[0m"<<std::endl;
        std::cout<<"\033[1;34m"<<vec2<<"\033[0m"<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    printTest("[Vector]clear test");
    {
        ft::Vector<int> vec;

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = vec.begin();
            vec.insert(itr, 42 + i);
        }
        std::cout<<std::endl;
        std::cout<<vec<<std::endl;
        vec.clear();
        printCase("After clear");
        std::cout<<vec<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    printTest("[Vector]push_back test");
    {
        ft::Vector<SampleClass> vec;

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<SampleClass>::Iterator itr = vec.begin();
            vec.insert(itr, SampleClass(data[i]));
        }
        std::cout<<std::endl;
        std::cout<<vec<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    printTest("[Vector]pop_back test");
    {
        ft::Vector<SampleClass> vec;

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<SampleClass>::Iterator itr = vec.begin();
            vec.insert(itr, SampleClass(data[i]));
        }
        std::cout<<vec<<std::endl;

        printCase("After pop_back 2 times");
        for (size_t i = 0; i < 2; i++)
            vec.pop_back();
        
        std::cout<<std::endl;
        std::cout<<vec<<std::endl;

        res = checkResultManually();
        printResult(res);
    }


}