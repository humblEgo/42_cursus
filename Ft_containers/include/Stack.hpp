#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
/*==========================================================*/
/*#################     Stack prototype     ################*/
/*==========================================================*/

template <typename T, typename C = ft::List<T> >
class Stack
{
public:
    typedef T value_type;
    typedef C container_type;
    typedef typename C::reference reference;
    typedef typename C::const_reference const_reference;
    typedef typename C::size_type size_type;

private:
    container_type _cont;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    
    explicit Stack(const container_type& cont = container_type());
    virtual ~Stack();
    explicit Stack(Stack const& other);
    Stack& operator=(Stack const& other);

    /*==========================================================*/
    /*####################  Element access  ####################*/
    /*==========================================================*/

    reference top();
    const_reference top() const;

    /*==========================================================*/
    /*######################  Capacity  ########################*/
    /*==========================================================*/

    bool empty() const;
    size_type size() const;

    /*==========================================================*/
    /*######################  Modifiers  #######################*/
    /*==========================================================*/

    void push(const value_type& value);
    void pop();

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/
    
    friend bool operator==(const Stack<T, C>& lhs, const Stack<T, C>& rhs);
    friend bool operator!=(const Stack<T, C>& lhs, const Stack<T, C>& rhs);
    friend bool operator<(const Stack<T, C>& lhs, const Stack<T, C>& rhs);
    friend bool operator>(const Stack<T, C>& lhs, const Stack<T, C>& rhs);
    friend bool operator<=(const Stack<T, C>& lhs, const Stack<T, C>& rhs);
    friend bool operator>=(const Stack<T, C>& lhs, const Stack<T, C>& rhs);
};

/*==========================================================*/
/*####################  Canonical form   ###################*/
/*==========================================================*/

template <typename T, typename C>
Stack<T, C>::Stack(const container_type& cont) : _cont(cont) {}

template <typename T, typename C>
Stack<T, C>::Stack(Stack const &other) : _cont(other.base) {}

template <typename T, typename C>
Stack<T, C>& Stack<T, C>::operator=(Stack const& other)
{
    _cont = other.base;
    return (*this);
}

template <typename T, typename C>
Stack<T, C>::~Stack() {}

/*==========================================================*/
/*####################  Element access  ####################*/
/*==========================================================*/

template <typename T, typename C>
typename Stack<T, C>::reference Stack<T, C>::top()
{
    return (_cont.back());
}

template <typename T, typename C>
typename Stack<T, C>::const_reference Stack<T, C>::top() const
{
    return (_cont.back());
}

/*==========================================================*/
/*######################  Capacity  ########################*/
/*==========================================================*/

template <typename T, typename C>
bool Stack<T, C>::empty() const
{
    return (_cont.empty());
}

template <typename T, typename C>
typename Stack<T, C>::size_type Stack<T, C>::size() const
{
    return (_cont.size());
}

/*==========================================================*/
/*######################  Modifiers  #######################*/
/*==========================================================*/

template <typename T, typename C>
void Stack<T, C>::push(const value_type& value)
{
    _cont.push_back(value);
}

template <typename T, typename C>
void Stack<T, C>::pop()
{
    _cont.pop_back();
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

template <typename T, typename C>
bool operator==(const Stack<T, C>& lhs, const Stack<T, C>& rhs)
{
    return (lhs._cont == rhs._cont);
}

template <typename T, typename C>
bool operator!=(const Stack<T, C>& lhs, const Stack<T, C>& rhs)
{
    return (!(lhs == rhs));
}

template <typename T, typename C>
bool operator<(const Stack<T, C>& lhs, const Stack<T, C>& rhs)
{
    return (lhs._cont < rhs._cont);
}

template <typename T, typename C>
bool operator>(const Stack<T, C>& lhs, const Stack<T, C>& rhs)
{
    return (lhs._cont > rhs._cont);
}

template <typename T, typename C>
bool operator<=(const Stack<T, C>& lhs, const Stack<T, C>& rhs)
{
    return (!(lhs > rhs));
}

template <typename T, typename C>
bool operator>=(const Stack<T, C>& lhs, const Stack<T, C>& rhs)
{
    return (!(lhs < rhs));
}

/*==========================================================*/
/*####################  Custom for test  ###################*/
/*==========================================================*/

template <typename T, typename C>
std::ostream& operator<<(std::ostream& out, const Stack<T, C>& stk)
{
    std::cout<<"============================================="<<std::endl;
    out<<"top   : "<<stk.top()<<"\n";
    std::cout<<"member: [ ";
    // for (typename Stack<T, C>::Iterator it = stk.begin(); it != stk.end(); ++it)
    //     std::cout<<*it<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"=============================================";
    return (out);
}

std::ostream& operator<<(std::ostream& out, const Stack<SampleClass>& stk)
{
    std::cout<<"============================================="<<std::endl;
    out<<"top   : "<<stk.top()<<"\n";
    std::cout<<"member: [ ";
    // for (typename Stack<SampleClass>::Iterator it = stk.begin(); it != stk.end(); ++it)
    //     std::cout<<(*it).getName()<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"=============================================";
    return (out);
}


};

#endif