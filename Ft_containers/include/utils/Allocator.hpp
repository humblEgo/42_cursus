#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include /* header */

template <typename T>
class Allocator
{
private:
    typedef T _value_type;
    typedef _value_type* _pointer;
    typedef const _value_type* _const_pointer;
    typedef const _value_type& _reference;
    typedef const _value_type& _const_reference;
    typedef std::size_t _size_type;
    typedef std::ptrdiff_t _difference_type;

public:
    // convert an allocator<T> to allocator<U>
    template <typename U>
    struct rebind
    {
        typedef Allocator<U> other;
    };

public:
    Allocator() throw();
    virtual ~Allocator();
    template <typename U>
    Allocator(const Allocator &other) throw();
    Allocator &operator=(const Allocator &other) throw();

    pointer address(_reference r);
    const_pointer address(_const_reference);

    pointer allocate(size_type cnt, typename std::allocator<void>::const_pointer = 0);
    void deallocate(pointer p, size_type);

    size_type max_size() cosnt;

    void construct(pointer p, const T& t);
    void destroy(pointer p);

    bool operator==(Allocator const&);
    bool operator!=(Allocator const& a);
};


/*==========================================================*/
/*####################  definitions  #######################*/
/*==========================================================*/





#endif