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
    std::string int_type = "i";

    if (typeid(T).name() == int_type)
        static const bool value = false;
    else
        static const bool value = true;
};

};

#endif