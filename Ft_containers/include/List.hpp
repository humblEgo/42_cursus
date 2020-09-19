#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <stdexcept>
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

    class Iterator : public BaseIterator<T>
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
    /*################  Vector Const Iterator  #################*/
    /*==========================================================*/
    
    class ConstIterator : public ListBaseIterator<T>
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

        ConstIterator() : ListBaseIterator<T>(nullptr) {};
        ConstIterator(const ConstIterator &itr) : ListBaseIterator<T>(itr._ptr) {};
        ConstIterator(const Iterator& itr) : ListBaseIterator<T>(itr.base()) {};
        ConstIterator(ListNode<T> *ptr) : ListBaseIterator<T>(ptr) {};
        virtual ~ConstIterator() {};
        ConstIterator& operator=(const ConstIterator &rhs) { this->_ptr = rhs._ptr; return (*this); };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/

        reference operator*() const { return (this->_ptr->element); };
        pointer operator->() const { return (&(this->_ptr->element); };

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
    List(const List& rhs);
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
    void remove_if(UnaryPredicate p);
    void reverse();
    void unique();
    template <typename BinaryPredicate>
    void unique(BinaryPredicate binary_pred);
    void sort();
    template <typename Compare>
    void sort(Compare comp);

};

//TODO: 전역 함수들

/*==========================================================*/
/*####################  Canonical form   ###################*/
/*==========================================================*/

template <typename T, typename A>
List<T, A>::List(const allocator_type& alloc)
: _allocator(alloc), _size(0)
{
    _li = new ListNode<T>(nullptr, nullptr, value_type());
    //TODO: 왜 이렇게 처리하는지 확인하기.
    _li->prev = _li;
    _li->next = _li;
}

};

#endif