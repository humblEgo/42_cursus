/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:13:00 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:13:00 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *randomClassGenerate()
{
    Base *ret;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> pick(0, 2);
    int random_num = pick(gen);
    if (random_num == 0)
        ret = new A;
    else if (random_num == 1)
        ret = new B;
    else
        ret = new C;
    return (ret);
}

void identify_from_pointer(Base *base)
{
    A *a = dynamic_cast<A *>(base);
    B *b = dynamic_cast<B *>(base);
    C *c = dynamic_cast<C *>(base);
    if (a != nullptr)
        std::cout << "A" << std::endl;
    else if (b != nullptr)
        std::cout << "B" << std::endl;
    else if (c != nullptr)
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base &base)
{
    try
    {
        A a = dynamic_cast<A &>(base);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
    try
    {
        B b = dynamic_cast<B &>(base);
        std::cout << "B" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
    try
    {
        C c = dynamic_cast<C &>(base);
        std::cout << "C" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
}

int main(void)
{
    Base *base = nullptr;

    base = randomClassGenerate();
    if (base == nullptr)
    {
        std::cout << "radomClassGenerate failed!" << std::endl;
        return (1);
    }
    identify_from_pointer(base);
    identify_from_reference(*base);
    delete base;

    return (0);
}