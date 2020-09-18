#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include "BaseIterator.hpp"
# include "Utils.hpp"

namespace ft
{
/*==========================================================*/
/*#################    Vector prototype    #################*/
/*==========================================================*/

template <typename T, typename A = std::allocator<T> >
class Vector
{
public:
    typedef T value_type;
    typedef A allocator_type;
    typedef typename A::reference reference;
    typedef typename A::const_reference const_reference;
    typedef typename A::pointer pointer;
    typedef typename A::const_pointer const_pointer;
    typedef typename A::difference_type difference_type;
    typedef typename A::size_type size_type;

    /*==========================================================*/
    /*###################   Vector Iterator   ##################*/
    /*==========================================================*/

    class Iterator : public BaseIterator<T>
    {
    public:
        typedef typename A::reference reference;
        typedef typename A::pointer pointer;
        typedef typename A::difference_type difference_type;
        typedef typename A::value_type value_type;
        typedef std::random_access_iterator_tag iterator_category;

    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/
        
        Iterator() : BaseIterator<T>(nullptr) {};
        
        //TODO: const iter, pointer
        virtual ~Iterator() {};
        Iterator(const Iterator& iter) : BaseIterator<T>(iter._ptr) {};
        Iterator(pointer ptr) : BaseIterator<T>(ptr) {};

        Iterator& operator=(const Iterator& rhs)
        {
            this->_ptr = rhs._ptr;
            return (*this);
        };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/
        
        reference operator*() const
        {
            return (*this->_ptr);
        };

        pointer operator->() const 
        {
            return (this->_ptr);
        };

        reference operator[](difference_type n) const
        {
            return (*(this->_ptr + n));
        };

        Iterator& operator++()
        {
            this->_ptr++;
            return (*this);
        };

        Iterator operator++(int)
        {
            Iterator itr = *this;
            this->_ptr++;
            return (itr);
        };

        Iterator& operator--()
        {
            this->_ptr--;
            return (*this);
        };

        Iterator operator--(int)
        {
            Iterator itr = *this;
            this->_ptr--;
            return (itr);
        };

        Iterator operator+=(difference_type n)
        {
            this->_ptr += n;
            return (*this);
        };

        Iterator operator-=(difference_type n)
        {
            this->_ptr -= n;
            return (*this);
        };

        Iterator operator+(difference_type n) const
        {
            return (Iterator(this->_ptr + n));
        };

        Iterator operator-(difference_type n) const
        {
            return (Iterator(this->_ptr - n));
        };

        difference_type operator-(const BaseIterator<T>& rhs)
        {
            return (this->_ptr - rhs.base());
        };
    };

    /*==========================================================*/
    /*################  Vector Const Iterator  #################*/
    /*==========================================================*/
    
    class ConstIterator : public BaseIterator<T>
    {
    public:
        typedef T& reference;
        typedef T* pointer;
        typedef typename A::difference_type difference_type;
        typedef typename A::value_type value_type;
        typedef std::random_access_iterator_tag iterator_category;

    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/

        ConstIterator() : BaseIterator<T>(nullptr) {};
        ConstIterator(const ConstIterator &itr) : BaseIterator<T>(itr._ptr) {};
        ConstIterator(const Iterator& itr) : BaseIterator<T>(itr.base()) {};
        ConstIterator(pointer ptr) : BaseIterator<T>(ptr) {};
        virtual ~ConstIterator() {};

        ConstIterator& operator=(const ConstIterator &rhs)
        {
            this->_ptr = rhs._ptr;
            return (*this);
        };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/

        reference operator*() const
        {
            return (*this->_ptr);
        };

        pointer operator->() const 
        {
            return (this->_ptr);
        };

        reference operator[](difference_type n) const
        {
            return (*(this->_ptr + n));
        };

        ConstIterator& operator++()
        {
            this->_ptr++;
            return (*this);
        };

        ConstIterator operator++(int)
        {
            ConstIterator itr = *this;
            this->_ptr++;
            return (itr);
        };

        ConstIterator& operator--()
        {
            this->_ptr--;
            return (*this);
        };

        ConstIterator operator--(int)
        {
            ConstIterator itr = *this;
            this->_ptr--;
            return (itr);
        };

        ConstIterator operator+=(difference_type n)
        {
            this->_ptr += n;
            return (*this);
        };

        ConstIterator operator-=(difference_type n)
        {
            this->_ptr -= n;
            return (*this);
        };

        ConstIterator operator+(difference_type n) const
        {
            return (ConstIterator(this->_ptr + n));
        };

        ConstIterator operator-(difference_type n) const
        {
            return (ConstIterator(this->_ptr - n));
        };

        difference_type operator-(const BaseIterator<T>& rhs)
        {
            return (this->_ptr - rhs.base());
        };
    };

    //TODO: reverse, const_reverse
private:
    allocator_type _allocator;
    pointer _arr;
    size_type _size;
    size_type _cap;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    
    explicit Vector(const allocator_type& alloc = allocator_type());
    explicit Vector(size_type n, const value_type& value = value_type(), 
                                const allocator_type& alloc = allocator_type());
    // template <class InputIterator>
    // Vector(InputIterator first, InputIterator last, 
    //                 const allocator_type& alloc = allocator_type(),
    //                 typename ft::enable_if<!is_integer<InputIterator>::value, InputIterator>::type isIter = InputIterator());
    virtual ~Vector();
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);

    /*==========================================================*/
    /*#################  Iterator functions  ###################*/
    /*==========================================================*/
    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;
    //TODO: reverse itr

    /*==========================================================*/
    /*######################  Capacity  ########################*/
    /*==========================================================*/

    size_type size() const;
    size_type max_size() const;
    void resize(size_type n, value_type val = value_type());
    void reserve(size_type n);
    bool empty() const;
    size_type capacity() const;
    
    /*==========================================================*/
    /*####################  Element access  ####################*/
    /*==========================================================*/

    /*==========================================================*/
    /*#######################  Assign  #########################*/
    /*==========================================================*/
    
    /*==========================================================*/
    /*######################  Modifiers  #######################*/
    /*==========================================================*/
    Iterator insert(Iterator position, const value_type& val);
    void insert(Iterator position, size_type n, const value_type& val);
    Iterator erase(Iterator position);
    Iterator erase(Iterator first, Iterator last);
    void swap(Vector& other);
    void clear();

};

/*==========================================================*/
/*####################  Custom for test  ###################*/
/*==========================================================*/

template <typename T, typename A>
std::ostream& operator<<(std::ostream& out, const Vector<T, A>& vec)
{
    std::cout<<std::endl;
    out<<"size    : "<<vec.size()<<"\n";
    out<<"capacity: "<<vec.capacity()<<"\n";
    std::cout<<"member: [";
    for (typename Vector<T, A>::ConstIterator it = vec.begin(); it != vec.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"]";
    return (out);
}

/*==========================================================*/
/*####################  Canonical Form  ####################*/
/*==========================================================*/

template <typename T, typename A>
Vector<T, A>::Vector(const allocator_type& alloc) 
: _allocator(alloc), _arr(nullptr), _size(0), _cap(0)
{
}

template <typename T, typename A>
Vector<T, A>::Vector(size_type n, const value_type& val, const allocator_type& alloc) 
: _allocator(alloc), _size(n), _cap(n)
{
    _arr = _allocator.allocate(n);
    for (size_type i = 0; i < n; i++)
    {
        _allocator.construct(_arr + i, val);
    }
}

template <typename T, typename A>
Vector<T, A>::~Vector() 
{
    if (_cap)
    {
        for (size_type i = 0; i < _size; i++)
            _allocator.destroy(_arr + i);
        _allocator.deallocate(_arr, _cap);
    }
}

/*==========================================================*/
/*#################  Iterator functions  ###################*/
/*==========================================================*/

template <typename T, typename A>
typename Vector<T, A>::Iterator Vector<T, A>::begin()
{
    return (Iterator(_arr));
}

template <typename T, typename A>
typename Vector<T, A>::ConstIterator Vector<T, A>::begin() const
{
    return (ConstIterator(_arr));
}

template <typename T, typename A>
typename Vector<T, A>::Iterator Vector<T, A>::end()
{
    return (Iterator(_arr + _size));
}

template <typename T, typename A>
typename Vector<T, A>::ConstIterator Vector<T, A>::end() const
{
    return (ConstIterator(_arr + _size));
}

/*==========================================================*/
/*######################  Capacity  ########################*/
/*==========================================================*/

template <typename T, typename A>
typename Vector<T, A>::size_type Vector<T, A>::size() const
{
    return (_size);
}

template <typename T, typename A>
typename Vector<T, A>::size_type Vector<T, A>::max_size() const
{
    // (2^nativePointerBitWidth)/sizeof(dataType) - 1
    return (static_cast<size_type>(-1 / sizeof(T)));
}

// reserve는 최소한으로 실행되어야한다. 그런데 만약 cap = 10이고 size가 10인 상태에서 push를 하면, 무조건 재할당이 이뤄지는 구조로 구현되어있으므로, n을 더 더해줘야겠따. std::vector에서는 2배만큼 reserve하게 되어있다.
template <typename T, typename A>
void Vector<T, A>::reserve(size_type n)
{
    if (n > max_size())
        throw std::length_error("length error");
    else if (n > _cap)
    {
        T *new_arr = _allocator.allocate(n);
        for (size_t i = 0; i < _size; i++)
        {
            _allocator.construct(&new_arr[i], _arr[i]);
            _allocator.destroy(&_arr[i]);
        }
        _allocator.deallocate(_arr, _cap);
        _arr = new_arr;
        _cap = n;
    }
}

template <typename T, typename A>
bool Vector<T, A>::empty() const
{
    return (_size == 0);
}

template <typename T, typename A>
typename Vector<T, A>::size_type Vector<T, A>::capacity() const
{
    return (_cap);
}

template <typename T, typename A>
void Vector<T, A>::resize(size_type n, value_type val) 
{
    if (n < size())
    {
        erase(begin() + n, end());
    }
    else if (n > size())
    {
        insert(end(), n - size(), val);
    }
}

/*==========================================================*/
/*######################  Modifiers  #######################*/
/*==========================================================*/

template <typename T, typename A>
typename Vector<T, A>::Iterator 
Vector<T, A>::insert(Iterator position, const value_type& val)
{
    insert(position, 1, val);
    return (position);
}

template <typename T, typename A>
void Vector<T, A>::insert(Iterator position, size_type n, const value_type& val)
{
    size_type pos = ft::distance(begin(), position);
    size_type new_size = _size + n;
    if (new_size > _cap)
    {
        if (new_size < _cap * 2)
            reserve(_cap * 2);
        else
            reserve(new_size);
    }
    if (_size)
    {
        size_type times = _size - pos;
        for (size_type last = (_size - 1), i = 0; i < times; --last, i++)
        {
            _allocator.construct(_arr + last + n, *(_arr + last));
            _allocator.destroy(_arr + last);
        }
        for (size_type i = 0; i < n; ++i, ++pos)
            _allocator.construct(_arr + pos, val);
    }
    else
    {
        for (size_type i = 0; i < n; ++i)
            _allocator.construct(_arr + i, val);
    }
    _size += n;
}

template <typename T, typename A>
typename Vector<T, A>::Iterator Vector<T, A>::erase(Iterator position)
{
    return (erase(position, position + 1));    
}

template <typename T, typename A>
typename Vector<T, A>::Iterator Vector<T, A>::erase(Iterator first, Iterator last)
{
    Iterator itr;
    size_type times = ft::distance(first, last);

    for (itr = first; itr != last; ++itr)
        _allocator.destroy(&*itr);
    
    if (last < end())
    {
        for (itr = first; last != end(); ++itr, ++last)
        {
            _allocator.construct(&*itr, *last);
            _allocator.destroy(&*last);
        }
    }
    _size -= times;
    return (first);
}

};

#endif