#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <iostream>

namespace ft
{

template <typename T>
class BaseIterator
{
public:
    typedef T value_type;

protected:
    value_type *_ptr;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/

    BaseIterator(value_type *ptr) : _ptr(ptr) {};
    virtual ~BaseIterator() {};
    BaseIterator(const BaseIterator& rhs) { this->_ptr = rhs._ptr; };
    BaseIterator& operator=(const BaseIterator& rhs)
    {
        if (this == &rhs)
            return (*this);
        this->_ptr = rhs._ptr;
        return (*this);
    };

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/

    bool operator==(const BaseIterator& rhs) { return (this->_ptr == rhs._ptr); };
    bool operator!=(const BaseIterator& rhs) { return (this->_ptr != rhs._ptr); };
    bool operator<(const BaseIterator& rhs) { return (this->_ptr < rhs._ptr); };
    bool operator>(const BaseIterator& rhs) { return (this->_ptr > rhs._ptr); };
    bool operator<=(const BaseIterator& rhs) { return (this->_ptr <= rhs._ptr); };
    bool operator>=(const BaseIterator& rhs) { return (this->_ptr >= rhs._ptr); };

    /*==========================================================*/
    /*################    Member functions    ##################*/
    /*==========================================================*/
    
    value_type* base() const { return (this->_ptr); };
};

template <typename Iter>
class ReverseBaseIterator
{
private:
    ReverseBaseIterator();

protected:
    Iter _base;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    ReverseBaseIterator(Iter base) : _base(base) {};
    ReverseBaseIterator(const ReverseBaseIterator& rhs) { this->_base= rhs._base; };
    virtual ~ReverseBaseIterator() {};
    ReverseBaseIterator& operator=(const ReverseBaseIterator& rhs)
    {
        if (this == &rhs)
            return (*this);
        this->_ptr = rhs._ptr;
        return (*this);
    };

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/
    
    bool operator==(const ReverseBaseIterator &rhs) const { return (_base == rhs._base); };
    bool operator!=(const ReverseBaseIterator &rhs) const { return (_base != rhs._base); };
    bool operator<(const ReverseBaseIterator &rhs) const { return (_base > rhs._base); };
    bool operator>(const ReverseBaseIterator &rhs) const { return (_base < rhs._base); };
    bool operator<=(const ReverseBaseIterator &rhs) const { return (_base >= rhs._base); };
    bool operator>=(const ReverseBaseIterator &rhs) const { return (_base <= rhs._base); };
    Iter base() const { return (this->_base); };
};

template <typename Iter>
class ReverseIterator : public ReverseBaseIterator<Iter>
{
public:
    typedef ReverseIterator<Iter> reverse_iterator;
    typedef Iter iterator_type;
    typedef typename Iter::iterator_category iterator_category;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/

    ReverseIterator() : ReverseBaseIterator<Iter>(NULL) {};
    explicit ReverseIterator(iterator_type base) : ReverseBaseIterator<Iter>(base) {};
    ReverseIterator(const reverse_iterator& other) : ReverseBaseIterator<Iter>(other._base) {};
    ~ReverseIterator() {};
    reverse_iterator& operator=(const reverse_iterator& other)
    { 
        this->_base = other._base; 
        return (*this); 
    };

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/

    value_type &operator*() const { Iter it(this->_base); --it; return (*it); };
    reverse_iterator operator+(difference_type n) const { return (reverse_iterator(this->_base - n)); };
    reverse_iterator &operator++() { --this->_base; return (*this); };
    reverse_iterator operator++(int) { reverse_iterator it = *this; --this->_base; return (it); };
    reverse_iterator &operator+=(difference_type n) { this->_base -= n; return (*this); };
    reverse_iterator operator-(difference_type n) const { return (reverse_iterator(this->_base + n)); };
    reverse_iterator &operator--() { ++this->_base; return (*this); };
    reverse_iterator operator--(int) { reverse_iterator it = *this; ++this->_base; return (it); };
    reverse_iterator &operator-=(difference_type n) { this->_base += n; return (*this); };
    difference_type operator-(const ReverseBaseIterator<Iter> &rhs) { return (rhs.base() - this->base()); };
    pointer operator->() const { return (&(this->operator*())); };
    reference operator[](difference_type n) const { Iter it(this->_base - n); --it; return (*it); };

    /*==========================================================*/
    /*################    Member functions    ##################*/
    /*==========================================================*/
    
    iterator_type base() const { return (this->base); };
};


template <typename Iter>
class ConstReverseIterator : public ReverseBaseIterator<Iter>
{
public:
    typedef ReverseIterator<Iter> reverse_iterator;
    typedef ConstReverseIterator<Iter> const_reverse_iterator;
    typedef Iter iterator_type;
    typedef typename Iter::iterator_category iterator_category;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/

    ConstReverseIterator() : ReverseBaseIterator<Iter>(nullptr) {};
    explicit ConstReverseIterator(iterator_type base) : ReverseBaseIterator<Iter>(base) {};
    ConstReverseIterator(const const_reverse_iterator& other) : ReverseBaseIterator<Iter>(other._base) {};
    const_reverse_iterator& operator=(const const_reverse_iterator& other)
    { 
        this->_base = other._base; 
        return (*this); 
    };
    ~ConstReverseIterator() {};

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/

    value_type &operator*() const { Iter it(this->_base); --it; return (*it); };
    const_reverse_iterator operator+(difference_type n) const { return (const_reverse_iterator(this->_base - n)); };
    const_reverse_iterator &operator++() { --this->_base; return (*this); };
    const_reverse_iterator operator++(int) { const_reverse_iterator it = *this; --this->_base; return (it); };
    const_reverse_iterator &operator+=(difference_type n) { this->_base -= n; return (*this); };
    const_reverse_iterator operator-(difference_type n) const { return (const_reverse_iterator(this->_base + n)); };
    const_reverse_iterator &operator--() { ++this->_base; return (*this); };
    const_reverse_iterator operator--(int) { const_reverse_iterator it = *this; ++this->_base; return (it); };
    const_reverse_iterator &operator-=(difference_type n) { this->_base += n; return (*this); };
    difference_type operator-(const ReverseBaseIterator<Iter> &rhs) { return (rhs.base() - this->base()); };
    pointer operator->() const { return (&(this->operator*())); };
    reference operator[](difference_type n) const { Iter it(this->_base - n); --it; return (*it); };

    /*==========================================================*/
    /*################    Member functions    ##################*/
    /*==========================================================*/
    
    iterator_type base() const { return (this->base); };
};

template <typename Iter>
ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter>& rev_it)
{
    return (rev_it + n);
}

template <typename Iter>
ConstReverseIterator<Iter> operator+(typename ConstReverseIterator<Iter>::difference_type n, const ConstReverseIterator<Iter>& rev_it)
{
    return (rev_it + n);
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

template <typename T>
struct ListNode 
{
    ListNode(ListNode<T> *prev, ListNode<T> *next, const T& element) : prev(prev), next(next), element(element) {}
    ListNode<T> *prev;
    ListNode<T> *next;
    T element;
};

template <typename T>
class ListBaseIterator
{
private:
    ListBaseIterator();

protected:
    ListNode<T> *_ptr;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    
    ListBaseIterator(ListNode<T> *ptr) : _ptr(ptr) {};
    virtual ~ListBaseIterator() {};
    ListBaseIterator(const ListBaseIterator& rhs) : _ptr(rhs._ptr) {};
    ListBaseIterator& operator=(const ListBaseIterator& rhs)
    { 
        this->_ptr = rhs._ptr; 
        return (*this); 
    };

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/
    
    bool operator==(const ListBaseIterator& rhs) const { return (_ptr == rhs._ptr); };
    bool operator!=(const ListBaseIterator& rhs) const { return (_ptr != rhs._ptr); };
    ListNode<T> *base() const { return (this->_ptr); };
};

template <typename T, typename Compare>
class BST;

template <typename T>
struct BSTNode
{
    T element;
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;
    BSTNode() {};
    BSTNode(T element, BSTNode *parent, BSTNode *left, BSTNode *right)
    : element(element), parent(parent), left(left), right(right) {};
    BSTNode(const BSTNode& o)
    : element(o.element), parent(o.parent), left(o.left), right(o.right) {};
};

template <typename T, typename Compare>
class BSTBaseIterator
{
private:
    BSTBaseIterator();
protected:
    BST<T, Compare> *_tree;
    BSTNode<T> *_node;
public:
    typedef std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::bidirectional_iterator_tag iterator_category;
public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/

    BSTBaseIterator(BST<T, Compare> *tree, BSTNode<T> *node) : _tree(tree), _node(node) {};
    virtual ~BSTBaseIterator() {};
    BSTBaseIterator(const BSTBaseIterator& other) : _tree(other.tree), _node(other.node) {};
    BSTBaseIterator& operator=(const BSTBaseIterator& other)
    { 
        this->_tree = other._tree;
        this->_node = other._node;
        return (*this);
    };

    /*==========================================================*/
    /*######################  Operators  #######################*/
    /*==========================================================*/
    
    bool operator==(const BSTBaseIterator& rhs) const { return (_node == rhs._node); };
    bool operator!=(const BSTBaseIterator& rhs) const { return (_node != rhs._node); };

    /*==========================================================*/
    /*################    Member functions    ##################*/
    /*==========================================================*/
    
    BSTNode<T> *getPointer() const { return (_node); };
    BST<T, Compare> *getTree() const { return (_tree); };
};


};

#endif