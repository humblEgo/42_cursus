#ifndef UTILS_HPP
# define UTILS_HPP

# include <typeinfo>

namespace ft
{

/*==========================================================*/
/*####################   enable_if   #######################*/
/*==========================================================*/

template <bool Condition, typename T = void>
struct enable_if
{
};

template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};

/*==========================================================*/
/*#####################  is_itegral  #######################*/
/*==========================================================*/

template <typename T>
struct is_integer
{
    static const bool value = false;
};

template <>
struct is_integer<bool>
{
    static const bool value = true;
};

template <>
struct is_integer<char>
{
    static const bool value = true;
};

template <>
struct is_integer<wchar_t>
{
    static const bool value = true;
};


template <>
struct is_integer<signed char>
{
    static const bool value = true;
};


template <>
struct is_integer<short int>
{
    static const bool value = true;
};


//TODO ??
template <>
struct is_integer<int>
{
    static const bool value = true;
};


template <>
struct is_integer<long int>
{
    static const bool value = true;
};


template <>
struct is_integer<long long int>
{
    static const bool value = true;
};


template <>
struct is_integer<unsigned char>
{
    static const bool value = true;
};


template <>
struct is_integer<unsigned short int>
{
    static const bool value = true;
};


template <>
struct is_integer<unsigned int>
{
    static const bool value = true;
};


template <>
struct is_integer<unsigned long int>
{
    static const bool value = true;
};


template <>
struct is_integer<unsigned long long int>
{
    static const bool value = true;
};

// double과 float는 이터레이터와 혼동할 가능성이 없으므로 처리해줄 필요가 없다.

};

#endif