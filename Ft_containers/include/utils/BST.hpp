#ifndef BST_HPP
# define BST_HPP

# include "Iterators.hpp"
# include "Pair.hpp"
# include <iostream>

namespace ft
{

//여기서 T는 pair<key, mapped_value>가 들어온다.
template <typename T, typename Compare>
class BST
{

public:
    typedef T value_type;
    typedef BSTNode<T> Node;
    typedef size_t size_type;
    typedef BST<T, Compare> Tree;

    /*==========================================================*/
    /*####################  BST iterator  ######################*/
    /*==========================================================*/
    
    class Iterator : public BSTBaseIterator<T, Compare>
    {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef BSTNode<T> Node;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/
        
        Iterator() : BSTBaseIterator<T, Compare>(nullptr, nullptr) {};
        Iterator(BST *tree) : BSTBaseIterator<T, Compare>(tree, nullptr) {};
        Iterator(BST *tree, Node *node) : BSTBaseIterator<T, Compare>(tree, node) {};
        Iterator(const Iterator& other) : BSTBaseIterator<T, Compare>(other) {};
        virtual ~Iterator() {};
        Iterator& operator=(const Iterator& other)
        {
            this->_node = other._node;
            this->_tree = other._tree;
            return (*this);
        };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/

        // iterator가 지금 노드보다 한단계 높은 값을 가지고 있는 노드를 가리키게해야한다. BST의 특징을 바탕으로 케이스나누어 생각하면 쉽다.
        // 참고로 _tree, _node는 BSTBaseItearator에 protected로 아래처럼 선언되어있다. 
        // protected:
        //     BST<T, Compare> *_tree;
        //     BSTNode<T> *_node;
        Iterator& operator++()
        {
            Node *root = this->_tree->getRoot();
            Node *tmp;

            if (!(root))
            {
                this->_node = this->_tree->getInit();
                return (*this);
            }
            // 노드가 없거나 노드가 init을 가리키고 있다면(가장 마지막 노드), 그 다음 노드로 첫번째 노드를 가리키게하여 반환!
            if (!(this->_node) || this->_node == this->_tree->getInit())
            {
                tmp = root;
                while (tmp->left)
                    tmp = tmp->left;
                this->_node = tmp;
                return (*this);
            }
            // 만약 노드의 오른쪽에 노드가 있다면? 오른쪽 노드를 기준으로 가장 왼쪽 노드를 가리키게하여 반환! 왼쪽 노드가 있다면 말이지.
            if (this->_node->right)
            {
                this->_node = this->_node->right;
                while (this->_node->left)
                    this->_node = this->_node->left;
                return (*this);
            }

            // 오른쪽 노드가 없는 케이스에는 자신이 lchild인지, rchild인지에 따라 달리 처리된다.
            // lchild일 경우: 바로 위 parent가 반환되어야할 노드
            // rchild일 경우: 바로 위 parent의 parent가 반환되어야할 노드. 참고로 rchild면서 가장 마지막 노드인 경우는 (this->_node == this->_tree->getInit()) 조건에 걸려서 처리된 상태이다.
            tmp = this->_node->parent;
            while (tmp && tmp->right == this->_node)
            {
                this->_node = tmp;
                tmp = this->_node->parent;
            }
            if (!tmp)
                this->_node = this->_tree->getInit();
            else
                this->_node = tmp;
            return (*this);
        };

        Iterator operator++(int)
        {
            Iterator it(*this);
            this->operator++();
            return (it);
        };

        Iterator& operator--()
        {
            Node *root = this->_tree->getRoot();
            Node *tmp;

            if (!(root))
            {
                this->_node = this->_tree->getInit();
                return (*this);
            }
            if (!(this->_node) || this->_node == this->_tree->getInit())
            {
                tmp = root;
                while (tmp->right)
                    tmp = tmp->right;
                this->_node = tmp;
                return (*this);
            }
            if (this->_node->left)
            {
                this->_node = this->_node->left;
                while (this->_node->right)
                    this->_node = this->_node->right;
                return (*this);
            }

            tmp = this->_node->parent;
            while (tmp && tmp->left == this->_node)
            {
                this->_node = tmp;
                tmp = this->_node.parent;
            }
            if (!tmp)
                this->_node = this->_tree->getInit();
            else
                this->_node = tmp;
            
            return (*this);
        };

        Iterator operator--(int)
        {
            Iterator it(*this);
            operator--();
            return (it);
        }

        reference operator*() const { return (this->_node->element); };
        pointer operator->() const { return (&(this->_node->element)); };
    };

    /*==========================================================*/
    /*#################  BST const iterator  ###################*/
    /*==========================================================*/
    
    class ConstIterator : public BSTBaseIterator<T, Compare>
    {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef BSTNode<T> Node;
        typedef std::ptrdiff_t difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

    public:
        /*==========================================================*/
        /*####################  Canonical form   ###################*/
        /*==========================================================*/
        
        ConstIterator() : BSTBaseIterator<T, Compare>(nullptr, nullptr) {};
        ConstIterator(BST *tree) : BSTBaseIterator<T, Compare>(tree, nullptr) {};
        ConstIterator(BST *tree, Node *node) : BSTBaseIterator<T, Compare>(tree, node) {};
        ConstIterator(const ConstIterator& other) : BSTBaseIterator<T, Compare>(other) {};
        virtual ~ConstIterator() {};
        ConstIterator& operator=(const ConstIterator& other)
        {
            this->_node = other._node;
            this->_trethis->e = other._trethis->e;
            return (*this);
        };

        /*==========================================================*/
        /*######################  Operators  #######################*/
        /*==========================================================*/

        ConstIterator& operator++()
        {
            Node *root = this->_tree->getRoot();
            Node *tmp;

            if (!(root))
            {
                this->_node = this->_tree->getInit();
                return (*this);
            }

            if (!(this->_node) || this->_node == this->_tree->getInit())
            {
                tmp = root;
                while (tmp->left)
                    tmp = tmp->left;
                this->_node = tmp;
                return (*this);
            }

            if (this->_node->right)
            {
                this->_node = this->_node->right;
                while (this->_node->left)
                    this->_node = this->_node->left;
                return (*this);
            }

            tmp = this->_node->parent;
            while (tmp && tmp->right == this->_node)
            {
                this->_node = tmp;
                tmp = this->_node->parent;
            }
            if (!tmp)
                this->_node = this->_tree->getInit();
            else
                this->_node = tmp;
            return (*this);
        };

        ConstIterator operator++(int)
        {
            ConstIterator it(*this);
            this->operator++();
            return (it);
        };

        ConstIterator& operator--()
        {
            Node *root = this->_tree->getRoot();
            Node *tmp;

            if (!(root))
            {
                this->_node = this->_tree->getInit();
                return (*this);
            }
            if (!(this->_node) || this->_node == this->_tree->getInit())
            {
                tmp = root;
                while (tmp->right)
                    tmp = tmp->right;
                this->_node = tmp;
                return (*this);
            }
            if (this->_node->left)
            {
                this->_node = this->_node->left;
                while (this->_node->right)
                    this->_node = this->_node->right;
                return (*this);
            }

            tmp = this->_node->parent;
            while (tmp && tmp->left == this->_node)
            {
                this->_node = tmp;
                tmp = this->_node.parent;
            }
            if (!tmp)
                this->_node = this->_tree->getInit();
            else
                this->_node = tmp;
            
            return (*this);
        };

        ConstIterator operator--(int)
        {
            ConstIterator it(*this);
            operator--();
            return (it);
        }

        reference operator*() const { return (this->_node->element); };
        pointer operator->() const { return (&(this->_node->element)); };
    };

    typedef ReverseIterator<Iterator> ReverseIterator;
    typedef ConstReverseIterator<Iterator> ConstReverseIterator;


private:
    Compare _cmp;
    Node *_root;
    Node *_init;
    size_t _size;
    BST() {};

    /*==========================================================*/
    /*###########    Private Member functions    ###############*/
    /*==========================================================*/

    void deep_free(Node *root);
    // Node n을 기준으로 재귀적으로 tree에 속하는 노드들을 모두 깊은복사한다. 
    // parent는 복사한 노드들의 parent에 해당.
    Node *deep_copy(Node *parent, Node *n);

public:
    /*==========================================================*/
    /*####################  Canonical form   ###################*/
    /*==========================================================*/
    
    BST(Compare cmp) : _cmp(cmp), _root(nullptr), _size(0)
    {
        // BSTNode(T element, BSTNode *parent, BSTNode *left, BSTNode *right)
        _init = new Node(value_type(), nullptr, nullptr, nullptr);
    };

    BST(const BST& other) : _cmp(other._cmp), _size(other._size)
    {
        _root = deep_copy(nullptr, other._root);
        _init = new Node(value_type(), nullptr, nullptr, nullptr);
    };

    BST& operator=(const BST& other)
    {
        deep_free(_root);
        _root = deep_copy(nullptr, other._root);
        _cmp = other._cmp;
        _size = other._size;
        return (*this);
    };

    virtual ~BST() { deep_free(_root); delete (_init); };

    /*==========================================================*/
    /*############    Public Member functions    ###############*/
    /*==========================================================*/
    
    Node *getRoot();
    Node *getInit();
    size_type getSize() const;
    pair<Iterator, bool> insert(Iterator position, const value_type& val);
    bool map_erase(const value_type& val);
};

/*==========================================================*/
/*###########    Private Member functions    ###############*/
/*==========================================================*/

template <typename T, typename Compare>
void BST<T, Compare>::deep_free(Node *root)
{
    if (!root)
        return ;
    deep_free(root->left);
    deep_free(root->right);
    delete root;
}

template <typename T, typename Compare>
typename BST<T, Compare>::Node *BST<T, Compare>::deep_copy(Node *parent, Node *node)
{
    if (!node)
        return (nullptr);
    Node *copy = new Node(node->element, parent, nullptr, nullptr);
    copy->left = deep_copy(copy, node->left);
    copy->right = deep_copy(copy, node->right);
    return (copy);
}

/*==========================================================*/
/*############    Public Member functions    ###############*/
/*==========================================================*/

template <typename T, typename Compare>
typename BST<T, Compare>::Node *BST<T, Compare>::getRoot() { return (this->_root); }

template <typename T, typename Compare>
typename BST<T, Compare>::Node *BST<T, Compare>::getInit() { return (this->_init); }

template <typename T, typename Compare>
typename BST<T, Compare>::size_type BST<T, Compare>::getSize() const
{ 
    return (this->_size); 
}

template <typename T, typename Compare>
pair<typename BST<T, Compare>::Iterator, bool> BST<T, Compare>::insert(Iterator position, const value_type& val)
{
    Node *pos = position.getPointer();
    Node *newNode;

    if (!(_root)) // 루트가 없다? 트리가 없다!
    {
        _root = new Node(val, nullptr, nullptr, nullptr);
        _size++;
        return (make_pair(Iterator(this, _root), true));
    }
    while (true)
    {
        // 여기서 val과 pos->element는 pair<key, mapped_value>이다.
        // pos->element의 key와 val의 key가 동일하게 존재한다면, 인자로 들어온 이터레이터와 같은 노드를 가리키는 이터레이터를 생성시켜서 false 값과 pair를 만들어 리턴한다. 
        if (pos->element.first == val.first)
            return (make_pair(Iterator(this, pos), false));
        
        if (_cmp(val, pos->element))
        {
            // 만약 val이 pos->element보다 작다면, position의 왼쪽 끝에 val을 담은 리프노드를 생성한다. 
            if (pos->left)
                pos = pos->left;
            else
            {
                newNode = new Node(val, pos, nullptr, nullptr);
                pos->left = newNode;
                break;
            }
        }
        else
        {
            // 만약 val이 pos->element보다 크거나 같다면, position의 오른쪽 끝에 val을 담은 리프노드를 생성한다.
            if (pos->right)
                pos = pos->right;
            else
            {
                newNode = new Node(val, pos, nullptr, nullptr);
                pos->right = newNode;
                break;
            }
        }
    }
    _size++;
    // 이제 노드삽입을 성공했으면 새로 만들어진 노드를 가리키는 Iterator와 true 값을 pair로 만들어서 리턴!
    return (make_pair(Iterator(this, newNode), true));
}

template <typename T, typename Compare>
bool BST<T, Compare>::map_erase(const value_type& val)
{
    Node *del = nullptr;
    Node *del_parent = nullptr;
    Node **del_ptr = nullptr;
    Node *cdd = nullptr;
    Node *cdd_parent = nullptr;
    Node *traverse = nullptr;

    if (!(_root))
        return false;
    // 삭제할 노드를 탐색한다.
    traverse = _root;
    while (traverse)
    {
        if (val.first == traverse->element.first)
        {
            del = traverse;
            break;
        }
        if (_cmp(val, traverse->element))
            traverse = traverse->left;
        else
            traverse = traverse->right;
    }
    // 만약 삭제할 pair를 가진 노드를 찾지 못했다면(없으면), false를 리턴!
    if (!del)
        return (false);
    
    // 자, 이제 삭제 전에 BST를 정리할 수 있도록 적절한 조치를 취해줘야한다. BST에서 가장 복잡한 편이다. 삭제할 노드의 자식존재여부에 따라 케이스를 나눠서 효율적으로 최소한의 노드만 움직여서 계속 정돈된 상태가 되도록 해보자.
    del_parent = del->parent;
    if (!(del->right) && !(del->left)) //case1. 삭제하려는 노드가 자식이 없을 때(리프노드)
        cdd = nullptr;
    else if ((del->left) && !(del->right)) //case2. 삭제하려는 노드가 자식노드를 하나만 가지고 있을 때.
        cdd = del->left;
    else if (!(del->left) && (del->right))
        cdd = del->right;
    else //case3. 삭제하려는 노드가 자식노드를 두개 가지고 있을 때. lchild의 오른쪽 끝 리프노드나 rchild의 왼쪽 끝 노드를 del 자리에 치환시키면 된다. 나는 후자로 구현해보았다.
    {
        // 우선 rchild의 왼쪽 끝 노드를 찾아내려가자.
        cdd_parent = del;
        cdd = del->right;
        while (cdd->left)
        {
            cdd_parent = cdd;
            cdd = cdd->left;
        }
        // 그런데 이 노드에 rchild가 있을 수 있다. 이 경우엔 cdd의 rchild를 cdd_parent의 lchild로 붙여버리자.
        if (cdd_parent->left == cdd)
        {
            cdd_parent->left = cdd->right;
            if (cdd->right)
                cdd->right->parent = cdd_parent;
            cdd->left = del->left;
            del->left->parent = cdd;
        }
        // 오른쪽 서브트리의 가장 작은 값이 그냥 del->right였을 경우.
        else
        {
            // cdd와 del->left를 연결시켜준다.
            cdd->left = del->left;
            del->left->parent = cdd;
        }
    }
    // 이제 del_parent와 cdd를 연결시켜준다.
    if (del_parent)
    {
        if (del_parent->left == del)
            del_ptr = &(del_parent->left);
        else 
            del_ptr = &(del_parent->right);
        *del_ptr = cdd;
    }
    else
    {
        // root만 parent가 존재하지 않는다. del_parent가 없다면? del이 루트라는 소리. root에 cdd를 대신 넣어주자.
        _root = cdd;
    }

    if (cdd) // 만약 del이 리프노드가 아니라면(cdd가 None이 아니라면) cdd_parent도 설정해주자.
        cdd->parent = del_parent;

    // 이제 삭제!
    delete del;
    _size--;
    return (true);
}

};

#endif