/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:12:52 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:12:53 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T &min(T &a, T &b)
{
    if (a < b)
        return (a);
    return (b);
}

template <>
std::string &min<std::string>(std::string &s1, std::string &s2)
{
    if (strcmp(s1.c_str(), s2.c_str()) < 0)
        return (s1);
    return (s2);
}

template <typename T>
T &max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
}

template <>
std::string &max<std::string>(std::string &s1, std::string &s2)
{
    if (strcmp(s1.c_str(), s2.c_str()) > 0)
        return (s1);
    return (s2);
}

int main(void)
{
    char c1 = 'a';
    char c2 = 'b';
    int i1 = 1;
    int i2 = 2;
    float f1 = 1.1f;
    float f2 = 2.2f;
    double d1 = 1.1;
    double d2 = 2.2;
    std::string s1 = "wow11111";
    std::string s2 = "wow22222";

    std::cout << "=========================================my example" << std::endl;
    std::cout << "Before swap" << std::endl;
    std::cout << "c1: " << c1 << "\t| "
              << "c2 : " << c2 << std::endl;
    std::cout << "i1: " << i1 << "\t| "
              << "i2 : " << i2 << std::endl;
    std::cout << "f1: " << f1 << "\t| "
              << "f2 : " << f2 << std::endl;
    std::cout << "d1: " << d1 << "\t| "
              << "d2 : " << d2 << std::endl;
    std::cout << "s1: " << s1 << "\t| "
              << "s2 : " << s2 << std::endl;
    ::swap(c1, c2);
    ::swap(i1, i2);
    ::swap(f1, f2);
    ::swap(d1, d2);
    ::swap(s1, s2);
    std::cout << "After swap" << std::endl;
    std::cout << "c1: " << c1 << "\t| "
              << "c2 : " << c2 << std::endl;
    std::cout << "i1: " << i1 << "\t| "
              << "i2 : " << i2 << std::endl;
    std::cout << "f1: " << f1 << "\t| "
              << "f2 : " << f2 << std::endl;
    std::cout << "d1: " << d1 << "\t| "
              << "d2 : " << d2 << std::endl;
    std::cout << "s1: " << s1 << "\t| "
              << "s2 : " << s2 << std::endl;

    std::cout << "Reset swap" << std::endl;
    ::swap(c1, c2);
    ::swap(i1, i2);
    ::swap(f1, f2);
    ::swap(d1, d2);
    ::swap(s1, s2);
    std::cout << "=========================================" << std::endl;
    std::cout << "min( c1, c2 ) = " << min(c1, c2) << std::endl;
    std::cout << "min( i1, i2 ) = " << min(i1, i2) << std::endl;
    std::cout << "min( f1, f2 ) = " << min(f1, f2) << std::endl;
    std::cout << "min( d1, d2 ) = " << min(d1, d2) << std::endl;
    std::cout << "min( s1, s2 ) = " << min(s1, s2) << std::endl;
    std::cout << "min( s2, s1 ) = " << min(s2, s1) << std::endl;

    std::cout << "=========================================" << std::endl;
    std::cout << "max( c1, c2 ) = " << max(c1, c2) << std::endl;
    std::cout << "max( i1, i2 ) = " << max(i1, i2) << std::endl;
    std::cout << "max( f1, f2 ) = " << max(f1, f2) << std::endl;
    std::cout << "max( d1, d2 ) = " << max(d1, d2) << std::endl;
    std::cout << "max( s1, s2 ) = " << max(s1, s2) << std::endl;
    std::cout << "max( s2, s1 ) = " << max(s2, s1) << std::endl;

    std::cout << "=========================================subject example" << std::endl;
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

    return (0);
}