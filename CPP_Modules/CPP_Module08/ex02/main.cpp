/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:11:54 by iwoo              #+#    #+#             */
/*   Updated: 2020/09/06 17:11:55 by iwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "\033[1;37;41m"
              << "mstack's top: 17"
              << "\033[0m" << std::endl;
    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "\033[1;37;41m"
              << "mstack's size: 1"
              << "\033[0m" << std::endl;
    std::cout << mstack.size() << std::endl;

    std::cout << "\033[1;37;41m"
              << "mstack push test"
              << "\033[0m" << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    std::cout << "==================print using iterator" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "==================print using const iterator" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "==================print using reverse iterator " << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "==================print using const reverse iterator" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    ++crit;
    --crit;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }

    std::cout << "\033[1;37;41m"
              << "Copy test"
              << "\033[0m" << std::endl;
    MutantStack<int> copy_mstack(mstack);
    copy_mstack.push(42);
    MutantStack<int>::iterator copy_it = copy_mstack.begin();
    MutantStack<int>::iterator copy_ite = copy_mstack.end();
    ++copy_it;
    --copy_it;
    while (copy_it != copy_ite)
    {
        std::cout << *copy_it << std::endl;
        ++copy_it;
    }

    std::cout << "\033[1;37;41m"
              << "Assign test"
              << "\033[0m" << std::endl;
    MutantStack<int> assign_msatck = mstack;
    assign_msatck.push(-42);
    MutantStack<int>::iterator assign_it = assign_msatck.begin();
    MutantStack<int>::iterator assign_ite = assign_msatck.end();
    ++assign_it;
    --assign_it;
    while (assign_it != assign_ite)
    {
        std::cout << *assign_it << std::endl;
        ++assign_it;
    }

    std::cout << "==================original mstack" << std::endl;
    it = mstack.begin();
    ite = mstack.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\033[1;37;41m"
              << "Original stack test"
              << "\033[0m" << std::endl;
    std::stack<int> original_stack(mstack);
    original_stack.push(42);
    original_stack.push(42);
    original_stack.push(42);
    while (original_stack.empty() == false)
    {
        std::cout << original_stack.top() << std::endl;
        original_stack.pop();
    }

    return 0;
}
