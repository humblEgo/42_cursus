#ifndef VECTOR_HPP
#define VECTOR_HPP

#include /* header */

template <typename T>
class Vector
{
private:
    typedef T _value_type;

public:
    Vector();
    virtual ~Vector();
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);
};

#endif