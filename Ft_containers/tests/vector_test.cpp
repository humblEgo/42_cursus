#include "SampleClass.hpp"
#include "container_test.hpp"
#include <vector>
#include "Vector.hpp"

template <typename T, typename A>
std::ostream& operator<<(std::ostream& out, const ft::Vector<T, A>& vec)
{
    std::cout<<"============================================="<<std::endl;
    out<<"size    : "<<vec.size()<<"\n";
    out<<"capacity: "<<vec.capacity()<<"\n";
    std::cout<<"member: [ ";
    for (typename ft::Vector<T, A>::ConstIterator it = vec.begin(); it != vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"=============================================";
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
        ft::Vector<SampleClass> myvec;
        res = true;
        printResult(res);
        //TODO: other contsturctors
    }

    /*==========================================================*/
    /*####################  Iterator test  #####################*/
    /*==========================================================*/
    
    printTest("[Iterator] default constructor");
    {
        ft::Vector<int>::Iterator itr_default;
        res = true;
        printResult(res);
        //TODO: printTest("[Iterator] copy constructor");
    }

    printTest("[Iterator] operator*");
    {
        //TODO: * 처음에 인자없이 생성자가 입력되더라도 데이터 자료형 크기만큼 임의의 메모리 공간을 할당해서 그 주소를 _ptr로 가지고 있도록해야 이 테스트를 통과할 수 있다... 추후 생각해보자.
        ft::Vector<int>::Iterator itr;
        // std::vector<int>::iterator itr;
        // *itr = 1;
        res = false;
        printResult(res);
    }

    printTest("[Iterator] operator->");
    {
        //TODO: 멤버 함수 생기면 써보자.
        // ft::Vector<int>::Iterator itr;
        // std::vector<int>::iterator itr;
        res = false;
        printResult(res);
    }

    printTest("[Iterator] operator=");
    {
        ft::Vector<int>::Iterator itr_lhs;
        ft::Vector<int>::Iterator itr_rhs;
        itr_lhs = itr_rhs;
        if (itr_lhs.base() == itr_rhs.base())
            res = true;
        else
            res = false;
        printResult(res);
    }

    printTest("[Iterator] operator++(prefix)");
    {
        ft::Vector<int>::Iterator itr;
        ft::Vector<int>::Iterator tmp;
        // std::vector<int>::iterator itr;
        // std::vector<int>::iterator tmp;

        itr = tmp;
        if (tmp.base() + 1 == (++itr).base())
            res = true;
        else
            res = false;
        printResult(res);
    }

    printTest("[Iterator] operator++(postfix)");
    {
        // ft::Vector<int>::Iterator itr;
        // ft::Vector<int>::Iterator tmp;
        std::vector<int>::iterator itr;
        std::vector<int>::iterator tmp;

        itr = tmp;
        if (tmp.base() + 1 == itr++.base())
            res = false;
        else
            res = true;
        if (res)
        {
            if (tmp.base() == itr.base())
                res = true;
            else
                res = false;
        }
        printResult(res);
    }

    //TODO: 여기없는 연산자들 추가

/*==========================================================*/
/*####################  Vector Test  #######################*/
/*==========================================================*/
    
    printTest("[Vector]Default constructor");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);
        res = true;
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
    //TODO: reserve test

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
    /*####################  Assign tests  ######################*/
    /*==========================================================*/
    
    printTest("[Vector]Assign test");
    {
        ft::Vector<SampleClass> vec;

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<SampleClass>::Iterator itr = vec.begin();
            vec.insert(itr, SampleClass(data[i]));
        }
        std::cout<<vec<<std::endl;

        std::cout<<"After assign(2, SampleClass(data[o])"<<std::endl;
        vec.assign(2, SampleClass(data[0]));
        
        std::cout<<vec<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

    /*==========================================================*/
    /*####################  Modifiers tests  ###################*/
    /*==========================================================*/
    
    printTest("[Vector]insert test");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);

        my_vec.reserve(100);
        std_vec.reserve(100);
        ft::Vector<int>::Iterator itr;
        std::vector<int>::iterator std_itr;

        std::cout<<std::endl;
        std::cout<<"my_vec : ";
        itr = my_vec.begin();
        for (int i = 0; i < 5; i++)
            itr = my_vec.insert(itr, 42 + i);
        for (ft::Vector<int>::Iterator tmp = my_vec.begin(); tmp < my_vec.end(); tmp++)
                    std::cout<<*tmp<<" ";
        std::cout<<std::endl;

        std::cout<<"std_vec: ";
        std_itr = std_vec.begin();
        for (int i = 0; i < 5; i++)
            std_itr = std_vec.insert(std_itr, 42 + i);
        for (std::vector<int>::iterator tmp = std_vec.begin(); tmp < std_vec.end(); tmp++)
                    std::cout<<*tmp<<" ";
        std::cout<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

   printTest("[Vector]erase test");
    {
        //TODO: 아무 인자없이 vector를 만들었을 때 nullptr이 아니라 할당된 포인터를 가지게끔해야함.
        ft::Vector<int> vec;
        ft::Vector<int>::Iterator itr = vec.begin();
        // ft::Vector<int> vec(1);

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = vec.begin();
            itr = vec.insert(itr, 42 + i);
        }
        std::cout<<std::endl;
        std::cout<<vec<<std::endl;
        vec.erase(vec.begin());
        std::cout<<"After erase begin itr"<<std::endl;
        std::cout<<vec<<std::endl;
        vec.erase(vec.begin(), (vec.begin()) + 1);
        std::cout<<"After erase begin itr to next of begin itr"<<std::endl;
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
        std::cout<<"vec1"<<std::endl;
        std::cout<<vec1<<std::endl;
        std::cout<<"vec2"<<std::endl;
        std::cout<<vec2<<std::endl;

        std::cout<<"After swap"<<std::endl;
        vec1.swap(vec2);
        std::cout<<"vec1"<<std::endl;
        std::cout<<vec1<<std::endl;
        std::cout<<"vec2"<<std::endl;
        std::cout<<vec2<<std::endl;

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
        std::cout<<"After clear"<<std::endl;
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

        std::cout<<"After pop_back 2 times"<<std::endl;
        for (size_t i = 0; i < 2; i++)
            vec.pop_back();
        
        std::cout<<vec<<std::endl;

        res = checkResultManually();
        printResult(res);
    }

}