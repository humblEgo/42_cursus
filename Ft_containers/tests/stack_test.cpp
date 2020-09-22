#include "SampleClass.hpp"
#include "container_test.hpp"
#include "Stack.hpp"
#include <stack>

template <typename T>
std::ostream& operator<<(std::ostream& out, const ft::Stack<T>& stk)
{
    std::cout<<"===============   my_stack    ==============="<<std::endl;
    out<<"size: "<<stk.size()<<"\n";
    std::cout<<"top : [ ";
    std::cout<<stk.top()<<" ]"<<std::endl;
    return (out);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::stack<T>& stk)
{
    std::cout<<"===============   std_stack   ==============="<<std::endl;
    out<<"size: "<<stk.size()<<"\n";
    std::cout<<"top : [ ";
    std::cout<<stk.top()<<" ]"<<std::endl;
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
        ft::Stack<SampleClass> my_stack;
        ft::Stack<int> my_stack2;

        std::stack<SampleClass> std_stack;
        std::stack<int> std_stack2;

        if (my_stack.size() != std_stack.size() ||
            my_stack2.size() != std_stack2.size())
            res = false;
        else
            res = true; 
        printResult(res);
    }

    /*==========================================================*/
    /*###################  Modifiers test  #####################*/
    /*==========================================================*/

    printTest("[Stack] push && size && top test");
    {
        ft::Stack<SampleClass> my_stack;
        std::stack<SampleClass> std_stack;

        printCase("push one to five");
        for (size_t i = 0; i < 5; i++)
        {
            my_stack.push(SampleClass(data[i]));
            std_stack.push(SampleClass(data[i]));
        }

        // size and top is overloaded with "<<"
        std::cout<<my_stack<<std::endl;
        std::cout<<std_stack<<std::endl;

        if (my_stack.top() != std_stack.top() ||
            my_stack.size() != std_stack.size())
            res = false;
        else
            res = true;
        printResult(res);
    }

    printTest("[Stack] pop test");
    {
        ft::Stack<SampleClass> my_stack;
        std::stack<SampleClass> std_stack;

        printCase("push one to five && pop 3 times");
        for (size_t i = 0; i < 5; i++)
        {
            my_stack.push(SampleClass(data[i]));
            std_stack.push(SampleClass(data[i]));
        }
        for (size_t i = 0; i < 3; i++)
        {
            my_stack.pop();
            std_stack.pop();
        }

        std::cout<<my_stack<<std::endl;
        std::cout<<std_stack<<std::endl;

        if (my_stack.top() != std_stack.top() ||
            my_stack.size() != std_stack.size())
            res = false;
        else
            res = true;
        printResult(res);
    }

    printTest("[Stack] empty test");
    {
        ft::Stack<SampleClass> my_stack;
        std::stack<SampleClass> std_stack;

        std::cout<<std::endl;
        std::cout<<"my_stack : Empty->"<<my_stack.empty()<<std::endl;
        std::cout<<"std_stack: Empty->"<<std_stack.empty()<<std::endl;
        printCase("push one to five");
        for (size_t i = 0; i < 5; i++)
        {
            my_stack.push(SampleClass(data[i]));
            std_stack.push(SampleClass(data[i]));
        }
        std::cout<<"my_stack : Empty->"<<my_stack.empty()<<std::endl;
        std::cout<<"std_stack: Empty->"<<std_stack.empty()<<std::endl;

        if (my_stack.empty() != std_stack.empty())
            res = false;
        else
            res = true;
        printResult(res);
    }

    /*==========================================================*/
    /*##########  copy constructor && assign test  #############*/
    /*==========================================================*/

    printTest("[Stack] copy constructor test");
    {
        ft::Stack<SampleClass> base_stack;

        printCase("base_stack.push(one to five) and copy to my_stack");
        for (size_t i = 0; i < 5; i++)
            base_stack.push(SampleClass(data[i]));

        ft::Stack<SampleClass> my_stack(base_stack);
        std::cout<<my_stack<<std::endl;
        printCase("my_stack.pop()");
        my_stack.pop();
        std::cout<<my_stack<<std::endl;
        std::cout<<"👇 base_stack👇 "<<std::endl;
        std::cout<<base_stack<<std::endl;

        if (my_stack.top() == base_stack.top())
            res = false;
        else
            res = true;
        
        printResult(res);
    }

    printTest("[Stack] assign constructor test");
    {
        ft::Stack<SampleClass> base_stack;

        printCase("base_stack.push(one to five) and copy to my_stack");
        for (size_t i = 0; i < 5; i++)
            base_stack.push(SampleClass(data[i]));

        ft::Stack<SampleClass> my_stack;
        my_stack = base_stack;
        std::cout<<my_stack<<std::endl;
        printCase("my_stack.pop()");
        my_stack.pop();
        std::cout<<my_stack<<std::endl;
        std::cout<<"👇 base_stack👇 "<<std::endl;
        std::cout<<base_stack<<std::endl;

        if (my_stack.top() == base_stack.top())
            res = false;
        else
            res = true;
        printResult(res);
    }

    printTest("[Stack] oprators test");
    {
        ft::Stack<int> my_stack;
        std::stack<int> std_stack;

        for (size_t i = 0; i < 5; i++)
        {
            my_stack.push(i);
            std_stack.push(i);
        }

        std::cout<<std::endl;
        std::cout<<my_stack<<std::endl;
        std::cout<<std_stack<<std::endl;

        std::cout<<"[std_stack == std_stack] : "<<(std_stack == std_stack)<<std::endl;
        std::cout<<"[my_stack == my_stack]   : "<<(my_stack == my_stack)<<std::endl;
        
        std::cout<<"[std_stack != std_stack] : "<<(std_stack != std_stack)<<std::endl;
        std::cout<<"[my_stack != my_stack]   : "<<(my_stack != my_stack)<<std::endl;

        std::cout<<"[std_stack >= std_stack] : "<<(std_stack >= std_stack)<<std::endl;
        std::cout<<"[my_stack >= my_stack]   : "<<(my_stack >= my_stack)<<std::endl;

        std::cout<<"[std_stack > std_stack] : "<<(std_stack > std_stack)<<std::endl;
        std::cout<<"[my_stack > my_stack]   : "<<(my_stack > my_stack)<<std::endl;

        std::cout<<"[std_stack <= std_stack] : "<<(std_stack <= std_stack)<<std::endl;
        std::cout<<"[my_stack <= my_stack]   : "<<(my_stack <= my_stack)<<std::endl;

        std::cout<<"[std_stack < std_stack] : "<<(std_stack < std_stack)<<std::endl;
        std::cout<<"[my_stack < my_stack]   : "<<(my_stack < my_stack)<<std::endl;

        printResult(res);
    }

    //TODO: Container 타입을 바꿔보기

}