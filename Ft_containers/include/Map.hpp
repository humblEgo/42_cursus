#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "Pair.hpp"
# include "BST.hpp"
# include "Iterators.hpp"
# include "Utils.hpp"
# include "Vector.hpp"

namespace ft
{
/*==========================================================*/
/*#################     Map prototype     #################*/
/*==========================================================*/

template <typename T>
struct less : std::binary_fucntion<T, T, bool>
{
    bool operator()(const T& x, const T& y) cosnt { return (x < y); }
};

template <typename Key, typename T, typename Compare = ft::less<Key>, typename A = std::allocator<pair<const Key, T> > >
class Map
{
public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
      // `()` 연산자를 오버로딩한 것을 특기하자.
    class value_compare
    {
    public:
        typedef bool result_type;
        typedef pair<const Key, T> first_argument_type;
        typedef pair<const Key, T> second_argument_type;

    private:
        Comapre _cmp;
        value_compare() {};
    
    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/

        value_compare(const Compare& c) : _cmp(c) {}:
        ~value_compare() {};
        value_compare(const value_compare& other) : _cmp(other._cmp) {};
        value_compare& operator=(const value_compare& rhs)
        {
            _cmp = rhs._cmp;
            return (*this);
        }

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/
        
        bool operator()(const pair<const Key, T>& x, const pair<const Key, T>& y) const { return (_cmp(x.first, y.first)); };
    };
    typedef A allocator_type;
    typedef typename A::reference reference;
    typedef typename A::const_reference const_reference;
    typedef typename A::pointer pointer;
    typedef typename A::const_pointer const_pointer;
    typedef std::pirdiff_t difference_type;
    typedef size_t size_type;

    typedef typename BST<value_type, value_compare>::Iterator Iterator;
    typedef typename BST<value_type, value_compare>::ConstIterator ConstIterator;
    typedef typename BST<value_type, value_compare>::ReverseIterator reverse_iterator;
    typedef typename BST<value_type, value_compare>::ConstReverseIterator const_reverse_iterator;

    typedef BSTNode<pair<const Key, T> > Node;

private:
    BST<pair<const Key, T>, value_compare> _tree;
    allocator_type _alloc;

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    
    explicit Map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    template <typename InputIterator>
    Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    virtual ~Map();
    Map(const Map& other);
    Map& operator=(const Map& rhs);

    /*==========================================================*/
    /*################  Iterators funcitons  ###################*/
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
    /*####################    Capacity   #######################*/
    /*==========================================================*/

    bool empty() const;
    size_type size() const;
    size_type max_size() const;

    /*==========================================================*/
    /*###################  Element access  #####################*/
    /*==========================================================*/

    mapped_type& operator[](const key_type& key);
    
    /*==========================================================*/
    /*####################   Modifiers   #######################*/
    /*==========================================================*/

    pair<Iterator, bool> insert(const value_type& val);
    Iterator insert(Iterator position, const value_type& val);
    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last);
    void erase(Iterator position);
    size_type erase(const key_type& key);
    void erase(Iterator first, Iterator last);
    void swap(map& other);
    void clear();

    /*==========================================================*/
    /*####################   Observers   #######################*/
    /*==========================================================*/

    key_compare key_comp() const;
    value_compare value_comp() const;
    
    /*==========================================================*/
    /*####################   Operations   ######################*/
    /*==========================================================*/

    Iterator find(const key_type& key);
    ConstIterator find(const key_type& key) const;
    size_type count(const key_type& key);
    Iterator lower_bound(const key_type& key);
    ConstIterator lower_bound(const key_type& key) const;
    Iterator upper_bound(const key_type& key);
    ConstIterator upper_bound(const key_type& key) const;
    pair<ConstIterator, ConstIterator> equal_range(const key_type& key) const;
    pair<Iterator, Iterator> equal_range(const key_type& key);
};

/*==========================================================*/
/*####################  Canonical form   ###################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::Map(const key_compare& comp, const allocator_type& alloc)
: _tree(value_compare(comp)), _alloc(alloc)
{
}

template <typename Key, typename T, typename Compare, typename A>
template <typename InputIterator>
Map<Key, T, Compare, A>::Map(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc)
: _tree(value_compare(comp)), _alloc(alloc)
{
    for (InputIterator it = first; it != last; ++it)
        _tree.insert(Iterator(&_tree, _tree.getRoot()), *it);
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::Map(const Map& other)
: _tree(othre._tree), _alloc(other._alloc)
{
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::~Map() {}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>& Map<Key, T, Compare, A>::operator=(const Map& rhs)
{
    _tree = rhs._tree;
    _alloc = rhs._alloc;
    return (*this);
}

/*==========================================================*/
/*################  Iterators funcitons  ###################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::Iterator Map<Key, T, Compare, A>::begin()
{
    Node *n = _tree.getRoot();
    if (!n)
        return (Iterator(&_tree, _tree.getInit()));
    while (n && n->left)
        n = n->left;
    return (Iterator(&_tree, n));
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::ConstIterator Map<Key, T, Compare, A>::begin() const
{
    Node *n = _tree.getRoot();
    if (!n)
        return (ConstIterator(&_tree, _tree.getInit()));
    while (n && n->left)
        n = n->left;
    return (ConstIterator(&_tree, n));
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::Iterator Map<Key, T, Compare, A>::end()
{
    return (Iterator(&_tree, _tree.getInit())); 
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::ConstIterator Map<Key, T, Compare, A>::end() const
{
    return (ConstIterator(&_tree, _tree.getInit())); 
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::reverse_iterator Map<Key, T, Compare, A>::rbegin()
{
    return (reverse_iterator(end()));
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::const_reverse_iterator Map<Key, T, Compare, A>::rbegin() const
{
    return (const_reverse_iterator(end()));
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::reverse_iterator Map<Key, T, Compare, A>::rend()
{
    return (reverse_iterator(begin()));
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::const_reverse_iterator Map<Key, T, Compare, A>::rend() const
{
    return (const_reverse_iterator(begin()));
}

/*==========================================================*/
/*####################    Capacity   #######################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
bool Map<Key, T, Compare, A>::empty() const { return (_tree.getSize() == 0); }

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::size_type Map<Key, T, Compare, A>::size() const
{
    return (_tree.getSize());
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::size_type Map<Key, T, Compare, A>::max_size() const
{
    return (std::min((size_type)std::numeric_limits<difference_type>::max(), std::numeric_limits<size_type>::max() / sizeof(Node)));
}

/*==========================================================*/
/*###################  Element access  #####################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::mapped_type& Map<Key, T, Compare, A>::operator[](const key_type& key)
{
    Iterator it = find(key);
    if (it == end())
        it = _tree.insert(Iterator(&_tree, _tree.getRoot()), make_pair(key, mapped_type())).first;
    return (it->second);
}

/*==========================================================*/
/*####################   Modifiers   #######################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
pair<typename Map<Key, T, Compare, A>::Iterator, bool> Map<Key, T, Compare, A>::insert(const value_type& val)
{
    return (_tree.insert(Iterator(&_tree, _tree.getRoot()), val));
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::Iterator Map<Key, T, Compare, A>::insert(Iterator position, const value_type& val)
{
    key_compare cmp = key_comp();
    if (cmp(position->first, val.first) && upper_bound(position->first) == upper_bound(val.first))
        return (_tree.insert(positiion, val).first);
    return (_tree.insert(Iterator(&_tree, _tree.getRoot()), val).first);
}

template <typename Key, typename T, typename Compare, typename A>
template <typename InputIterator>
void Map<Key, T, Compare, A>::insert(InputIterator first, InputIterator last)
{
    for (InputIterator it = first; it != last; it++)
        insert(*it);
}

template <typename Key, typename T, typename Compare, typename A>
void erase(Iterator position)
{
    _tree.map_erase(*poisition);
}

template <typename Key, typename T, typename Compare, typename A>
Map<Key, T, Compare, A>::size_type Map<Key, T, Compare, A>::erase(const key_type& key)
{
    return (_tree.map_erase(make_pair(key, mapped_type())));
}

template <typename Key, typename T, typename Compare, typename A>
void Map<Key, T, Compare, A>::erase(Iterator first, Iterator last)
{
    while (first != lsat)
        _tree.map_erase(*first++);
}

template <typename Key, typename T, typename Compare, typename A>
void Map<Key, T, Compare, A>::swap(map& other)
{
    std::swap(_alloc, other._alloc);
    std::swap(_tree, other._tree);
}

template <typename Key, typename T, typename Compare, typename A>
void Map<Key, T, Compare, A>::clear()
{
    erase(begin(), end());
}

/*==========================================================*/
/*####################   Observers   #######################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::key_compare Map<Key, T, Compare, A>::key_comp() const
{
    return (key_compare());
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::value_compare Map<Key, T, Compare, A>::value_comp() const
{
    return (value_compare(key_compare()));
}

/*==========================================================*/
/*####################   Operations   ######################*/
/*==========================================================*/

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::Iterator Map<Key, T, Compare, A>::find(const key_type& key)
{
    Node *tmp = _tree.getRoot();
    key_compare cmp = key_comp();
    while (tmp)
    {
        if (tmp->element.first == key)
            return (Iterator(&_tree, tmp));
        if (cmp(key, tmp->element.first))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return (end());
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::ConstIterator Map<Key, T, Compare, A>::find(const key_type& key) const
{
    Node *tmp = _tree.getRoot();
    key_compare cmp = key_comp();
    while (tmp)
    {
        if (tmp->element.first == key)
            return (Iterator(&_tree, tmp));
        if (cmp(key, tmp->element.first))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return (ConstIterator(end()));
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::size_type Map<Key, T, Compare, A>::count(const key_type& key)
{
    Node *tmp = _tree.getRoot();
    key_compare cmp = key_comp();
    while (tmp)
    {
        if (tmp->element.first == key)
            return (1);
        if (cmp(key, tmp->element.first))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return (0);
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::Iterator Map<Key, T, Compare, A>::lower_bound(const key_type& key)
{
    Node *tmp = _tree.getRoot();
    Node *ptmp = nullptr;
    key_compare cmp = key_comp();
    if (tmp)
    {
        while (tmp)
        {
            ptmp = tmp;
            if (tmp->element.first == key)
                return (Iterator(&_tree, tmp));
            if (cmp(key, tmp->element.first))
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        while (ptmp)
        {
            if (!(cmp(key, ptmp->element.first)))
                ptmp = ptmp->parent;
            else
                return (Iterator(&_tree, ptmp));
        }
    }
    return (end());
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::ConstIterator Map<Key, T, Compare, A>::lower_bound(const key_type& key) const
{
    Node *tmp = _tree.getRoot();
    Node *ptmp = nullptr;
    key_compare cmp = key_comp();
    if (tmp)
    {
        while (tmp)
        {
            ptmp = tmp;
            if (tmp->element.first == key)
                return (Iterator(&_tree, tmp));
            if (cmp(key, tmp->element.first))
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        while (ptmp)
        {
            if (!(cmp(key, ptmp->element.first)))
                ptmp = ptmp->parent;
            else
                return (Iterator(&_tree, ptmp));
        }
    }
    return (ConstIterator(end()));
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::Iterator Map<Key, T, Compare, A>::upper_bound(const key_type& key)
{
    Node *tmp = _tree.getRoot();
    Node *ptmp = nullptr;
    key_compare cmp = key_comp();
    if (tmp)
    {
        while (tmp)
        {
            ptmp = tmp;
            if (cmp(key, tmp->element.first))
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        while (ptmp)
        {
            if (!(cmp(key, ptmp->element.first)))
                ptmp = ptmp->parent;
            else
                return (Iterator(&_tree, ptmp));
        }
    }
    return (end());
}

template <typename Key, typename T, typename Compare, typename A>
typename Map<Key, T, Compare, A>::ConstIterator Map<Key, T, Compare, A>::upper_bound(const key_type& key) const
{
    Node *tmp = _tree.getRoot();
    Node *ptmp = nullptr;
    key_compare cmp = key_comp();
    if (tmp)
    {
        while (tmp)
        {
            ptmp = tmp;
            if (cmp(key, tmp->element.first))
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        while (ptmp)
        {
            if (!(cmp(key, ptmp->element.first)))
                ptmp = ptmp->parent;
            else
                return (ConstIterator(&_tree, ptmp));
        }
    }
    return (ConstIterator(end()));
}

template <typename Key, typename T, typename Compare, typename A>
pair<typename Map<Key, T, Compare, A>::ConstIterator, typename Map<Key, T, Compare, A>::ConstIterator> equal_range(const key_type& key) const
{
    return (make_pair(lower_bound(key), upper_bound(key)));
}

template <typename Key, typename T, typename Compare, typename A>
pair<typename Map<Key, T, Compare, A>::Iterator, typename Map<Key, T, Compare, A>::Iterator> Map<Key, T, Compare, A>::equal_range(const key_type& key)
{
    return (make_pair(lower_bound(key), upper_bound(key)));
}

};

#endif