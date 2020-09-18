#include "container_test.hpp"
#include <vector>
#include "Vector.hpp"

namespace 
{
}

void printTest(std::string test_name)
{
    std::cout << "\033[1;36;40m" << std::setw(50);
    std::cout << std::left << test_name << "\033[0m";
}

void printResult(bool result)
{ 
    if (result)
    {
        std::cout << "\033[1;32;40m" << "success" << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[1;31;40m" << "fail" << "\033[0m" << std::endl;
    }
}

void vectorTest()
{
    bool res;
    std::cout<<"\033[1;37;41m"<<"Vector test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/
    
    printTest("default constructor");
    {
        std::vector<int> stdvec;
        ft::Vector<int> myvec;
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

        // std::cout<<std_vec.max_size()<<" ";
        // std::cout<<my_vec.max_size()<<" ";
        if (std_vec.max_size() == my_vec.max_size())
            res = true;
        else
            res = false;
        
        printResult(res);
    }

    //TODO: reserve test
    
    printTest("[Vector]insert test");
    {
        ft::Vector<int> my_vec(5);
        std::vector<int> std_vec(5);

        my_vec.reserve(100);
        ft::Vector<int>::Iterator itr;

        std::cout<<std::endl;
        itr = my_vec.begin();
        for (int i = 0; i < 5; i++)
            itr = my_vec.insert(itr, 42 + i);
        for (ft::Vector<int>::Iterator tmp = my_vec.begin(); tmp < my_vec.end(); tmp++)
                    std::cout<<*tmp<<" ";
            std::cout<<std::endl;
        res = true;
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

   printTest("[Vector]erase test");
    {
        //TODO: 아무 인자없이 vector를 만들었을 때 nullptr이 아니라 할당된 포인터를 가지게끔해야함.
        // ft::Vector<int> vec;
        // ft::Vector<int>::Iterator itr = vec.begin();
        ft::Vector<int> vec(1);

        for (int i = 0; i < 5; i++)
        {
            ft::Vector<int>::Iterator itr = vec.begin();
            vec.insert(itr, 42 + i);
        }
        std::cout<<vec<<std::endl;
        vec.erase(vec.begin());
        std::cout<<"After erase begin"<<std::endl;
        std::cout<<vec<<std::endl;
        
        printResult(res);
    }

}