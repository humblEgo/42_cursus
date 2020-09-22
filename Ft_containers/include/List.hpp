#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "Iterators.hpp"
# include "Utils.hpp"

namespace ft
{
/*==========================================================*/
/*#################     List prototype     #################*/
/*==========================================================*/

template <typename T, typename A = std::allocator<T> >
class List 
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
    /*###################    List Iterator    ##################*/
    /*==========================================================*/

    class Iterator : public ListBaseIterator<T>
    {
    public:
        typedef typename A::reference reference;
        typedef typename A::pointer pointer;
        typedef typename A::difference_type difference_type;
        typedef typename A::value_type value_type;
        typedef std::bidirectional_iterator_tag iterator_category;

    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/
        
        Iterator() : ListBaseIterator<T>(nullptr) {};
        virtual ~Iterator() {};
        Iterator(const Iterator& rhs) : ListBaseIterator<T>(rhs._ptr) {};
        Iterator(ListNode<T> *ptr) : ListBaseIterator<T>(ptr) {};
        Iterator& operator=(const Iterator& rhs) { this->_ptr = rhs._ptr; return (*this); };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/
        
        reference operator*() const { return (this->_ptr->element); };
        pointer operator->() const { return (&(this->_ptr->element)); };

        Iterator& operator++() { this->_ptr = this->_ptr->next; return (*this); };
        Iterator operator++(int) { Iterator itr(this->_ptr); this->_ptr = this->_ptr->next; return (itr); };
        Iterator& operator--() { this->_ptr = this->_ptr->prev; return (*this); };
        Iterator operator--(int) { Iterator itr(this->_ptr); this->_ptr = this->_ptr->prev; return (itr); };
    };

    /*==========================================================*/
    /*#################  List Const Iterator  ##################*/
    /*==========================================================*/
    
    class ConstIterator : public ListBaseIterator<T>
    {
    public:
        typedef T& reference;
        typedef T* pointer;
        typedef typename A::difference_type difference_type;
        typedef typename A::value_type value_type;
        typedef std::bidirectional_iterator_tag iterator_category;

    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/

        ConstIterator() : ListBaseIterator<T>(NULL) {};
        ConstIterator(const ConstIterator &other) : ListBaseIterator<T>(other._ptr) {};
        ConstIterator(const Iterator& other) : ListBaseIterator<T>(other.base()) {};
        ConstIterator(ListNode<T> *ptr) : ListBaseIterator<T>(ptr) {};
        virtual ~ConstIterator() {};
        ConstIterator& operator=(const ConstIterator &rhs) { this->_ptr = rhs._ptr; return (*this); };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/

        reference operator*() const { return (this->_ptr->element); };
        pointer operator->() const { return (&(this->_ptr->element)); };

        ConstIterator& operator++() { this->_ptr = this->_ptr->next; return (*this); };
        ConstIterator operator++(int) { ConstIterator itr(this->_ptr); this->_ptr = this->_ptr->_next; return (itr); };
        ConstIterator& operator--() { this->_ptr = this->_ptr->prev; return (*this); };
        ConstIterator operator--(int) { ConstIterator itr(this->_ptr); this->_ptr = this->_ptr->prev; return (itr); };
    };

typedef ReverseIterator<Iterator> reverse_iterator;
typedef ConstReverseIterator<Iterator> const_reverse_iterator;

private:
    allocator_type _allocator;
    ListNode<T> *_li;
    size_type _size;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    
    explicit List(const allocator_type& alloc = allocator_type());
    explicit List(size_type n, const value_type& value = value_type(), 
                                const allocator_type& alloc = allocator_type());
    template <class InputIterator>
    List(InputIterator first, InputIterator last, 
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
    virtual ~List();
    List(const List& other);
    List &operator=(const List& rhs);

    /*==========================================================*/
    /*#################  Iterator functions  ###################*/
    /*==========================================================*/

    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;

    /*==========================================================*/
    /*######################  Capacity  ########################*/
    /*==========================================================*/

    size_type size() const;
    size_type max_size() const;
    bool empty() const;
    
    /*==========================================================*/
    /*####################  Element access  ####################*/
    /*==========================================================*/

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    /*==========================================================*/
    /*#######################  Assign  #########################*/
    /*==========================================================*/
    
    template <typename InputIterator>
    void assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
    void assign (size_type n, const value_type& val);

    /*==========================================================*/
    /*######################  Modifiers  #######################*/
    /*==========================================================*/

    void push_front(const value_type& val);
    void push_back(const value_type& val);
    void pop_front();
    void pop_back();
    Iterator insert(Iterator position, const value_type& val);
    void insert(Iterator position, size_type n, const value_type& val);
    template <typename InputIterator>
    void insert(Iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator()); 
    Iterator erase(Iterator position);
    Iterator erase(Iterator first, Iterator last);
    void resize(size_type n, value_type val = value_type());
    void swap(List& other);
    void clear();

    /*==========================================================*/
    /*####################  Operations  ########################*/
    /*==========================================================*/
    

    void merge(List& other);
    template <typename Compare>
    void merge(List& other, Compare comp);
    void splice(Iterator position, List& other);
    void splice(Iterator position, List& other, Iterator it);
    void splice(Iterator position, List& other, Iterator first, Iterator last);
    void remove(const value_type& val);
    template <typename UnaryPredicate>
    void remove_if(UnaryPredicate pred);

    void reverse();
    void unique();
    template <typename BinaryPredicate>
    void unique(BinaryPredicate binary_pred);
    void sort();
    template <typename Compare>
    void sort(Compare comp);

};

/*==========================================================*/
/*####################  Canonical form   ###################*/
/*==========================================================*/

template <typename T, typename A>
List<T, A>::List(const allocator_type& alloc)
: _allocator(alloc), _size(0)
{
    _li = new ListNode<T>(nullptr, nullptr, value_type());
    _li->prev = _li;
    _li->next = _li;
}

template <typename T, typename A>
List<T, A>::List(size_type n, const value_type& val, const allocator_type& alloc)
: _allocator(alloc), _size(0)
{
    _li = new ListNode<T>(nullptr, nullptr, value_type());
    _li->prev = _li;
    _li->next = _li;
    insert(begin(), n, val);
}

template <typename T, typename A>
List<T, A>::List(const List<T, A>& other)
: _allocator(other._allocator), _size(0)
{
    _li = new ListNode<T>(nullptr, nullptr, value_type());
    _li->prev = _li;
    _li->next = _li;
    insert(begin(), other.begin(), other.end());
}

template <typename T, typename A>
List<T, A>& List<T, A>::operator=(const List<T, A>& rhs)
{
    clear();
    insert(begin(), rhs.begin(), rhs.end());
    return (*this);
}

template <typename T, typename A>
List<T, A>::~List()
{
    clear();
    delete _li;  // 만약 delete[] 하면, SampleClass 처럼 객체를 받았을 때 문제 생김.
}

/*==========================================================*/
/*#################  Iterator functions  ###################*/
/*==========================================================*/

template <typename T, typename A>
typename List<T, A>::Iterator List<T, A>::begin()
{
    return (Iterator(_li->next));
}

template <typename T, typename A>
typename List<T, A>::ConstIterator List<T, A>::begin() const
{
    return (ConstIterator(_li->next));
}

template <typename T, typename A>
typename List<T, A>::Iterator List<T, A>::end()
{
    return (Iterator(_li));
}

template <typename T, typename A>
typename List<T, A>::ConstIterator List<T, A>::end() const
{
    return (ConstIterator(_li));
}

template <typename T, typename A>
typename List<T, A>::reverse_iterator List<T, A>::rbegin()
{
    return (reverse_iterator(end()));
}

template <typename T, typename A>
typename List<T, A>::const_reverse_iterator List<T, A>::rbegin() const
{
    return (const_reverse_iterator(end()));
}

template <typename T, typename A>
typename List<T, A>::reverse_iterator List<T, A>::rend()
{
    return (reverse_iterator(begin()));
}

template <typename T, typename A>
typename List<T, A>::const_reverse_iterator List<T, A>::rend() const
{
    return (const_reverse_iterator(begin()));
}

/*==========================================================*/
/*######################  Capacity  ########################*/
/*==========================================================*/

template <typename T, typename A>
typename List<T, A>::size_type List<T, A>::size() const
{
    return (_size);
}

template <typename T, typename A>
typename List<T, A>::size_type List<T, A>::max_size() const
{
    // size_type 이 unsigned이니까 음수 -1을 캐스팅하면 size_type 자료형의 최대값이 나온다. 여기에 node의 사이즈로 나눈 후 size_type으로 캐스팅하면 깔끔하게 max_size가 나온다!
    return (static_cast<size_type>(-1 / sizeof(ListNode<T>)));
}

template <typename T, typename A>
bool List<T, A>::empty() const
{
    return (_size == 0);
}

/*==========================================================*/
/*####################  Element access  ####################*/
/*==========================================================*/

template <typename T, typename A>
typename List<T, A>::reference List<T, A>::front()
{
    return (_li->next->element);
}

template <typename T, typename A>
typename List<T, A>::const_reference List<T, A>::front() const
{
    return (_li->next->element);
}

template <typename T, typename A>
typename List<T, A>::reference List<T, A>::back()
{
    return (_li->prev->element);
}
template <typename T, typename A>
typename List<T, A>::const_reference List<T, A>::back() const
{
    return (_li->prev->element);
}

/*==========================================================*/
/*#######################  Assign  #########################*/
/*==========================================================*/

template <typename T, typename A>
template <typename InputIterator>
void List<T, A>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) 
{
    (void)isIter;
    clear();
    insert(begin(), first, last);
}

template <typename T, typename A>
void List<T, A>::assign(size_type n, const value_type& val)
{
    clear();
    insert(begin(), n, val);
}

/*==========================================================*/
/*######################  Modifiers  #######################*/
/*==========================================================*/

template <typename T, typename A>
void List<T, A>::push_front(const value_type& val)
{
    insert(begin(), val);
}

template <typename T, typename A>
void List<T, A>::push_back(const value_type& val)
{
    insert(end(), val);
}

template <typename T, typename A>
void List<T, A>::pop_front()
{
    erase(begin());
}

template <typename T, typename A>
void List<T, A>::pop_back()
{
    erase(--(end()));
}

template <typename T, typename A>
typename List<T, A>::Iterator List<T, A>::insert(Iterator position, const value_type& val)
{
    insert(position, 1, val);
    return (--position);
}

template <typename T, typename A>
void List<T, A>::insert(Iterator position, size_type n, const value_type& val)
{
    ListNode<T> *start;
    ListNode<T> *cur;
    ListNode<T> *next;

    if (n > max_size() || n < 0)
        return ;
    
    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start = new ListNode<T>(nullptr, nullptr, val);
            cur = start;
            next = cur;
        }
        else
        {
            next = new ListNode<T>(cur, nullptr, val);
            cur->next = next;
            cur = cur->next;
        }
    }

    if (_size == 0)
    {
        _li->next = start;
        start->prev = _li;
        next->next = _li;
        _li->prev = next;
    }
    else
    {
        ListNode<T> *pos_node = position.base();
        ListNode<T> *prev = position.base()->prev;
        prev->next = start;
        start->prev = prev;
        next->next = pos_node;
        pos_node->prev = next;
    }
    _size += n;
}

template <typename T, typename A>
template <typename InputIterator>
void List<T, A>::insert(Iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter)
{
    (void)isIter;
    ListNode<T> *start;
    ListNode<T> *cur;
    ListNode<T> *next;
    size_type nb = 0;

    for (InputIterator it = first; it != last; ++it)
    {
        if (nb == 0)
        {
            start = new ListNode<T>(nullptr, nullptr, *it);
            cur = start;
            next = cur;
        }
        else
        {
            next = new ListNode<T>(cur, nullptr, *it);
            cur->next = next;
            cur = cur->next;
        }
        nb++;
    }
    if (!nb)
        return ;
    if (_size == 0)
    {
        _li->next = start;
        start->prev = _li;
        next->next = _li;
        _li->prev = next;
    }
    else
    {
        ListNode<T> *pos = position.base();
        ListNode<T> *prev = pos->prev;
        prev->next = start;
        start->prev = prev;
        next->next = pos;
        pos->prev = next;
    }
    _size += nb;
}

template <typename T, typename A>
typename List<T, A>::Iterator List<T, A>::erase(typename List<T, A>::Iterator position)
{
    Iterator it(position);
    return (erase(position, ++it));
}

template <typename T, typename A>
typename List<T, A>::Iterator 
List<T, A>::erase(typename List<T, A>::Iterator first, typename List<T, A>::Iterator last)
{
    ListNode<T> *begin_node = first.base();
    ListNode<T> *end_node = last.base();
    ListNode<T> *prev_node = begin_node->prev;
    size_type nb = 0;

    while (begin_node != end_node)
    {
        ListNode<T> *tmp = begin_node->next;
        if (begin_node != _li)
        {
            delete begin_node;
            nb++;
        }
        begin_node = tmp;
    }
    _size -= nb;
    prev_node->next = end_node;
    end_node->prev = prev_node;
    return (Iterator(end_node));
}

template <typename T, typename A>
void List<T, A>::resize(size_type n, value_type val)
{
    if (n < size())
    {
        Iterator it = begin();
        for (size_t i = 0; i < n; i++)
            ++it;
        erase(it, end());
    }
    else if (n > size())
        insert(end(), n - size(), val);
}

template <typename T, typename A>
void List<T, A>::swap(List& other)
{
    std::swap(_allocator, other._allocator);
    std::swap(_size, other._size);
    std::swap(_li, other._li);
}

template <typename T, typename A>
void List<T, A>::clear()
{ 
    erase(begin(), end());
}

/*==========================================================*/
/*####################  Operations  ########################*/
/*==========================================================*/

// 이미 정렬된 두 리스트를 오름차순으로 결합. 정렬되어있지 않으면 merge() 함수는 실패하며 오류가 발생.
template <typename T, typename A>
void List<T, A>::merge(List& other)
{
    ListNode<T> *original_cur = begin().base();
    ListNode<T> *other_cur = other.begin().base();
    ListNode<T> *other_next;
    ListNode<T> *original_prev;

    while (other_cur != other._li)
    {
        if (original_cur == end().base() || other_cur->element < original_cur->element)
        {
            other_next = other_cur->next;
            original_prev = original_cur->prev;

            original_prev->next = other_cur;
            other_cur->prev = original_prev;

            other_cur->next = original_cur;
            original_cur->prev = other_cur;

            other_cur = other_next;
        }
        else
            original_cur = original_cur->next;
    }
    _size += other._size;
    other._size = 0;
    // remove elements of 'other', without destroying them.
    ListNode<T> *other_list = other._li;
    other_list->next = other_list;
    other_list->prev = other_list;
}

template <typename T, typename A>
template <typename Compare>
void List<T, A>::merge(List& other, Compare comp)
{
    ListNode<T> *original_cur = begin().base();
    ListNode<T> *other_cur = other.begin().base();
    ListNode<T> *other_next;
    ListNode<T> *original_prev;

    while (other_cur != other._li)
    {
        if (original_cur == end().base() || comp(other_cur->element, original_cur->element))
        {
            other_next = other_cur->next;
            original_prev = original_cur->prev;

            original_prev->next = other_cur;
            other_cur->prev = original_prev;

            other_cur->next = original_cur;
            original_cur->prev = other_cur;

            other_cur = other_next;
        }
        else
            original_cur = original_cur->next;
    }
    _size += other._size;
    other._size = 0;
    // remove elements of 'other', without destroying them.
    ListNode<T> *other_list = other._li;
    other_list->next = other_list;
    other_list->prev = other_list;
}

template <typename T, typename A>
void List<T, A>::splice(Iterator position, List& other)
{
    insert(position, other.begin(), other.end());
    other.clear();
}

template <typename T, typename A>
void List<T, A>::splice(Iterator position, List& other, Iterator it)
{
    insert(position, *it);
    other.erase(it);
}

template <typename T, typename A>
void List<T, A>::splice(Iterator position, List& other, Iterator first, Iterator last)
{
    insert(position, first, last);
    other.erase(first, last);
}


template <typename T, typename A>
void List<T, A>::remove(const value_type& val)
{
    for (Iterator it = begin(); it != end();)
    {
        if (*it == val)
            it = erase(it);
        else
            ++it;
    }
}

template <typename T, typename A>
template <typename UnaryPredicate>
void List<T, A>::remove_if(UnaryPredicate pred)
{
    for (Iterator it = begin(); it != end();)
    {
        if (pred(*it))
            it = erase(it);
        else
            ++it;
    }
}

template <typename T, typename A>
void List<T, A>::reverse()
{
    ListNode<T> *cur = _li->next;
    ListNode<T> *next;

    while (cur != _li)
    {
        next = cur->next;
        cur->next = cur->prev;
        cur->prev = next;

        cur = next;
    }
    next = cur->next;
    cur->next = cur->prev;
    cur->prev = next;
}

template <typename T, typename A>
void List<T, A>::unique()
{
    for (Iterator it = ++(begin()); it != end();)
    {
        Iterator tmp = it;
        --tmp;
        if (*tmp == *it)
            it = erase(it);
        else
            ++it;
    }
}

template <typename T, typename A>
template <typename BinaryPredicate>
void List<T, A>::unique(BinaryPredicate binary_pred)
{
    for (Iterator it = (++(begin())); it != end();)
    {
        Iterator tmp = it;
        --tmp;
        if (binary_pred(*tmp, *it))
            it = erase(it);
        else
            ++it;
    }
}

template <typename T, typename A>
void List<T, A>::sort()
{
    ListNode<T> *a = _li->next;
    ListNode<T> *b = a->next;
    ListNode<T> *prev;
    ListNode<T> *next;
    while (b != _li)
    {
        if (b->element < a->element)
        {
            prev = a->prev;
            next = b->next;

            prev->next = b;
            b->prev = prev;

            b->next = a;
            a->prev = b;

            a->next = next;
            next->prev = a;
            // reset a and b to begin 
            a = _li->next;
            b = a->next;
        }
        else
        {
            a = a->next;
            b = b->next;
        }
    }
}

template <typename T, typename A>
template <typename Compare>
void List<T, A>::sort(Compare comp)
{
    ListNode<T> *a = _li->next;
    ListNode<T> *b = a->next;
    ListNode<T> *prev;
    ListNode<T> *next;
    while (b != _li)
    {
        if (comp(b->element, a->element))
        {
            prev = a->prev;
            next = b->next;

            prev->next = b;
            b->prev = prev;

            b->next = a;
            a->prev = b;

            a->next = next;
            next->prev = a;
            // reset a and b to begin 
            a = _li->next;
            b = a->next;
        }
        else
        {
            a = a->next;
            b = b->next;
        }
    }
}

/*==========================================================*/
/*######################  Operators  #######################*/
/*==========================================================*/

template <typename T, typename A>
bool operator==(const List<T, A>& lhs, const List<T, A>& rhs)
{
    if (lhs.size() != rhs.size())
        return (false);
    typename List<T, A>::const_iterator lit = lhs.begin();
    typename List<T, A>::const_iterator rit = rhs.begin();
    for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
    {
        if (*lit != *rit)
            return (false);
    }
    return (true);
}

template <typename T, typename A>
bool operator!=(const List<T, A>& lhs, const List<T, A>& rhs)
{
    return (!(lhs == rhs));
}

template <typename T, typename A>
bool operator<(const List<T, A>& lhs, const List<T, A>& rhs)
{
    typename List<T, A>::const_iterator lit = lhs.begin();
    typename List<T, A>::const_iterator rit = rhs.begin();

    if (lhs.size() == rhs.size())
        return (false);
    for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
    {
        if (*lit != *rit)
            return (*lit < *rit);
    }
    return (lhs.size() < rhs.size());
}

template <typename T, typename A>
bool operator>(const List<T, A>& lhs, const List<T, A>& rhs)
{
    typename List<T, A>::const_iterator lit = lhs.begin();
    typename List<T, A>::const_iterator rit = rhs.begin();

    if (lhs.size() == rhs.size())
        return (false);
    for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
    {
        if (*lit != *rit)
            return (*lit > *rit);
    }
    return (lhs.size() > rhs.size());
}

template <typename T, typename A>
bool operator<=(const List<T, A>& lhs, const List<T, A>& rhs)
{
    return (!(lhs > rhs));
}

template <typename T, typename A>
bool operator>=(const List<T, A>& lhs, const List<T, A>& rhs)
{
    return (!(lhs < rhs));
}

template <typename T, typename A>
void swap(List<T, A>& lhs, List<T, A>& rhs)
{
    lhs.swap(rhs);
}

/*==========================================================*/
/*####################  Custom for test  ###################*/
/*==========================================================*/

template <typename T, typename A>
std::ostream& operator<<(std::ostream& out, const List<T, A>& li)
{
    std::cout<<"============================================="<<std::endl;
    out<<"size    : "<<li.size()<<"\n";
    std::cout<<"member: [ ";
    for (typename List<T, A>::Iterator it = li.begin(); it != li.end(); ++it)
        std::cout<<*it<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"=============================================";
    return (out);
}

template <>
std::ostream& operator<<(std::ostream& out, const List<SampleClass>& li)
{
    std::cout<<"============================================="<<std::endl;
    out<<"size  : "<<li.size()<<"\n";
    std::cout<<"member: [ ";
    for (List<SampleClass>::ConstIterator it = li.begin(); it != li.end(); ++it)
        std::cout<<(*it).getName()<<" ";
    std::cout<<"]"<<std::endl;
    std::cout<<"=============================================";
    return (out);
}


};

#endif