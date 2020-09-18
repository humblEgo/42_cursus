#ifndef BASEITERATOR_HPP
# define BASEITERATOR_HPP

namespace ft
{

/*==========================================================*/
/*###############  BaseIterator prototype  #################*/
/*==========================================================*/

template <typename T>
class BaseIterator
{
public:
    typedef T value_type;

protected:
    value_type *_ptr;

public:
    BaseIterator(value_type *ptr);
    virtual ~BaseIterator();
    BaseIterator(const BaseIterator& rhs);
    BaseIterator& operator=(const BaseIterator& rhs);
    bool operator==(const BaseIterator& rhs);
    bool operator!=(const BaseIterator& rhs);
    bool operator<(const BaseIterator& rhs);
    bool operator>(const BaseIterator& rhs);
    bool operator<=(const BaseIterator& rhs);
    bool operator>=(const BaseIterator& rhs);
    value_type* base() const;
};

/*==========================================================*/
/*#####################  Constructor  ######################*/
/*==========================================================*/

template <typename T>
ft::BaseIterator<T>::BaseIterator(T *ptr) : _ptr(ptr) {};

/*==========================================================*/
/*#####################  Destructor  #######################*/
/*==========================================================*/

template <typename T>
ft::BaseIterator<T>::~BaseIterator() {};

/*==========================================================*/
/*###################  Copy Constructor  ###################*/
/*==========================================================*/

template <typename T>
ft::BaseIterator<T>::BaseIterator(const BaseIterator& rhs)
{
    this->_ptr = rhs._ptr;
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

template <typename T>
ft::BaseIterator<T>& 
ft::BaseIterator<T>::operator=(const ft::BaseIterator<T>& rhs)
{
    if (this == &rhs)
        return (*this);
    this->_ptr = rhs._ptr;
    return (*this);
}

template <typename T>
bool ft::BaseIterator<T>::operator==(const BaseIterator& rhs)
{
    return (this->_ptr == rhs._ptr);
}

template <typename T>
bool ft::BaseIterator<T>::operator!=(const BaseIterator& rhs)
{
    return (this->_ptr != rhs._ptr);
}

template <typename T>
bool ft::BaseIterator<T>::operator<(const BaseIterator& rhs)
{
    return (this->_ptr < rhs._ptr);
}

template <typename T>
bool ft::BaseIterator<T>::operator>(const BaseIterator& rhs)
{
    return (this->_ptr > rhs._ptr);
}

template <typename T>
bool ft::BaseIterator<T>::operator<=(const BaseIterator& rhs)
{
    return (this->_ptr <= rhs._ptr);
}

template <typename T>
bool ft::BaseIterator<T>::operator>=(const BaseIterator& rhs)
{
    return (this->_ptr >= rhs._ptr);
}

/*==========================================================*/
/*###################  Getter functions  ###################*/
/*==========================================================*/

template <typename T>
T* ft::BaseIterator<T>::base() const
{
    return (this->_ptr);
}

//for random access it 
template <typename Iterator>
static typename std::iterator_traits<Iterator>::difference_type 
do_distance(Iterator first, Iterator last, std::random_access_iterator_tag)
{
    return (last - first);
}

template <typename Iterator>
typename std::iterator_traits<Iterator>::difference_type 
distance(Iterator first, Iterator last)
{
    return (do_distance(first, last, typename std::iterator_traits<Iterator>::iterator_category()));
}

};

#endif