#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

template <typename T1, typename T2>
struct pair
{
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() : first(), second() {};
    ~pair() {}
    pair(const T1& x, const T2& y) : first(x), second(y) {}
    pair(const pair& other) : first(other.first), second(other.second) {}
    template <typename U1, typename U2>
    pair(const pair<U1, U2>& other) : first(other.first), second(other.second) {};
    pair &operator=(const pair& rhs)
    {
        first = rhs.first;
        second = rhs.second;
        return (*this);
    }
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(const T1 t1, const T2 t2)
{
    return (pair<T1, T2>(t1, t2));
}

template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
    return (lhs.first < rhs.first && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
    return (!(lhs == rhs));
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
    return (!(lhs > rhs));
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{
    return (!(lhs < rhs));
}

};

#endif