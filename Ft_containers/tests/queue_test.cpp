#include "SampleClass.hpp"
#include "container_test.hpp"
#include "Queue.hpp"
#include <queue>

template <typename T>
std::ostream& operator<<(std::ostream& out, const ft::Queue<T>& que)
{
    std::cout<<"===============   my_que    ==============="<<std::endl;
    out<<"size : "<<que.size()<<"\n";
    std::cout<<"front: [ ";
    std::cout<<que.front()<<" ]"<<std::endl;
    return (out);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::queue<T>& que)
{
    std::cout<<"===============   std_que   ==============="<<std::endl;
    out<<"size : "<<que.size()<<"\n";
    std::cout<<"front: [ ";
    std::cout<<que.front()<<" ]"<<std::endl;
    return (out);
}

void queueTest()
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
    std::cout<<"\033[1;37;41m"<<"Queue test start"<<"\033[0m"<<std::endl;

    /*==========================================================*/
    /*####################  Constructor test  ##################*/
    /*==========================================================*/

    printTest("[Queue] Constructor test");
    {
        ft::Queue<SampleClass> my_que;
        ft::Queue<int> my_que2;

        std::queue<SampleClass> std_que;
        std::queue<int> std_que2;

        if (my_que.size() != std_que.size() ||
            my_que2.size() != std_que2.size())
            res = false;
        else
            res = true; 
        printResult(res);
    }

    /*==========================================================*/
    /*###################  Modifiers test  #####################*/
    /*==========================================================*/

    printTest("[Queue] push && size && front test");
    {
        ft::Queue<SampleClass> my_que;
        std::queue<SampleClass> std_que;

        printCase("push one to five");
        for (size_t i = 0; i < 5; i++)
        {
            my_que.push(SampleClass(data[i]));
            std_que.push(SampleClass(data[i]));
        }

        // size and front is overloaded with "<<"
        std::cout<<my_que<<std::endl;
        std::cout<<std_que<<std::endl;

        if (my_que.front() != std_que.front() ||
            my_que.size() != std_que.size())
            res = false;
        else
            res = true;
        printResult(res);
    }

    printTest("[Queue] pop test");
    {
        ft::Queue<SampleClass> my_que;
        std::queue<SampleClass> std_que;

        printCase("push one to five && pop 3 times");
        for (size_t i = 0; i < 5; i++)
        {
            my_que.push(SampleClass(data[i]));
            std_que.push(SampleClass(data[i]));
        }
        for (size_t i = 0; i < 3; i++)
        {
            my_que.pop();
            std_que.pop();
        }

        std::cout<<my_que<<std::endl;
        std::cout<<std_que<<std::endl;

        if (my_que.front() != std_que.front() ||
            my_que.size() != std_que.size())
            res = false;
        else
            res = true;
        printResult(res);
    }

    printTest("[Queue] empty test");
    {
        ft::Queue<SampleClass> my_que;
        std::queue<SampleClass> std_que;

        std::cout<<std::endl;
        std::cout<<"my_que : Empty->"<<my_que.empty()<<std::endl;
        std::cout<<"std_que: Empty->"<<std_que.empty()<<std::endl;
        printCase("push one to five");
        for (size_t i = 0; i < 5; i++)
        {
            my_que.push(SampleClass(data[i]));
            std_que.push(SampleClass(data[i]));
        }
        std::cout<<"my_que : Empty->"<<my_que.empty()<<std::endl;
        std::cout<<"std_que: Empty->"<<std_que.empty()<<std::endl;

        if (my_que.empty() != std_que.empty())
            res = false;
        else
            res = true;
        printResult(res);
    }

    /*==========================================================*/
    /*##########  copy constructor && assign test  #############*/
    /*==========================================================*/

    printTest("[Queue] copy constructor test");
    {
        ft::Queue<SampleClass> base_Queue;

        printCase("base_Queue.push(one to five) and copy to my_que");
        for (size_t i = 0; i < 5; i++)
            base_Queue.push(SampleClass(data[i]));

        ft::Queue<SampleClass> my_que(base_Queue);
        std::cout<<my_que<<std::endl;
        printCase("my_que.pop()");
        my_que.pop();
        std::cout<<my_que<<std::endl;
        std::cout<<"👇 base_Queue👇 "<<std::endl;
        std::cout<<base_Queue<<std::endl;

        if (my_que.front() == base_Queue.front())
            res = false;
        else
            res = true;
        
        printResult(res);
    }

    printTest("[Queue] assign constructor test");
    {
        ft::Queue<SampleClass> base_Queue;

        printCase("base_Queue.push(one to five) and copy to my_que");
        for (size_t i = 0; i < 5; i++)
            base_Queue.push(SampleClass(data[i]));

        ft::Queue<SampleClass> my_que;
        my_que = base_Queue;
        std::cout<<my_que<<std::endl;
        printCase("my_que.pop()");
        my_que.pop();
        std::cout<<my_que<<std::endl;
        std::cout<<"👇 base_Queue👇 "<<std::endl;
        std::cout<<base_Queue<<std::endl;

        if (my_que.front() == base_Queue.front())
            res = false;
        else
            res = true;
        printResult(res);
    }

    printTest("[Queue] oprators test");
    {
        ft::Queue<int> my_que;
        std::queue<int> std_que;

        for (size_t i = 0; i < 5; i++)
        {
            my_que.push(i);
            std_que.push(i);
        }

        std::cout<<std::endl;
        std::cout<<my_que<<std::endl;
        std::cout<<std_que<<std::endl;

        std::cout<<"[std_que == std_que] : "<<(std_que == std_que)<<std::endl;
        std::cout<<"[my_que == my_que]   : "<<(my_que == my_que)<<std::endl;
        
        std::cout<<"[std_que != std_que] : "<<(std_que != std_que)<<std::endl;
        std::cout<<"[my_que != my_que]   : "<<(my_que != my_que)<<std::endl;

        std::cout<<"[std_que >= std_que] : "<<(std_que >= std_que)<<std::endl;
        std::cout<<"[my_que >= my_que]   : "<<(my_que >= my_que)<<std::endl;

        std::cout<<"[std_que > std_que] : "<<(std_que > std_que)<<std::endl;
        std::cout<<"[my_que > my_que]   : "<<(my_que > my_que)<<std::endl;

        std::cout<<"[std_que <= std_que] : "<<(std_que <= std_que)<<std::endl;
        std::cout<<"[my_que <= my_que]   : "<<(my_que <= my_que)<<std::endl;

        std::cout<<"[std_que < std_que] : "<<(std_que < std_que)<<std::endl;
        std::cout<<"[my_que < my_que]   : "<<(my_que < my_que)<<std::endl;

        printResult(res);
    }

    //TODO: Container 타입을 바꿔보기

}