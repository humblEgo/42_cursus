#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>  // random_access_iterator_tag가 선언되어있다.
# include <stdexcept>
# include "BaseIterator.hpp"

namespace ft
{
/*==========================================================*/
/*#################    Vector prototype    #################*/
/*==========================================================*/


template <typename T, typename Alloc = std::allocator<T> >
class Vector
{
public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::size_type size_type;

/*==========================================================*/
/*#############   Vector Iterator   ########################*/
/*==========================================================*/


    class Iterator : public BaseIterator<T>
    {
    public:
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::value_type value_type;
        typedef std::random_access_iterator_tag iterator_category;

    public:
        Iterator() : BaseIterator<T>(nullptr) {};
        virtual ~Iterator() {};
        Iterator(const Iterator& iter) : BaseIterator<T>(iter._ptr) {};
        Iterator(pointer ptr) : BaseIterator<T>(ptr) {};

        Iterator& operator=(const Iterator& rhs)
        {
            this->_ptr = rhs._ptr;
            return (*this);
        };
        //TODO: 나머지 연산자들
    };
    //TODO: const iterator, reverse, const_reverse
private:
    allocator_type _allocator;
    pointer _arr;
    size_type _size;
    size_type _cap;

public:
    explict Vector(const allocator_type& alloc = allocator_type());
    explict Vector(size_type n, const value_type& value = value_type(), 
                    const allocator_type& alloc = allocator_type());
    template <typename InputIterator>
    Vector(InputIterator first, InputIterator last, 
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!is_integer<InputIterator>::value, InputIterator>::type isIter = InputIterator());
    virtual ~Vector();
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);

    /*==========================================================*/
    /*#################  Iterator functions  ###################*/
    /*==========================================================*/
    Iterator begin();

    Iterator end();

    /*==========================================================*/
    /*######################  Capacity  ########################*/
    /*==========================================================*/
    
    /*==========================================================*/
    /*####################  Element access  ####################*/
    /*==========================================================*/

    /*==========================================================*/
    /*#######################  Assign  #########################*/
    /*==========================================================*/
    
    /*==========================================================*/
    /*######################  Modifiers  #######################*/
    /*==========================================================*/
    
    void push_back (const value_type& val);
    

    template <typename T, typename A>
    typename Vector<T, A>::Iterator Vector<T, A>::begin()
    {
        return (Iterator(_arr));
    }

    template <typename T, typename A>
    void Vector<T, A>::insert (Iterator position, size_type n, 
                                                    const value_type& val)
    {
        size_type pos = ft::distance(begin(), position);
        size_type newSize = _size + n;
        // if (newSize > _cap)
        //     reserve(newSize);
        if (_size)
        {
            // copy from end down to pos
            size_type times = _size - pos;
            for (size_type last = (_size - 1), i = 0; i < times; --last, i++) 
            {
                _allocator.construct(_arr + last + n, *(_arr + last));
                _allocator.destroy(_arr + last);
            }
            //insert n vals
            for (size_t i = 0; i < n; ++i, ++pos)
            {
                _allocator.construct(_arr + pos, val);
            }
        }
        else
        {
            for (size_type i = 0; i < n; ++i)
                _allocator.construct(_arr + i, val);
        }
        _size += n;
    }
};

}

#endif