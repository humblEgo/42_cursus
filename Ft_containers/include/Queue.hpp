#ifndef QUEUE_HPP 
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{
/*==========================================================*/
/*#################     Queue prototype     ################*/
/*==========================================================*/

template <typename T, typename C = ft::List<T> >
class Queue
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
    
    explicit Queue(const container_type& cont = container_type());
    virtual ~Queue();
    explicit Queue(Queue const& other);
    Queue& operator=(Queue const& other);

    /*==========================================================*/
    /*####################  Element access  ####################*/
    /*==========================================================*/

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

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
    
    friend bool operator==(const Queue<T, C>& lhs, const Queue<T, C>& rhs) { return (lhs._cont == rhs._cont ); };
    friend bool operator!=(const Queue<T, C>& lhs, const Queue<T, C>& rhs) { return (!(lhs == rhs)); };
    friend bool operator<(const Queue<T, C>& lhs, const Queue<T, C>& rhs) { return (lhs._cont < rhs._cont); };
    friend bool operator>(const Queue<T, C>& lhs, const Queue<T, C>& rhs) { return (lhs._cont > rhs._cont); };
    friend bool operator<=(const Queue<T, C>& lhs, const Queue<T, C>& rhs) { return (!(lhs > rhs)); };
    friend bool operator>=(const Queue<T, C>& lhs, const Queue<T, C>& rhs) { return (!(lhs < rhs)); };
};

/*==========================================================*/
/*####################  Canonical form   ###################*/
/*==========================================================*/

template <typename T, typename C>
Queue<T, C>::Queue(const container_type& cont) : _cont(cont) {}

template <typename T, typename C>
Queue<T, C>::Queue(Queue const &other) : _cont(other._cont) {}

template <typename T, typename C>
Queue<T, C>& Queue<T, C>::operator=(Queue const& other)
{
    _cont = other._cont;
    return (*this);
}

template <typename T, typename C>
Queue<T, C>::~Queue() {}

/*==========================================================*/
/*####################  Element access  ####################*/
/*==========================================================*/

template <typename T, typename C>
typename Queue<T, C>::reference Queue<T, C>::front()
{
    return (_cont.front());
}

template <typename T, typename C>
typename Queue<T, C>::const_reference Queue<T, C>::front() const
{
    return (_cont.front());
}

template <typename T, typename C>
typename Queue<T, C>::reference Queue<T, C>::back()
{
    return (_cont.back());
}

template <typename T, typename C>
typename Queue<T, C>::const_reference Queue<T, C>::back() const
{
    return (_cont.back());
}

/*==========================================================*/
/*######################  Capacity  ########################*/
/*==========================================================*/

template <typename T, typename C>
bool Queue<T, C>::empty() const
{
    return (_cont.empty());
}

template <typename T, typename C>
typename Queue<T, C>::size_type Queue<T, C>::size() const
{
    return (_cont.size());
}

/*==========================================================*/
/*######################  Modifiers  #######################*/
/*==========================================================*/

template <typename T, typename C>
void Queue<T, C>::push(const value_type& value)
{
    _cont.push_back(value);
}

template <typename T, typename C>
void Queue<T, C>::pop()
{
    _cont.pop_front();
}

};

#endif