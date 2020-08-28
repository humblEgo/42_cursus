/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:24:46 by iwoo              #+#    #+#             */
/*   Updated: 2020/08/28 11:31:21 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void displayValue(T& value)
{
    std::cout<<value<<" ";
}

template <typename T1, typename T2>
void iter(T1* array, T2 length, void (*func)(T1 const&))
{
    if (array == nullptr)
        return ;
    for (T2 i = 0; i < length; i++)
        func(array[i]);
}

int main(void)
{
    std::cout<<"====================================int array"<<std::endl;
    int int_array[10];
    for (int i = 0; i < 10; i++)
        int_array[i] = i;

    for (int i = 0; i < 10; i++)
        std::cout<<int_array[i]<<" ";
    std::cout<<std::endl;
    
    iter(int_array, 10, displayValue);
    std::cout<<std::endl;
    iter(int_array, (size_t)10, displayValue);
    std::cout<<std::endl;

    std::cout<<"====================================double array"<<std::endl;
    double double_array[10];
    for (int i = 0; i < 10; i++)
        double_array[i] = i + 0.1;

    for (int i = 0; i < 10; i++)
        std::cout<<double_array[i]<<" ";
    std::cout<<std::endl;
    
    iter(double_array, 10, displayValue);
    std::cout<<std::endl;
    iter(double_array, (size_t)10, displayValue);
    std::cout<<std::endl;

    std::cout<<"====================================char array"<<std::endl;
    char char_array[11];
    for (int i = 0; i < 10; i++)
        char_array[i] = i + 'a';
    char_array[10] = '\0';

    for (int i = 0; i < 10; i++)
        std::cout<<char_array[i]<<" ";
    std::cout<<std::endl;
    
    iter(char_array, 10, displayValue);
    std::cout<<std::endl;
    iter(char_array, (size_t)10, displayValue);
    std::cout<<std::endl;

    std::cout<<"====================================std::string array"<<std::endl;
    std::string string_array[5];
    string_array[0] = "abc";
    string_array[1] = "abcd";
    string_array[2] = "abcde";
    string_array[3] = "abcdef";
    string_array[4] = "abcdefg";

    for (int i = 0; i < 5; i++)
        std::cout<<string_array[i]<<" ";
    std::cout<<std::endl;
    
    iter(string_array, 5, displayValue);
    std::cout<<std::endl;
    iter(string_array, (size_t)5, displayValue);
    std::cout<<std::endl;



    return (0);
}